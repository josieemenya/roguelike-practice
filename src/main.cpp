//
// Created by jossi on 27/05/2025.
//
#include "libtcod.hpp"

#define SDL_MAIN_HANDLED
#include <SDL3/SDL_main.h>

#include "Engine.h"

// to rebuild ue5 style use these cmds in project file cmd prompt :
//cmake -B build -S .
// cmake --build build

int main(int argc, char* argv[]){
    Center::Engine engine;

    while(engine.isRunning()){

      engine.render();
      engine.input();
      engine.update();
    }

    return 0;
}
