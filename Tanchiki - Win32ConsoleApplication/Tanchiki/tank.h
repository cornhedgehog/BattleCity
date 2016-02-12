#ifndef TANK_H_
#define TANK_H_

#include <SDL_render.h>
#include "direction.h"
#include "tank_color.h"

//! Характеристики танка
struct Tank {
  int health;       //!< здоровье
  TankColor color;  //!< цвет (номер строки в файле)
  Direction dir;    //!< направление
  double x, y;      //!< координаты
  double vx, vy;    //!< вектор скорости
  double frame;     //!< номер кадра (столбец в файле)
};

//! Количество кадров анимации танка в строке файле
const int kTankFramesNumber = 8;

//! Частота смены кадров анимации танка (кадров в миллисекунду)
/*! При отриц. значении кадры меняются в обратном направлении
 * (верхняя сторона гусеницы должна перемещаться вперед).
 */
const double kTankFrameRate = - (double) kTankFramesNumber / 500; 

//! Размер каждого кадра анимации танка в файле (в пикселях)
const int kTankFrameSize = 32;

//! Углы поворота кадра анимации танка для каждого направления
/*! Относительно направления кадров анимации танка в файле.
 * Ось Oy при работе с графикой направлена вниз,
 * поэтому угол отсчитывается ПО часовой стрелке.
 */
const double kTankFrameAngles[4] = {
  -90.0,  //!< kTankFrameAngles[DIR_UP]
  180.0,  //!< kTankFrameAngles[DIR_LEFT]
  90.0,   //!< kTankFrameAngles[DIR_DOWN]
  0.0     //!< kTankFrameAngles[DIR_RIGHT]
};

//! Инициализация танка начальными значениями характеристик
void Tank_Init(Tank* tank, TankColor color, double x, double y, Direction dir);

//! Инициализация танка начальными значениями характеристик
/*! Танк размещается в центре указанного поля карты игрового мира.
 */
void Tank_Init(Tank* tank, TankColor color, int row, int column, Direction dir);

//! Проверить, движется ли танк
bool Tank_IsMoving(const Tank* tank);

//! Проверить, движется ли танк в указанном направлении
bool Tank_IsMoving(const Tank* tank, Direction dir);

//! Начать движение танка в указанном направлении
void Tank_StartMoving(Tank* tank, Direction dir);

//! Остановить движение танка
void Tank_StopMoving(Tank* tank);

//! Обновить координаты танка в соответствии с прошедшим временем
void Tank_UpdatePosition(Tank* tank, int delta_time);

//! Обновить кадр анимации танка в соответствии с прошедшим временем
void Tank_UpdateAnimation(Tank* tank, int delta_time);

//! Отрендерить танк на экране, используя его текстуру
void Tank_Render(const Tank* tank, SDL_Renderer* ren, SDL_Texture* tex);

#endif  // TANK_H_
