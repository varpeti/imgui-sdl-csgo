#include <dlfcn.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"

// Overwrite the SDL_GL_SwapWindow symbol.
extern "C" void SDL_GL_SwapWindow(SDL_Window* window) {
	// Get the original 'SDL_GL_SwapWindow' symbol from 'libSDL2-2.0.so.0'.
	static void (*oSDL_GL_SwapWindow) (SDL_Window*) = reinterpret_cast<void(*)(SDL_Window*)>(dlsym(RTLD_NEXT, "SDL_GL_SwapWindow"));
	
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

	ImGui::Text("Hello, world!");
	ImGui::Render();

	// Swap back to the game context.
	SDL_GL_MakeCurrent(window, original_context);

	// Call the original function.
	oSDL_GL_SwapWindow(window);
}