#include "redcoin.h"
#include "lasso.h"

void RedCoin::initRedCoin() {
    redcoin_start_x = PLAY_X_START+OFFSET_SIZE ;
    redcoin_start_y = OFFSET_SIZE/5;
    redcoin_circle.reset(redcoin_start_x, redcoin_start_y, REDCOIN_SIZE);
    redcoin_circle.setColor(COLOR("red"));
    redcoin_circle.setFill(true);
    addPart(&redcoin_circle);
}

void RedCoin::resetRedCoin() {
    double redcoin_speed = REDCOIN_SPEED;
    double redcoin_angle_deg = REDCOIN_ANGLE_DEG;
    redcoin_ax = 3.5*REDCOIN_G ;
    redcoin_ay = REDCOIN_G;
    bool paused = true, rtheta = true;
    reset_all(redcoin_start_x, redcoin_start_y, redcoin_speed, redcoin_angle_deg, redcoin_ax, redcoin_ay, paused, rtheta);
}
