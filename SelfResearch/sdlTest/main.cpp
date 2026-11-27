#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_messagebox.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <cstdint>
#include <vector>
#include <array>
#include "GameObject.h"
#include "Resource.h"

using namespace std;

void handleSDLEvents(bool& isRunning, int& width, int& height) {
    SDL_Event event{ 0};
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            case SDL_EVENT_WINDOW_RESIZED:
                width = event.window.data1;
                height = event.window.data2;

                break;
            default:
                break;
        }
    }
}

const size_t Layer_IDX_Level = 0;
const size_t Layer_IDX_Characters = 1;
struct GameState {
    array<vector<GameObject>, 2> layers;
    int playerIndex;

    GameState() {
        playerIndex = 0;
    }
};

void DrawObject(const SDL_Items& items, GameState& gameState, GameObject& obj, float deltaTime) {
    const int spriteSize = 32;
    float srcX = obj.currentAnimation != -1 ?
        obj.animations[obj.currentAnimation].CurrentFrame() * spriteSize : 0.0f;
    SDL_FRect src = {
        .x = srcX,
        .y = 0,
        .w = spriteSize,
        .h = spriteSize
    };
    SDL_FRect dst = {
        .x = obj.position.x,
        .y = obj.position.y,
        .w = spriteSize,
        .h = spriteSize
    };
    SDL_FlipMode flip = obj.direction == -1 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
    SDL_RenderTextureRotated(items.renderer, obj.texture, &src, &dst, 0, nullptr, flip);
}

int main(int argc, char* argv[]) {
    SDL_State state;
    SDL_Items sdlItems = state.Initialize();
    
    // Load Assets
    Resource resources(&sdlItems);
    // Sprite idle("./Data/Player/idle.png", sdlItems.renderer);
    // SDL_SetTextureScaleMode(idle.GetTexture(), SDL_SCALEMODE_NEAREST);

    // Setup game data
    GameState gs;
    GameObject player ;
    player.type = ObjectType::player;
    player.texture = resources.GetPlayerTexture(ANIMATION_STATE_IDLE);
    player.animations = resources.GetPlayerAnimations();
    player.currentAnimation = ANIMATION_STATE_IDLE;
    gs.layers[Layer_IDX_Characters].push_back(player);

    const bool* keys = SDL_GetKeyboardState(nullptr);
    uint64_t prevTime = SDL_GetTicks();
    
    bool isRunning = true;
    while(isRunning) {
        uint64_t nowTime = SDL_GetTicks(); //Gives us number of ticks since SDL was initialized
        float deltaTime = (nowTime - prevTime) / 1000.0f; //Converts to seconds

        handleSDLEvents(isRunning, sdlItems.windowWidth, sdlItems.windowHeight);
        SDL_SetRenderDrawColor(sdlItems.renderer, 20, 10, 30, 255);
        SDL_RenderClear(sdlItems.renderer);

        for(auto &layer : gs.layers) {
            for(GameObject &obj : layer) {
                obj.animations[obj.currentAnimation].Step(deltaTime);
                DrawObject(sdlItems, gs, obj, deltaTime);
            }
        }
        
        SDL_RenderPresent(sdlItems.renderer);
        prevTime = nowTime;
    }

    state.Cleanup();
    return 0;
}