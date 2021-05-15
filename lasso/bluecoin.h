#ifndef __BLUECOIN_H__
#define __BLUECOIN_H__

#include "MovingObject.h"

class BlueCoin : public MovingObject {
    double bluecoin_start_x;
    double bluecoin_start_y;
    double release_speed;
    double release_angle_deg;
    double bluecoin_ax;
    double bluecoin_ay;

    // Moving parts
    Circle bluecoin_circle;

public:
    BlueCoin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    bluecoin_ax = argax;
    bluecoin_ay = argay;
    initBlueCoin();
  }

    void initBlueCoin();
    void resetBlueCoin();

}; // End class BlueCoin

#endif
