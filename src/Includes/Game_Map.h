#ifndef MAP_H
#define MAP_H

#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Tiles.h"



class game_map{

    int width, height; 



    public :
    game_map() = default;
    ~game_map() = default;

    
    
    int get_height() {return height;}
    int get_width() {return width;}

    game_map(int width, int height) : width(width), height(height){

    }
   
    //std::vector<std::vector<Tiles::BaseTile>> tiles;

    /*std::vector<std::vector<Tiles::BaseTile>> initialize_tiles(){

        std::vector<std::vector<Tiles::BaseTile>> tiles;
            for (int i = 0; i < height; i++){
                for(int j = 0; j < width; i++){
                    tiles[30][22].blocking |= TileFlags::BLOCKED;
                    tiles[30][22].blocking |= TileFlags::BLOCK_SIGHT;
                }
            }    
        return tiles;
    }*/
};














#endif // MAP_H