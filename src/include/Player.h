#pragma once

#include "Drawable.h"
#include "raylib/raylib.h"

class Player : public virtual Drawable {

    public:
        Vector2 position;
        float width;
        float height;
        Color color;
        Vector2 velocity;
        
        Player() = default;

        void draw() override;

        void update( float delta );
};