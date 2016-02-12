#include "stdafx.h"
#include "tank.h"

#include "world.h"

void Tank_Init(Tank* tank, TankColor color, double x, double y, Direction dir) {

}

void Tank_Init(Tank* tank, TankColor color, int row, int column, Direction dir) {

}

bool Tank_IsMoving(const Tank* tank) {

  return true;
}

bool Tank_IsMoving(const Tank* tank, Direction dir) {
  
  return false;
}

void Tank_StartMoving(Tank* tank, Direction dir) {

}

void Tank_StopMoving(Tank* tank) {

}

void Tank_UpdatePosition(Tank* tank, int delta_time) {

}

void Tank_UpdateAnimation(Tank* tank, int delta_time) {

}

void Tank_Render(const Tank* tank, SDL_Renderer* ren, SDL_Texture* tex) {

  //SDL_RenderCopyEx(ren, tex, &tex_rect, &ren_rect, angle, nullptr, SDL_FLIP_NONE);
}
