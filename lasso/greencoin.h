#ifndef __GREENCOIN_H__
#define __GREENCOIN_H__

#include "MovingObject.h"

class GreenCoin : public MovingObject {
    double greencoin_start_x;
    double greencoin_start_y;
    double release_speed;
    double release_angle_deg;
    double greencoin_ax;
    double greencoin_ay;

    // Moving parts
    Circle greencoin_circle;

public:
    GreenCoin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    greencoin_ax = argax;
    greencoin_ay = argay;
    initGreenCoin();
  }

    void initGreenCoin();
    void resetGreenCoin();

}; // End class GreenCoin

#endif
