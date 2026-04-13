#pragma once

#include "Drawable.h"
#include "raylib/raylib.h"

class Player : public virtual Drawable {

    public:
        float x;
        float y;
        float width;
        float height;
        Color color;
        float velocity;
        
        Player() = default;

        void draw() override;

        void update( float delta );
};