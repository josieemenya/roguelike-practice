//
// Created by jossi on 27/05/2025.
//

#ifndef ACTORS_H
#define ACTORS_H
#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Character{ // Abstract Class
  public:
  // Character Movement and Speed
  int x, y {};

  protected:
  // Character Components :
  char body{};

  // Character Stats
  protected:

  float Health;
  float MaxHealth;

  public:
  Character() = default;
  Character(int x, int y, char body, int Health, int MaxHealth) : x{x}, y{y}, body{body}, MaxHealth{MaxHealth} {};
  virtual ~Character() = default;

  virtual void Update(float deltaTime) = 0;

 };




#endif //ACTORS_H
