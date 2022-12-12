#pragma once
#include <SDL2/SDL.h>


class Game {
public:
    Game();
    ~Game();
    void ProcessEvents();
    void Update(double deltaTime);
    void Render();
    [[nodiscard]] bool IsRunning() const { return this->m_running; }
    static SDL_Renderer* renderer;
    static SDL_Event event;
private:
    bool m_running;
    SDL_Window* m_window;
};

