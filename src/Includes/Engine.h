//
// Created by jossi on 28/05/2025.
//

#ifndef ENGINE_H
#define ENGINE_H
#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Characters.h"

namespace Center {

    enum class Event : int;

    class Engine{
      public:
        Engine();
        ~Engine() = default;

        void input();
        void update();
        void render();

        bool isRunning() const;

        private:
        void isKeyDownEvent(const SDL_Event& event);
        void Quit();

        tcod::Console engine_console;
        tcod::Context engine_context;

        Characters::Player* PlayerCharacter;
        Event next_event;
        bool running;
    };
}

#endif //ENGINE_H
