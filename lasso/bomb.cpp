//
//  bomb.cpp
//  
//
//  Created by harshvardhan agarwal on 09/02/21.
//

#include "bomb.h"
#include "lasso.h"

void Bomb::initBomb() {
    bomb_start_x = WINDOW_X - 3*OFFSET_SIZE  ;
    bomb_start_y = BORDER_SIZE ;
    bomb_circle.reset(bomb_start_x, bomb_start_y, BOMB_SIZE);
    bomb_circle.setColor(COLOR("black"));
    bomb_circle.setFill(true);
    addPart(&bomb_circle);
}

void Bomb::resetBomb() {
    double bomb_speed = 0 ;
    double bomb_angle_deg = BOMB_ANGLE_DEG;
    bomb_ax = 0;
    bomb_ay = BOMB_G;
    bool paused = true, rtheta = true;
    reset_all(bomb_start_x, bomb_start_y, bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
}


