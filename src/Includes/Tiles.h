#ifndef TILES_H
#define TILES_H

#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Flags.h" 



namespace Tiles{
    class BaseTile{

        BaseTile() = default;
        ~BaseTile() = default;

        public:
        int Tile; 
        TileFlags blocking = TileFlags::NONE; 


        BaseTile(unsigned int blocked = 1 << 0, unsigned int block_sight = 1 << 1){
            blocking |= blocked;
            
            if ((blocking & blocked) == TileFlags::BLOCKED){
                blocking |= block_sight; // by default a blocked tile, blocks sight.
            }
        }

    };
}


#endif // TILES_H