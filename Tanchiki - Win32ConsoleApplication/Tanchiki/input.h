#ifndef INPUT_H_
#define INPUT_H_

#include <SDL_events.h>
#include "tank.h"

//! Обработать для танка события, связанные с клавишами W,A,S,D
/*! Возвращает true, если событие было обработано.
 */
bool Input_ProcessWASD(Tank* tank, const SDL_Event* event);

//! Обработать для танка события, связанные с клавишами стрелок
/*! Возвращает true, если событие было обработано.
 */
bool Input_ProcessArrows(Tank* tank, const SDL_Event* event);

//! Обработать для танка события, связанные с мышью
/*! Возвращает true, если событие было обработано.
 */
bool Input_ProcessMouse(Tank* tank, const SDL_Event* event);

#endif  // INPUT_H_
