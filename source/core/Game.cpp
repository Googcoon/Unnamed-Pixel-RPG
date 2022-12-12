#include "core/Game.hpp"
#include "core/Input.hpp"
#include "core/TextureManager.hpp"
#include "math/Vector2.hpp"
#include <iostream>

#define GameTitle "Rogue Invaders"
#define ScreenWidth 900
#define ScreenHeight 900

Vector2 spritePos = { 0, 0 };
SDL_Texture* texture;
SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;


Game::Game() {
    m_window = nullptr;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Failed to initialize SDL" << std::endl;
        SDL_Delay(5000);
    }
    else {
        this->m_window = SDL_CreateWindow(GameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
        renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);

        this->m_running = true;
        texture = TextureManager::LoadTexture("..\\assets\\house.png");
        const SDL_Surface* windowSurface = SDL_GetWindowSurface(this->m_window);
        spritePos = { static_cast<float>(windowSurface->w / 2.0 - 700.0 / 2.0), static_cast<float>(windowSurface->h / 2.0 - 768.0 / 2.0) };
    }
}

Game::~Game() {
    SDL_DestroyWindow(this->m_window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::ProcessEvents() {
    while (SDL_PollEvent(&event)) {

        //Calls input manager to update state
        Input::UpdateKeyboardState(SDL_GetKeyboardState(nullptr));
        Input::UpdateMouseState(event.button);

        switch (event.type)
        {
            case(SDL_QUIT):
                m_running = false;
                break;


            default:

                break;
        }
    }
}

void Game::Update(double deltaTime) {
 /*
    if(Input::IsCurrentPress(SDL_SCANCODE_W) || Input::IsCurrentPress(SDL_SCANCODE_UP))
    {
        spritePos.y -= 1 * deltaTime;
    }

    if (Input::IsCurrentPress(SDL_SCANCODE_S) || Input::IsCurrentPress(SDL_SCANCODE_DOWN))
    {
        spritePos.y += 1 * deltaTime;
    }
 */

    if (Input::IsCurrentPress(SDL_SCANCODE_A) || Input::IsCurrentPress(SDL_SCANCODE_LEFT))
    {
        spritePos.x -= 1 * deltaTime;
    }

    if (Input::IsCurrentPress(SDL_SCANCODE_D) || Input::IsCurrentPress(SDL_SCANCODE_RIGHT))
    {
        spritePos.x += 1 * deltaTime;
    }

}

void Game::Render() {
    SDL_RenderClear(renderer);
    //Call all draw/render logic in here
    TextureManager::DrawTexture(texture, { static_cast<int>(spritePos.x), static_cast<int>(spritePos.y),  700, 768});

    SDL_RenderPresent(renderer);

}