#include "Resource.h"

Resource::Resource(SDL_Items* items) {
    this->playerAnimations.resize(Animation_State::Count);
    this->playerTextures.resize(Animation_State::Count);
    this->playerAnimations[ANIMATION_STATE_IDLE] = Animation(8, 1.6f);
    this->playerTextures[ANIMATION_STATE_IDLE] = LoadTexture(items->renderer, "./Data/Player/idle.png");
} 

Resource::~Resource() {
    for(SDL_Texture* text : this->playerTextures) {
        SDL_DestroyTexture(text);
    }
}

SDL_Texture* Resource::GetPlayerTexture(Animation_State state) {
    return this->playerTextures[state];
}

vector<Animation> Resource::GetPlayerAnimations() {
    return this->playerAnimations;
}

SDL_Texture* LoadTexture(SDL_Renderer* renderer, const string& filepath) {
    SDL_Texture* tex = IMG_LoadTexture(renderer, filepath.c_str());
    SDL_SetTextureScaleMode(tex, SDL_SCALEMODE_NEAREST);
    return tex;
}

