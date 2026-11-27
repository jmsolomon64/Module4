#pragma once
#include <SDL3/SDL_render.h>
#include <glm/ext/vector_float2.hpp>
#include <glm/glm.hpp>
#include <vector>
#include "Animation.h"

enum class ObjectType {
    player, level, enemy
};

struct GameObject {
    ObjectType type;
    glm::vec2 position, velocity, accelaration;
    float direction;
    std::vector<Animation> animations;
    int currentAnimation;
    SDL_Texture* texture;
    
    GameObject() {
        type = ObjectType::level;
        direction  = 1;
        position = velocity = accelaration = glm::vec2(0);
        currentAnimation = -1;
        texture = nullptr;
    }
};