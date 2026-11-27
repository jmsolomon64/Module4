#include "Sprite.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <stdexcept>

Sprite::Sprite(const char* path, SDL_Renderer* renderer) {
    this->texture = IMG_LoadTexture(renderer, path);
    this->flipX = false;
    if(!texture) {
        throw std::runtime_error("failed to load texture");
    }
    this->src = {
        .x = 0,
        .y = 0,
        .w = Sprite::SpriteSize,
        .h = Sprite::SpriteSize
    };
    this->dst = {
        .x = 0,
        .y = 0,
        .w = Sprite::SpriteSize,
        .h = Sprite::SpriteSize
    };
}

SDL_Texture* Sprite::GetTexture() {
    return this->texture;
}

void Sprite::Render(SDL_Renderer* renderer) {
    SDL_FlipMode flipMode = this->flipX ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderTextureRotated(renderer, this->texture, &this->src, &this->dst, 0, nullptr, flipMode);
}

void Sprite::MoveAndSlide(float x, float y, SDL_Renderer* renderer) {
    this->dst.x += x;
    this->dst.y = y; //TODO: fix Y stuff later
}