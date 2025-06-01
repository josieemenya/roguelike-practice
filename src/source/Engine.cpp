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
#include <filesystem>
#include <array>
#include <exception>
#include <iostream>
#include "Components.h"

// auto tileset = tcod::load_tilesheet(get_data_dir() / "dejavu16x16_gs_tc.png", {32, 8}, tcod::CHARMAP_TCOD);
   // params.tileset = tileset.get();


auto path = std::filesystem::current_path() / "data" / "test.png";
tcod::Tileset PlayerSprite;
TCOD_Tileset* PlayerSheet;

constexpr size_t TILE_COUNT = 312;

constexpr std::array<int, TILE_COUNT> make_full_charmap() {
    std::array<int, TILE_COUNT> arr{};
    for (size_t i = 0; i < TILE_COUNT; ++i) {
        arr[i] = static_cast<int>(i);
    }
    return arr;
}

constexpr auto full_charmap = make_full_charmap();

//auto Enemy = new Component::Entity(12, 12, full_charmap[30], TCODColor(255, 255, 255));

namespace Center{

    Engine::Engine() : running (true) {
      int window_width, window_height;
      window_width = 80;
      window_height = 50;
      constexpr std::string_view window_title = "My First Roguelike";

      engine_console = tcod::Console{ window_width, window_height };
      TCOD_ContextParams params {};

      PlayerSprite = tcod::load_tilesheet(path, {24, 13}, full_charmap);
      params.tileset = PlayerSprite.get();


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

      if(std::filesystem::exists(path)) { // 16/16 pixels

        engine_console.at(PlayerCharacter->PlayerLocation.x, PlayerCharacter->PlayerLocation.y).ch = full_charmap[2];
      }
      else {
        std::cerr << "Could not load test.bmp" << std::endl;
      }

      //engine_console.set_tilesheet(PlayerSprite);




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
       switch(event.key.scancode) {

         case SDL_SCANCODE_UP:
		 	      case SDL_SCANCODE_W:
           		next_event = Event::MoveUp;
           		break;

         case SDL_SCANCODE_DOWN:
			      case SDL_SCANCODE_S:
            	next_event = Event::MoveDown;
             	break;

         case SDL_SCANCODE_LEFT:
			      case SDL_SCANCODE_A:
           		next_event = Event::MoveLeft;
           		break;

         case SDL_SCANCODE_RIGHT:
			      case SDL_SCANCODE_D:
           		next_event = Event::MoveRight;
           break;

         case SDL_SCANCODE_ESCAPE:
           next_event = Event::Quit;
           break;

		 default:
		 	break;
       }
    }

    void Engine::Quit(){

      running = false;
      delete PlayerCharacter;
      PlayerCharacter = nullptr;


    }
}