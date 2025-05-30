//
// Created by jossi on 27/05/2025.
//
#define TCODLIB_STATIC
#include <libtcod/console.hpp>

#define SDL_MAIN_HANDLED

#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>

#include "Engine.h"


// to rebuild ue5 style use these cmds in project file cmd prompt :
//cmake -B build -S .
// cmake --build build

using namespace Center;

int SDL_main(int argc, char* argv[]){
    (void)argc;
    (void)argv;

    Engine engine;

    while(engine.isRunning()){

      engine.render();
      engine.input();
      engine.update();
    }

    return 0;
}
