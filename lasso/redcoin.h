#ifndef __REDCOIN_H__
#define __REDCOIN_H__

#include "MovingObject.h"

class RedCoin : public MovingObject {
    double redcoin_start_x;
    double redcoin_start_y;
    double release_speed;
    double release_angle_deg;
    double redcoin_ax;
    double redcoin_ay;

    // Moving parts
    Circle redcoin_circle;

public:
    RedCoin(double speed, double angle_deg, double argax, double argay, bool argpaused, bool rtheta) : MovingObject(speed, angle_deg, argax, argay, argpaused, rtheta) {
    release_speed = speed;
    release_angle_deg = angle_deg;
    redcoin_ax = argax;
    redcoin_ay = argay;
    initRedCoin();
  }

    void initRedCoin();
    void resetRedCoin();

}; // End class RedCoin

#endif
