#ifndef MISSILE_H_
#define MISSILE_H_

#include <SDL_render.h>
#include "direction.h"

//! Характеристики снаряда
struct Missile {
  Direction dir;  //!< направление
  double x, y;    //!< координаты
  double vx, vy;  //!< вектор скорости
  double frame;   //!< номер кадра
};

//! Инициализация снаряда начальными значениями характеристик
void Missile_Init(Missile* missile, double x, double y, Direction dir);

//! Обновить кадр анимации снаряда в соответствии с прошедшим временем
void Missile_UpdateAnimation(Missile* missile, int delta_time);

//! Обновить координаты снаряда в соответствии с прошедшим временем
void Missile_UpdatePosition(Missile* missile, int delta_time);

//! Проверить, вышел ли снаряд за границы игрового мира
bool Missile_IsPositionedOutside(const Missile* missile);

//! Отрендерить снаряд на экране, используя его текстуру
void Missile_Render(const Missile* missile, SDL_Renderer* ren, SDL_Texture* tex);

#endif  // MISSILE_H_