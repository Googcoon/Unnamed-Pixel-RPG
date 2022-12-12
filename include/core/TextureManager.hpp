#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Game.hpp"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* filePath);
    static SDL_Texture* LoadTexture(const std::string& filePath);
    static void DrawTexture(SDL_Texture* texture, SDL_Rect crop, SDL_Rect position, SDL_RendererFlip flip = SDL_FLIP_NONE);
    static void DrawTexture(SDL_Texture* texture, SDL_Rect position, SDL_RendererFlip  = SDL_FLIP_NONE);
private:

};
