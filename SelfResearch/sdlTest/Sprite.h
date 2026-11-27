#pragma once
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>

class Sprite {
    public:
        Sprite(const char* path, SDL_Renderer* renderer);
        Sprite(SDL_Texture* texture);
        SDL_Texture* GetTexture();
        void MoveAndSlide(float x, float y, SDL_Renderer* renderer);
        void Render(SDL_Renderer* renderer);
        bool flipX;
        static const int SpriteSize = 32;
        
        private:
        SDL_Texture* texture;
        SDL_FRect src;
        SDL_FRect dst;
};