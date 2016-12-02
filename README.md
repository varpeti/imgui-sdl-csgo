![imgui demo in Counter-Strike: Global Offensive on Linux](https://cdn.aixxe.net/projects/imgui-sdl-csgo/demo-ui-example.png)

# imgui-sdl-csgo

Implements the [imgui](https://github.com/ocornut/imgui) graphical user interface by hijacking the `SDL_GL_SwapWindow` symbol. This repository specifically targets Counter-Strike: Global Offensive but should work in other games that use SDL with minor changes.

## Usage
Compile with `make` then preload the output library into the game.

```
LD_PRELOAD=/home/aixxe/libsdl-imgui.so ./csgo.sh
```

## Known issues

* Keyboard inputs not currently working.
* Mouse input is sometimes erratic.