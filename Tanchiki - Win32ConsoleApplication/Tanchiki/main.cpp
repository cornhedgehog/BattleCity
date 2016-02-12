#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "explosion_sprite.h"
#include "input.h"
#include "missile.h"
#include "tank.h"
#include "world.h"

int _tmain(int argc, _TCHAR* argv[]) {
  int error = 0;

  int sdl = SDL_Init(SDL_INIT_VIDEO);
  if (sdl != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    error = 1;
  } else {

    SDL_Window* win = SDL_CreateWindow("Hello, Tanky!",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        kWindowWidth, kWindowHeight, SDL_WINDOW_SHOWN);
    if (win == nullptr){
      std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
      error = 1;
    } else {
    
      // Устанавливаем более высокое качество сглаживания
      SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

      SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
      if (ren == nullptr){
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        error = 1;
      } else {

        int img = IMG_Init(IMG_INIT_PNG);
        if (img == 0) {
          std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
          error = 1;
        } else {

          SDL_Surface* tanks_png = IMG_Load("MulticolorTanks.png");
          if (tanks_png == nullptr){
            std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
            error = 1;
          }

          SDL_Surface* explosion_png = IMG_Load("ExplosionSprite.png");
          if (explosion_png == nullptr){
            std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
            error = 1;
          }         
          
          if (tanks_png != nullptr && explosion_png != nullptr) {

            SDL_Texture* tanks_tex = SDL_CreateTextureFromSurface(ren, tanks_png);
            SDL_FreeSurface(tanks_png);  // Изображение в оперативке больше не нужно
            tanks_png = nullptr;  // Как будто изображение в оперативке и не создавали
            if (tanks_tex == nullptr){
              std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
              error = 1;
            }

            SDL_Texture* explosion_tex = SDL_CreateTextureFromSurface(ren, explosion_png);
            SDL_FreeSurface(explosion_png);  // Изображение в оперативке больше не нужно
            explosion_png = nullptr;  // Как будто изображение в оперативке и не создавали
            if (tanks_tex == nullptr){
              std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
              error = 1;
            }
            
            if (tanks_tex != nullptr && explosion_tex != nullptr) {

              // Создаем курсор в виде перекрестия
              SDL_Cursor* cur = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
              if (cur == nullptr) {
                std::cerr << "SDL_CreateSystemCursor Error: " << SDL_GetError() << std::endl;                
                error = 0;  // Не критичная ошибка
              } else {
                // Устанавливаем созданный курсор
                SDL_SetCursor(cur);
              }  // Не критичная ошибка, продолжаем
                          
              int n_players = 4;
              const int max_players = 4;
              Tank players[max_players];
              Tank_Init(&players[0], TANK_GREEN, 0, 0, DIR_RIGHT);
              Tank_Init(&players[1], TANK_YELLOW, kTileRows-1, kTileColumns - 1, DIR_LEFT);
              Tank_Init(&players[2], TANK_CYAN, 0, kTileColumns - 1, DIR_DOWN);
              Tank_Init(&players[3], TANK_BLUE, kTileRows-1, 0, DIR_UP);

              int n_missiles = 0;
              const int max_missiles = 10;
              Missile* missiles[max_missiles];

              int n_explosions = 0;
              const int max_explosions = 10;
              Explosion* explosions[max_explosions];

              // Получаем текущее время
              int current_time = SDL_GetTicks();

              bool game_over = false;
              while (!game_over) {

                SDL_Event event;
                while (SDL_PollEvent(&event) != 0) {
                  switch (event.type) {
                  case SDL_QUIT: 
                    game_over = true;
                    break;

                  // Только для демонстрации!
                  case SDL_MOUSEBUTTONDOWN:
                    switch (event.button.button) {
                    case SDL_BUTTON_LEFT:
                      Explosion* new_explosion = new Explosion;
                      Explosion_Init(new_explosion, event.button.x, event.button.y);
                      explosions[n_explosions++] = new_explosion;
                      break;
                    }

                  default:
                    // Передаем событие обработчикам по цепочке
                    if (Input_ProcessWASD(&players[0], &event))
                      break;
                    if (Input_ProcessArrows(&players[1], &event))
                      break;
                    if (Input_ProcessMouse(&players[2], &event))
                      break;
                  }
                }
                
                // Вычисляем прошедшее с прошлого кадра время
                int previous_time = current_time;
                current_time = SDL_GetTicks();
                int delta_time = current_time - previous_time;

                // Обновляем анимацию и координаты танков
                for (int i = 0; i < n_players; ++i) {
                  Tank_UpdateAnimation(&players[i], delta_time);
                  Tank_UpdatePosition(&players[i], delta_time);
                }

                /*
                // Обновляем анимацию и координаты снарядов
                for (int i = 0; i < n_missiles; ++i) {
                  Missile_UpdateAnimation(missiles[i], delta_time);
                  Missile_UpdatePosition(missiles[i], delta_time);
                  // Удаляем снаряды, вышедшие за границы игрового мира
                  if (Missile_IsPositionedOutside(missiles[i])) {
                    delete missiles[i];
                    missiles[i] = nullptr;
                  }
                }
                // Освобождаем место в массиве из-под удаленных снарядов
                auto missiles_end = std::remove(missiles, missiles + n_missiles, nullptr);
                n_missiles = missiles_end - missiles;
                */

                // Обновляем анимацию спрайтов взрыва
                for (int i = 0; i < n_explosions; ++i) {
                  Explosion_UpdateAnimation(explosions[i], delta_time);
                  // Удаляем спрайты взрыва, у которых закончились кадры анимации
                  if (Explosion_HasAnimationEnded(explosions[i])) {
                    delete explosions[i];
                    explosions[i] = nullptr;
                  }
                }
                // Освобождаем место в массиве из-под удаленных спрайтов взрыва
                auto explosions_end = std::remove(explosions, explosions + n_explosions, nullptr);
                n_explosions = explosions_end - explosions;

                SDL_RenderClear(ren);
                for (int i = 0; i < n_players; ++i) {
                  Tank_Render(&players[i], ren, tanks_tex);
                }
                /*
                for (int i = 0; i < n_missiles; ++i) {
                  Missile_Render(missiles[i], ren, missile_tex);
                }
                */
                for (int i = 0; i < n_explosions; ++i) {
                  Explosion_Render(explosions[i], ren, explosion_tex);
                }
                SDL_RenderPresent(ren);
              }

              // Удаляем курсор, если он был создан
              if (cur) SDL_FreeCursor(cur);
            }
            // Удаляем текстуры, если они были созданы
            if (tanks_tex) SDL_DestroyTexture(tanks_tex);
            if (explosion_tex) SDL_DestroyTexture(explosion_tex);
          }
          // Удаляем изображения, если они были созданы
          if (tanks_png) SDL_FreeSurface(tanks_png);
          if (explosion_png) SDL_FreeSurface(explosion_png);
          IMG_Quit();
        }
        SDL_DestroyRenderer(ren);
      }
      SDL_DestroyWindow(win);
    }
    SDL_Quit();
  }

  return error;
}
