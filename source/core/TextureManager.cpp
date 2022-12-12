#include "core/TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filePath)
{
    return IMG_LoadTexture(Game::renderer, filePath);
}

SDL_Texture* TextureManager::LoadTexture(const std::string& filePath)
{
    return IMG_LoadTexture(Game::renderer, filePath.c_str());
}

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect crop, SDL_Rect position, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer, texture, &crop, &position, 0, nullptr, flip);
}

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect position, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer, texture, nullptr, &position, 0, nullptr, flip);
}