![imgui demo in Counter-Strike: Global Offensive on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/csgo-ingame-demo.png) | ![imgui demo in Counter-Strike: Source on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/css-ingame-demo.png) | ![imgui demo in Team Fortress 2 on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/tf2-ingame-demo.png) |
| :---: | :---: | :---: |
| Counter-Strike: Global Offensive | Counter-Strike: Source | Team Fortress 2 |

# imgui-sdl-csgo

Implements the [imgui](https://github.com/ocornut/imgui) graphical user interface by hijacking the `SDL_GL_SwapWindow` symbol. This repository will eventually target Counter-Strike: Global Offensive specfically, but is just as capable of working in other games that use SDL2.

Special thanks to [SirBarclay](https://github.com/SirBarclay) who provided a [working example](https://github.com/SirBarclay/meh/blob/master/test.cpp) of OpenGL drawing based on [my initial hooking](https://www.unknowncheats.me/forum/1591704-post2.html) code.

## Usage
Compile with `make` then preload the output library into the game.

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./csgo.sh
```

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./hl2.sh -game tf
```

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./hl2.sh -game cstrike
```

If you are targeting a 32-bit game make sure to change `-m64` to `-m32` in the Makefile.

You will also need the appropriate SDL2 library for the specified architecture.

## Known issues

* Keyboard inputs not currently working in Source games.
* Mouse input is sometimes erratic.