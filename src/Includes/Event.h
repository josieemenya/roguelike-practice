//
// Created by jossi on 28/05/2025.
//

#ifndef EVENT_H
#define EVENT_H
#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

namespace Center {
    enum class Event : int {
        None = 0,
        MoveUp,
        MoveDown,
        MoveLeft,
        MoveRight,
        Quit
     };
}

#endif //EVENT_H
