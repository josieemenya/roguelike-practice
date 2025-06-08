//
// Created by jossi on 28/05/2025.
//

#ifndef CHARACTERS_H
#define CHARACTERS_H
#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Position.h"
#include <array>

namespace Characters {
    class Player : public Component::Entity {

      public:

        Player() = default;
        ~Player() = default;

        void setLocation(std::array<int,2> newLocation){
          x = newLocation[0];
          y = newLocation[1];
        }

    };

}

#endif //CHARACTERS_H
