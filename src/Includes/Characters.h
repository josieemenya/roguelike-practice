//
// Created by jossi on 28/05/2025.
//

#ifndef CHARACTERS_H
#define CHARACTERS_H
#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Position.h"

namespace Characters {
    class Player {

      public:

        Player() = default;
        ~Player() = default;
        Location::Position PlayerLocation;
    };

}

#endif //CHARACTERS_H
