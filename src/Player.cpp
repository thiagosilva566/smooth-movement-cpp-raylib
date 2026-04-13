#include "Player.h"
#include "raylib.h"

void Player::draw() {
    DrawRectangle( x, y, width, height, color );
};

void Player::update( float delta ) {

    if ( IsKeyDown( KEY_LEFT ) ) {
        x -= delta * velocity;
    }

    if ( IsKeyDown( KEY_RIGHT ) ) {
        x += delta * velocity;
    }

    if ( IsKeyDown( KEY_UP ) ) {
        y -= delta * velocity;
    }

    if ( IsKeyDown( KEY_DOWN ) ) {
        y += delta * velocity;
    }
    
}
