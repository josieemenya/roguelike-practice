//
// Created by jossi on 28/05/2025.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <iostream>
#include "Components.h"
#include "Game_Map.h"
#include <libtcod/bsp.h>


namespace Characters{
  class Player;
}

namespace Center {

    enum class Event : int;

    class Engine{
      public:
        Engine();
        ~Engine() = default;

        void input();
        void update();
        void render();

        void draw_entity(tcod::Console& e_console, Component::Entity* entity){
          if(e_console.in_bounds({entity->x, entity->y}))
            e_console.at(entity->x, entity->y).ch = entity->character;
        }

        void render_all(tcod::Console& e_console, std::vector<Component::Entity*>& entities, std::filesystem::path data_dir){

            e_console.clear();
            if(std::filesystem::exists(data_dir))
              std::for_each(entities.begin(), entities.end(), [this, &e_console](Component::Entity* entity){draw_entity(e_console, entity);});
            else
              std::cerr << "Could not load data directory and associated files" << std::endl;
        }

        bool isRunning() const;


        private:
        void isKeyDownEvent(const SDL_Event& event);
        void Quit();

        TCODBsp* RootMap = new TCODBsp(0,0, 512, 512);

        tcod::Console engine_console;
        tcod::Context engine_context;

        Characters::Player* PlayerCharacter;
        Event next_event;
        bool running;
    };
}

#endif //ENGINE_H
