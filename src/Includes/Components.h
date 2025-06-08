//
// Created by jossi on 31/05/2025.
//

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Position.h"
#include <libtcod/bsp.h>

namespace Component{

    class Entity : public Location::Position {
      public:
      
      int character;
      TCOD_color_t color;

      Entity() = default;
      ~Entity() = default;

      // copy
      Entity(Entity& self, int x, int y, int character, TCOD_color_t color){
        self.x = x;
        self.y = y;
        self.character = character;
        self.color = color;
      }

      Entity(int x, int y, int c, TCOD_color_t color) : Location::Position(x, y), character(c), color(color){

      }


      // move
      void update(Entity& self){
        self.x += x;
        self.y += y;
      }
    };
}

#endif //COMPONENTS_H
