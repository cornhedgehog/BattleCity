#ifndef EXPLOSION_SPRITE_H_
#define EXPLOSION_SPRITE_H_

#include <SDL_render.h>
#include "direction.h"

//! Характеристики спрайта взрыва
struct Explosion {
  double x, y;   //!< координаты
  double frame;  //!< номер кадра
  double angle;  //!< угол поворота
};

//! Количество кадров анимации взрыва в строке файла
const int kExplosionFramesNx = 4;

//! Количество кадров анимации взрыва в столбце файла
const int kExplosionFramesNy = 4;

//! Частота смены кадров анимации взрыва (кадров в миллисекунду)
const double kExplosionFrameRate = (double) 25 / 1000; 

//! Размер каждого кадра анимации взрыва в файле (в пикселях)
const int kExplosionFrameSize = 64;

//! Инициализация спрайта взрыва начальными значениями характеристик
/*! Центр спрайта взрыва размещается по указанным координатам.
 */
void Explosion_Init(Explosion* sprite, double x0, double y0);

//! Обновить кадр анимации взрыва в соответствии с прошедшим временем
void Explosion_UpdateAnimation(Explosion* sprite, int delta_time);

//! Проверить, закончились ли кадры анимации взрыва
bool Explosion_HasAnimationEnded(const Explosion* sprite);

//! Отрендерить спрайт взрыва на экране, используя его текстуру
void Explosion_Render(const Explosion* sprite, SDL_Renderer* ren, SDL_Texture* tex);

#endif  // EXPLOSION_SPRITE_H_
