#include "stdafx.h"
#include "input.h"

#include "world.h"

bool Input_ProcessWASD(Tank* tank, const SDL_Event* event) {

  return false;
}

bool Input_ProcessArrows(Tank* tank, const SDL_Event* event) {
  switch (event->type) {
  case SDL_KEYDOWN:
    switch (event->key.keysym.sym) {
    case SDLK_UP:
      Tank_StartMoving(tank, DIR_UP);
      return true;
    //case...
    }
    break;
  case SDL_KEYUP:
    switch (event->key.keysym.sym) {
    case SDLK_UP:
      if (Tank_IsMoving(tank, DIR_UP))
        Tank_StopMoving(tank);
      return true;
    //case...
    }
    break;
  }
  return false;
}

bool Input_ProcessMouse(Tank* tank, const SDL_Event* event) {

  return false;
}