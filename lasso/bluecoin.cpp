#include "bluecoin.h"
#include "lasso.h"

void BlueCoin::initBlueCoin() {
    bluecoin_start_x = (PLAY_X_START+WINDOW_X)/2;
    bluecoin_start_y = BORDER_SIZE ;
    bluecoin_circle.reset(bluecoin_start_x, bluecoin_start_y, BLUECOIN_SIZE);
    bluecoin_circle.setColor(COLOR(0,64,255));  // BLUE COLOR CODE
    bluecoin_circle.setFill(true);
    addPart(&bluecoin_circle);
}

void BlueCoin::resetBlueCoin() {
    double bluecoin_speed = BLUECOIN_SPEED;
    double bluecoin_angle_deg = BLUECOIN_ANGLE_DEG;
    bluecoin_ax = -BLUECOIN_G ;
    bluecoin_ay = 0 ;
    bool paused = true, rtheta = true;
    reset_all(bluecoin_start_x, bluecoin_start_y, bluecoin_speed, bluecoin_angle_deg, bluecoin_ax, bluecoin_ay, paused, rtheta);
}
