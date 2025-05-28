//
// Created by jossi on 28/05/2025.
//
#include "Engine.h"
#include <string_view>

#include "Event.h"
#include "Position.h"
#include "Characters.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_video.h>
#include <libtcod/context.h>
#include <libtcod/version.h>
#include <libtcod/context.hpp>



namespace Center{

    Engine::Engine() : running (true) {
      int window_width, window_height;
      window_width = 80;
      window_height = 50;
      constexpr std::string_view window_title = "My First Roguelike";

      engine_console = tcod::Console{ window_width, window_height };
      TCOD_ContextParams params {};

      params.tcod_version = TCOD_COMPILEDVERSION;
      params.window_title = window_title.data();
      params.console = engine_console.get();
      params.sdl_window_flags = SDL_WINDOW_RESIZABLE;

      engine_context = tcod::Context{params};
      PlayerCharacter = new Characters::Player();
      PlayerCharacter->PlayerLocation = Location::Position{(window_width/2), (window_height/2)};
    }

    void Engine::input(){

      SDL_Event event {};

      SDL_WaitEvent(&event);

      switch(event.type){

        case SDL_EVENT_KEY_DOWN:
          isKeyDownEvent(event);
          break;

        case SDL_EVENT_QUIT:
          next_event = Event::Quit;
          break;

        default:
          next_event = Event::None;
      }
      SDL_FlushEvent(SDL_EVENT_KEY_DOWN);
    }

    void Engine::render(){
      engine_console.clear();
      engine_console.at(PlayerCharacter->PlayerLocation.x, PlayerCharacter->PlayerLocation.y).ch = '@';

      engine_context.present(engine_console);
    }

    void Engine::update(){
        auto new_pos = PlayerCharacter->PlayerLocation;

        switch(next_event) {
          case Event::MoveUp:
            --new_pos.y;
            break;

          case Event::MoveDown:
            ++new_pos.y;
            break;

          case Event::MoveLeft:
            --new_pos.x;
            break;

          case Event::MoveRight:
            ++new_pos.x;
            break;

          case Event::Quit:
            Quit();
            break;

            default:
              break;
        }

        if (engine_console.in_bounds({new_pos.x, new_pos.y})){

           PlayerCharacter->PlayerLocation = new_pos;
        }
    }

    bool Engine::isRunning() const {
      return running;
    }

    void Engine::isKeyDownEvent(const SDL_Event& event) {
       switch(event.key.keysym.sym) {
         case SDLK_UP:
           next_event = Event::MoveUp;
           break;

         case SDLK_DOWN:
            next_event = Event::MoveDown;
             break;

         case SDLK_LEFT:
           next_event = Event::MoveLeft;
           break;

         case SDLK_RIGHT:
           next_event = Event::MoveRight;
           break;

         case SDLK_ESCAPE:
           next_event = Event::Quit;
           break;
       }
    }

    void Engine::Quit(){

      running = false;
      delete PlayerCharacter;
      PlayerCharacter = nullptr;

    }
}