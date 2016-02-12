#ifndef DIRECTION_H_
#define DIRECTION_H_

#define _USE_MATH_DEFINES
#include <cmath>

//! Возможные направления движения
enum Direction {
  DIR_UP = 0,
  DIR_LEFT = 1,
  DIR_DOWN = 2,
  DIR_RIGHT = 3,
};

//! Единичные вектора для каждого направления
/*! Ось Oy при работе с графикой направлена ВНИЗ.
 */
const struct {int ex, ey;} kUnitVectors[4] = {
  {0, -1},  //!< kUnitVectors[DIR_UP]
  {-1, 0},  //!< kUnitVectors[DIR_LEFT]
  {0, 1},   //!< kUnitVectors[DIR_DOWN]
  {1, 0}    //!< kUnitVectors[DIR_RIGHT]
};

// Полярные углы для каждого направления
/*! Ось Oy при работе с графикой направлена вниз,
 * поэтому угол отсчитывается ПО часовой стрелке.
 */
const double kPolarAngles[4] = {
  -M_PI/2,  //!< kPolarAngles[DIR_UP]
  M_PI,     //!< kPolarAngles[DIR_LEFT]
  M_PI/2,   //!< kPolarAngles[DIR_DOWN]
  0         //!< kPolarAngles[DIR_RIGHT]
};

#endif  // DIRECTION_H_
