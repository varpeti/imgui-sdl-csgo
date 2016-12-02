![imgui demo in Counter-Strike: Global Offensive on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/demo-ui-example.png)

# imgui-sdl-csgo

Implements the [imgui](https://github.com/ocornut/imgui) graphical user interface by hijacking the `SDL_GL_SwapWindow` symbol. This repository specifically targets Counter-Strike: Global Offensive but should work in other games that use SDL with minor changes.

Special thanks to @SirBarclay who provided a [working example](https://github.com/SirBarclay/meh/blob/master/test.cpp) of OpenGL drawing based on [my initial hooking](https://www.unknowncheats.me/forum/1591704-post2.html) code.

## Usage
Compile with `make` then preload the output library into the game.

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./csgo.sh
```

## Known issues

* Keyboard inputs not currently working.
* Mouse input is sometimes erratic.