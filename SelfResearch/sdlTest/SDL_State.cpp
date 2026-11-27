#include "SDL_State.h"

SDL_State::SDL_State() {
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Something went wrong", "OOF", nullptr);
        throw new runtime_error("Failed to initialize SDL");
    }
}

SDL_Items SDL_State::Initialize() {
    this->state.window = this->CreateWindow();
    this->state.renderer = this->CreateRenderer();
    this->ConfigurePresentation();
    return this->state;
}

void SDL_State::Cleanup() {
    SDL_DestroyRenderer(this->state.renderer);
    SDL_DestroyWindow(this->state.window);
    SDL_Quit();
}

SDL_Window* SDL_State::CreateWindow() {
    SDL_Window* window = SDL_CreateWindow("Test", this->state.windowWidth, this->state.windowHeight, SDL_WINDOW_RESIZABLE);
    if(!window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Something went wrong", "OOF", state.window);
        Cleanup();
        throw runtime_error("Failed to create window");
    }
    return window;
}

SDL_Renderer* SDL_State::CreateRenderer() {
    SDL_Renderer* renderer = SDL_CreateRenderer(state.window, nullptr);
    if(!renderer) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Something went wrong", "OOF", state.window);
        Cleanup();
        throw runtime_error("Failed to create renderer");
    }
    return renderer;
}

void SDL_State::ConfigurePresentation() {
    //Letter box keeps size the same regardless of window
    SDL_SetRenderLogicalPresentation(this->state.renderer, this->state.gameWidth, this->state.gameHeight, SDL_LOGICAL_PRESENTATION_LETTERBOX); 
}