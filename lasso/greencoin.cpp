#include "greencoin.h"
#include "lasso.h"

void GreenCoin::initGreenCoin() {
    greencoin_start_x = (PLAY_X_START+WINDOW_X)/2-OFFSET_SIZE;
    greencoin_start_y = PLAY_Y_HEIGHT;
    greencoin_circle.reset(greencoin_start_x, greencoin_start_y, GREENCOIN_SIZE);
    greencoin_circle.setColor(COLOR("green"));
    greencoin_circle.setFill(true);
    addPart(&greencoin_circle);
}

void GreenCoin::resetGreenCoin() {
    double greencoin_speed = GREENCOIN_SPEED;
    double greencoin_angle_deg = GREENCOIN_ANGLE_DEG;
    greencoin_ax = 0;
    greencoin_ay = GREENCOIN_G;
    bool paused = true, rtheta = true ;
    reset_all(greencoin_start_x, greencoin_start_y, greencoin_speed, greencoin_angle_deg, greencoin_ax, greencoin_ay, paused, rtheta);
}
