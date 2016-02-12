#ifndef WORLD_H_
#define WORLD_H_

//! Размер полей карты игрового мира (в пикселях)
/*! Поля могут быть свободными или препятствиями для танков.
 */
const int kTileSize = 40;

//! Размер танков в игровом мире (в пикселях)
/*! Меньше размера полей, чтобы у танков было место для маневра.
 */
const int kTankSize = 32;

//! Размер снарядов в игровом мире (в пикселях)
const int kMissileSize = 8;

//! Размер спрайтов взрыва в игровом мире (в пикселях)
const int kExplosionSize = 64;

//! Количество строк на карте игрового мира
const int kTileRows = 6;

//! Количество столбцов на карте игрового мира
const int kTileColumns = 8;

//! Скорость движения танков (пикселей в миллисекунду)
const double kTankVelocity = (double) kTileSize / 500;

//! Скорость движения снарядов (пикселей в миллисекунду)
const double kMissileVelocity = (double) 3 * kTileSize / 500;

//! Ширина карты игрового мира (в пикселях)
const int kWorldWidth = kTileColumns * kTileSize;

//! Высота карты игрового мира (в пикселях)
const int kWorldHeight = kTileRows * kTileSize;

//! Ширина окна программы (в пикселях)
const int kWindowWidth = kWorldWidth;

//! Высота окна программы (в пикселях)
const int kWindowHeight = kWorldHeight;

#endif  // WORLD_H_