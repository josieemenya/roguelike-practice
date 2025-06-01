//
// Created by jossi on 28/05/2025.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <queue>
#include "Components.h"
#include <libtcod/bsp.h>


namespace Center {

    enum class Event : int;

    class Engine{
      public:
        Engine();
        ~Engine() = default;

        void input();
        void update();
        void render();

        /*void draw_entity(tcod::Console e_console, Component::Entity* entity){
          TCOD_console_set_default_background(e_console, entity->color);
            TCOD_console_put_char(e_console, entity->x, entity->y, entity->c, TCOD_BKGND_NONE);
        }

        void render_all(tcod::Console e_console, std::queue<Component::Entity*> entities, int width, int height){

            while(!entities.empty()) {
                    Component::Entity* entity = entities.front();
                    draw_entity(e_console, entity);
                    entities.pop();
                }
        }*/

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
