//
// Created by jossi on 28/05/2025.
//

#ifndef POSITION_H
#define POSITION_H

#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

namespace Location{

    struct Position{
      public:

      int x;
      int y;

      Position() = default;
      Position(int x, int y) : x(x), y(y) {};
     
      Position& operator=(Position& other){
        x = other.x;
        y = other.y;
        return *this;
      } 

      Position& operator=(std::array<int, 2> other){
        x = other[0];
        y = other[1];
        return *this;
      } 

      Position& operator=(std::array<int*, 2>& other){
        x = *(other[0]);
        y = *(other[1]);
        return *this;
      } 

    };
}

#endif //POSITION_H
