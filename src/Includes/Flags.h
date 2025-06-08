#ifndef FLAGS_H
#define FLAGS_H

#include "libtcod.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


enum class TileFlags{
    NONE = 0,
    BLOCKED = 1 << 0,
    BLOCK_SIGHT = 1 << 1
};

inline TileFlags operator|(TileFlags self, TileFlags Other) {
    return static_cast<TileFlags>(static_cast<unsigned int>(self) | static_cast<unsigned int>(Other));
}

inline TileFlags operator&(const TileFlags self, TileFlags Other){
    return static_cast<TileFlags>(static_cast<unsigned int>(self) & static_cast<unsigned int>(Other));
}

inline TileFlags& operator|=(TileFlags &self, TileFlags Other){
    self =  self | Other;
    return self;
}

inline TileFlags operator|(TileFlags self, unsigned int Other) {
    return static_cast<TileFlags>(static_cast<unsigned int>(self) | (Other));
}

inline TileFlags operator&(const TileFlags self, unsigned int Other){
    return static_cast<TileFlags>(static_cast<unsigned int>(self) & (Other));
}

inline TileFlags& operator|=(TileFlags &self, unsigned int Other){
    self =  self | Other;
    return self;
}

inline TileFlags& operator&=(TileFlags& self, unsigned int Other){
    self = self & Other;
    return self;
}

#endif //FLAGS_H