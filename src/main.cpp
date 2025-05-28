//
// Created by jossi on 27/05/2025.
//
#include "libtcod.hpp"

// to rebuild ue5 style use these cmds in project file cmd prompt :
//cmake -B build -S .
// cmake --build build

int main(){

  TCODConsole::initRoot(80, 50, "bitch tv", false); // works but is crashing.


  system("pause");
  return 0;
}
