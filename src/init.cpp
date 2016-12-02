#include <dlfcn.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"

// Helper function to get address of a symbol from a shared library.
template <typename T> inline T GetNextFunction(const char* filename, const char* symbol) {
	return reinterpret_cast<T>(dlsym(dlopen(filename, RTLD_NOW), symbol));
}

// Overwrite the SDL_GL_SwapWindow symbol.
extern "C" void SDL_GL_SwapWindow(SDL_Window* window) {
	// Get the original 'SDL_GL_SwapWindow' symbol from 'libSDL2-2.0.so.0'.
	static void (*oSDL_GL_SwapWindow) (SDL_Window*) = GetNextFunction<void(*)(SDL_Window*)>("./bin/linux64/libSDL2-2.0.so.0", "SDL_GL_SwapWindow");
	
	// Store OpenGL contexts.
	static SDL_GLContext original_context = SDL_GL_GetCurrentContext();
	static SDL_GLContext user_context = NULL;
	
	// Perform first-time initialization.
	if (!user_context) {
		// Create a new context for our rendering.
		user_context = SDL_GL_CreateContext(window);
		ImGui_ImplSdl_Init(window);
	}

	// Switch to our context.
	SDL_GL_MakeCurrent(window, user_context);

	// Perform UI rendering.
	ImGui_ImplSdl_NewFrame(window);

	ImGui::ShowTestWindow();
	ImGui::Render();

	// Swap back to the game context.
	SDL_GL_MakeCurrent(window, original_context);

	// Call the original function.
	oSDL_GL_SwapWindow(window);
}