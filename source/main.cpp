#include "SDL2/SDL.h"
#include "core/Game.hpp"

#undef main
int main() {
    Game* game = new Game();

    int FPS = 60;
    Uint64 now = SDL_GetPerformanceCounter();
    double deltaTime = 0;

    while (game->IsRunning())
    {
        const Uint64 last = now;
        now = SDL_GetPerformanceCounter();

        deltaTime = (static_cast<double>(now) - static_cast<double>(last)) * 1000 / static_cast<double>(SDL_GetPerformanceFrequency());

        game->ProcessEvents();
        game->Update(deltaTime);
        game->Render();
        SDL_Delay(1000 / FPS);
    }

    delete game;
    game = nullptr;
    return 0;
}