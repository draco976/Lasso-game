#include <simplecpp>
#include <string>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include "greencoin.h"
#include "redcoin.h"
#include "bluecoin.h"
#include "bomb.h"

using namespace simplecpp;

void Lasso::draw_lasso_band() {
    double len = (release_speed/MAX_RELEASE_SPEED)*LASSO_BAND_LENGTH;
    double arad = release_angle_deg*PI/180.0;
    double xlen = len*cos(arad);
    double ylen = len*sin(arad);
    lasso_band.reset(lasso_start_x, lasso_start_y, (lasso_start_x-xlen), (lasso_start_y+ylen));
    lasso_band.setThickness(LASSO_THICKNESS);
} // End Lasso::draw_lasso_band()

void Lasso::initLasso() {
    lasso_start_x = (PLAY_X_START+LASSO_X_OFFSET);
    lasso_start_y = (PLAY_Y_HEIGHT-LASSO_Y_HEIGHT);
    lasso_circle.reset(lasso_start_x, lasso_start_y, LASSO_SIZE);
    lasso_circle.setColor(COLOR("red"));
    lasso_circle.setFill(true);
    lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2);
    lasso_loop.setColor(COLOR("brown"));
    lasso_loop.setFill(true);
    addPart(&lasso_circle);
    addPart(&lasso_loop);
    lasso_looped = false;
    the_coin = NULL;
    num_coins = 0;
    the_bluecoin = NULL;
    the_redcoin = NULL;
    the_greencoin = NULL;
    the_bomb = NULL;

    lasso_line.reset(lasso_start_x, lasso_start_y, lasso_start_x, lasso_start_y);
    lasso_line.setColor(COLOR("brown"));

    lasso_band.setColor(COLOR("black"));
    draw_lasso_band();

} // End Lasso::initLasso()

void Lasso::yank() {
    bool paused = true, rtheta = true;
    reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
    lasso_loop.reset(lasso_start_x, lasso_start_y, LASSO_SIZE/2) ;
    lasso_loop.setFill(true);
    lasso_looped = false;
    if(the_coin != NULL) {
        num_coins++ ;
        the_coin->resetCoin() ;
        the_coin=NULL ;
    }
    if(the_greencoin != NULL) {
        num_greencoins++ ;
        the_greencoin->resetGreenCoin() ;
        the_greencoin=NULL ;
    }
    if(the_redcoin != NULL) {
        num_redcoins++ ;
        the_redcoin->resetRedCoin() ;
        the_redcoin=NULL ;
    }
    if(the_bluecoin != NULL) {
        num_bluecoins++ ;
        the_bluecoin->resetBlueCoin() ;
        the_bluecoin=NULL ;
    }
    if(the_bomb != NULL) {
        num_bombs++ ;
        the_bomb->resetBomb() ;
        the_bomb=NULL ;
    }
} // End Lasso::yank()

void Lasso::loopit() {
    if(lasso_looped) { return; } // Already looped
    lasso_loop.reset(getXPos(), getYPos(), LASSO_RADIUS);
    lasso_loop.setFill(false) ;
    lasso_looped = true;
} // End Lasso::loopit()

void Lasso::addAngle(double angle_deg) {
    release_angle_deg += angle_deg;
    if(release_angle_deg < MIN_RELEASE_ANGLE_DEG) { release_angle_deg = MIN_RELEASE_ANGLE_DEG; }
    if(release_angle_deg > MAX_RELEASE_ANGLE_DEG) { release_angle_deg = MAX_RELEASE_ANGLE_DEG; }
    bool paused = true, rtheta = true;
    reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addAngle()

void Lasso::addSpeed(double speed) {
    release_speed += speed;
    if(release_speed < MIN_RELEASE_SPEED) { release_speed = MIN_RELEASE_SPEED; }
    if(release_speed > MAX_RELEASE_SPEED) { release_speed = MAX_RELEASE_SPEED; }
    bool paused = true, rtheta = true;
    reset_all(lasso_start_x, lasso_start_y, release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
} // End Lasso::addSpeed()

void Lasso::nextStep(double stepTime) {
    draw_lasso_band();
    MovingObject::nextStep(stepTime);
    if(getYPos() > PLAY_Y_HEIGHT) { yank(); }
    lasso_line.reset(lasso_start_x, lasso_start_y, getXPos(), getYPos());
} // End Lasso::nextStep()

void Lasso::check_for_coin(Coin *coinPtr) {
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double coin_x = coinPtr->getXPos();
    double coin_y = coinPtr->getYPos(); 
    double xdiff = (lasso_x - coin_x);
    double ydiff = (lasso_y - coin_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= LASSO_RADIUS) {
        the_coin = coinPtr;
        the_coin->getAttachedTo(this);
    }
} // End Lasso::check_for_coin()

void Lasso::check_for_bomb(Bomb *bombPtr) {
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double bomb_x = bombPtr->getXPos();
    double bomb_y = bombPtr->getYPos();
    double xdiff = (lasso_x - bomb_x);
    double ydiff = (lasso_y - bomb_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= LASSO_RADIUS) {
        the_bomb = bombPtr;
        the_bomb->getAttachedTo(this);
    }
} // End Lasso::check_for_bomb()

void Lasso::check_for_greencoin(GreenCoin *greencoinPtr) {
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double greencoin_x = greencoinPtr->getXPos();
    double greencoin_y = greencoinPtr->getYPos();
    double xdiff = (lasso_x - greencoin_x);
    double ydiff = (lasso_y - greencoin_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= LASSO_RADIUS) {
        the_greencoin = greencoinPtr;
        the_greencoin->getAttachedTo(this);
    }
} // End Lasso::check_for_coin()

void Lasso::check_for_redcoin(RedCoin *redcoinPtr) {
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double redcoin_x = redcoinPtr->getXPos();
    double redcoin_y = redcoinPtr->getYPos();
    double xdiff = (lasso_x - redcoin_x);
    double ydiff = (lasso_y - redcoin_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= LASSO_RADIUS) {
        the_redcoin = redcoinPtr;
        the_redcoin->getAttachedTo(this);
    }
} // End Lasso::check_for_coin()

void Lasso::check_for_bluecoin(BlueCoin *bluecoinPtr) {
    double lasso_x = getXPos();
    double lasso_y = getYPos();
    double bluecoin_x = bluecoinPtr->getXPos();
    double bluecoin_y = bluecoinPtr->getYPos();
    double xdiff = (lasso_x - bluecoin_x);
    double ydiff = (lasso_y - bluecoin_y);
    double distance = sqrt((xdiff*xdiff)+(ydiff*ydiff));
    if(distance <= LASSO_RADIUS) {
        the_bluecoin = bluecoinPtr;
        the_bluecoin->getAttachedTo(this);
    }
} // End Lasso::check_for_coin()

