#include "Player.h"
#include "raylib.h"
#include "Constants.h"
#include <cmath> 

void Player::draw() {
    DrawRectangle( position.x, position.y, width, height, color );
};

void Player::update( float delta ) {

    // I don't know what to name this variables
    double v1 = 20;      // Maybe that's the starting power?
    double v2 = 1.05;    // Maybe that's the friction of the ground?
    double v3 = 400;     // Maybe that's the power of the jump?
    double v4 = 20;      // The minimum horizontal speed of the player on the ground to bring them to a completely stop ( that's probably not a good idea :D )

    double terminalVelocity = 500;
    
    // update the velocities
    if ( IsKeyDown( KEY_LEFT ) ) {
        velocity.x -= v1;
    }

    if ( IsKeyDown( KEY_RIGHT ) ) {
        velocity.x += v1;
    }

    velocity.y += GRAVITATIONAL_ACCELERATION * delta;

    // check if it has reached the terminal velocity
    if ( fabs( velocity.x ) > terminalVelocity ) {
        velocity.x = (terminalVelocity * velocity.x) / fabs( velocity.x );
    }

    if ( fabs( velocity.y ) > terminalVelocity ) {
        velocity.y = ( terminalVelocity * velocity.y ) / fabs( velocity.y );
    }

    // updates the velocity if the player is in contact with the ground
    if ( position.y + height >= GetScreenHeight() ) {
        
        // so the player doesn't walk through the floor
        position.y = GetScreenHeight() - height;
        velocity.y = 0;

        // applies "friction" ( or maybe not, oh my god, I don't remember basic physics anymore ) to the player
        if ( IsKeyDown( KEY_LEFT ) || IsKeyDown( KEY_RIGHT ) ) {
            velocity.x = velocity.x / v2 < v4 ? 0 : velocity.x / v2;
        }
        
        // if the player jumps
        if ( IsKeyPressed( KEY_SPACE ) ) {
            velocity.y = -v3;
        }
        
    }

    // updates the positions
    position.y += velocity.y * delta;
    position.x += velocity.x * delta;
        
}
