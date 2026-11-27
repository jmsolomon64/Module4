#pragma once
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_render.h>
#include <vector>
#include <string>
#include "SDL_State.h"
#include "Animation.h"

using namespace std;

class Resource {
    public:
        Resource(SDL_Items* item);
        ~Resource();
        SDL_Texture* GetPlayerTexture(Animation_State state);
        vector<Animation> GetPlayerAnimations(); 
        private:
        vector<Animation> playerAnimations;
        vector<SDL_Texture*> playerTextures;
        SDL_Texture* LoadTexture(SDL_Renderer* renderer, const string &filepath);

};