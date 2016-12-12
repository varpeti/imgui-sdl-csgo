![imgui demo in Counter-Strike: Global Offensive on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/csgo-ingame-demo.png) | ![imgui demo in Counter-Strike: Source on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/css-ingame-demo.png) | ![imgui demo in Team Fortress 2 on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/tf2-ingame-demo.png) |
| :---: | :---: | :---: |
| Counter-Strike: Global Offensive | Counter-Strike: Source | Team Fortress 2 |

# imgui-sdl-csgo

Implements the [imgui](https://github.com/ocornut/imgui) graphical user interface by hijacking the `SDL_GL_SwapWindow` symbol. Nothing really specific for Counter-Strike: Global Offensive any more but changing the repository name now is a pain.

Special thanks to [SirBarclay](https://github.com/SirBarclay) who provided a [working example](https://github.com/SirBarclay/meh/blob/master/test.cpp) of OpenGL drawing based on [my initial hooking](https://www.unknowncheats.me/forum/1591704-post2.html) code.

## Usage

You will need the appropriate SDL2 library for the specified architecture.

### Injecting

See my [blog post](https://aixxe.net/2016/09/shared-library-injection) for some loading options.

#### 32-bit

Compile with `make x86 TYPE=runtime-x86` and load with any injection method.

#### 64-bit

Compile with `make x64 TYPE=runtime-x64` and load with any injection method.

### Preloading

### 32-bit

Compile with `make x86 TYPE=preload` and launch.

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./hl2.sh -game tf
```

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./hl2.sh -game cstrike
```

### 64-bit

Compile with `make x64 TYPE=preload` and launch.

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./csgo.sh
```