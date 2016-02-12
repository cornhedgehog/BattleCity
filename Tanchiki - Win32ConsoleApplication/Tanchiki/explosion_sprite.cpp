#include "stdafx.h"
#include "explosion_sprite.h"

#include <cstdlib>
#include "world.h"

void Explosion_Init(Explosion* sprite, double x0, double y0) {

}

void Explosion_UpdateAnimation(Explosion* sprite, int delta_time) {

}

bool Explosion_HasAnimationEnded(const Explosion* sprite) {

  return false;
}

void Explosion_Render(const Explosion* sprite, SDL_Renderer* ren, SDL_Texture* tex) {

  //SDL_RenderCopyEx(ren, tex, &tex_rect, &ren_rect, sprite->angle, nullptr, SDL_FLIP_NONE);
}
