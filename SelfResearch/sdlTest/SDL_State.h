#pragma once
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_messagebox.h>
#include <stdexcept>

using namespace std;

struct SDL_Items {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int windowWidth = 800;
    int windowHeight = 500;
    int gameWidth = 600;
    int gameHeight = 300;
};

class SDL_State {
    public:
        SDL_State();
        SDL_Items Initialize();
        void Cleanup();
        
    private:
        SDL_Items state;
        SDL_Window* CreateWindow();
        SDL_Renderer* CreateRenderer();
        void ConfigurePresentation();
};