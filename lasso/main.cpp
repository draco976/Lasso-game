#include <simplecpp>
#include <string>
#include <bits/stdc++.h>
#include "MovingObject.h"
#include "lasso.h"
#include "coin.h"
#include "bluecoin.h"
#include "greencoin.h"
#include "redcoin.h"
#include "bomb.h"
#include "tree.h"

    //   s++ -o lasso lasso.cpp MovingObject.cpp coin.cpp bomb.cpp greencoin.cpp bluecoin.cpp redcoin.cpp tree.cpp main.cpp
    //   ./lasso

using namespace simplecpp;

main_program {
    initCanvas("Lasso", WINDOW_X, WINDOW_Y) ;
    
    int LEVEL=-20 ;
    
    // LEVEL=0 MAIN LOBBY
    // LEVEL=-1 VIEW INSTRUCTIONS
    // LEVEL=-2 VIEW CONTROLS
    // LEVEL=-3 LEADERBOARD
    // LEVEL=-10 GAME LOST WINDOW
    // LEVEL=-20 START WINDOW
    // LEVEL=1 STAGE 1
    
    int LIVES=5 ;
    int SCORE_VALUE=0 ;
    
    for(;;) {
        
        if(LEVEL==-20) {
            
            int i=0 ;
            
            //************************* START WINDOW *******************************
            
            // Draw BASE
            Rectangle BASE(WINDOW_X/2,WINDOW_Y,WINDOW_X,2*(WINDOW_Y-PLAY_Y_HEIGHT)) ;
            BASE.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            BASE.setFill(true) ;
            
            // TEXT GAME START
            Text LASSO_2D(WINDOW_X/2,OFFSET_SIZE/2,"LASSO 2D") ;
            LASSO_2D.setColor(COLOR("red")) ;
            LASSO_2D.setFill(true) ;
            
            Turtle tree ;
            tree.penUp() ;
            tree.setColor(COLOR("brown")) ;
            tree.left(90) ;
            tree.moveTo(WINDOW_X/2,PLAY_Y_HEIGHT) ;
            tree.penDown() ;
            draw(tree,150,8,1,i) ;
            
            wait(1) ;
            
            LEVEL=0 ;
            
        }
        
        if(LEVEL==-10) {
            
            //********************* GAME LOST WINDOW ************************
            
            // Draw BORDER
            Rectangle BORDER(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y) ;
            BORDER.setColor(COLOR("white")) ;
            BORDER.setFill(true) ;
            
            // COLOR BACKGROUND
            Rectangle BACKGROUND(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE) ;
            BACKGROUND.setColor(COLOR(138,3,3)) ;  // BLOOD RED COLOR CODE
            BACKGROUND.setFill(true) ;
            
            // TEXT GAME LOST
            Text GAME_LOST(WINDOW_X/2,WINDOW_Y/2,"YOU ARE DEAD") ;
            GAME_LOST.setColor(COLOR("white")) ;
            GAME_LOST.setFill(true) ;
            
            wait(3) ;
            LEVEL=0 ;
            LIVES=5 ;
        }
        
        else if(LEVEL==0) {
            
            //********************* MAIN LOBBY ************************
            
            
            // Draw BORDER
            Rectangle BORDER(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y) ;
            BORDER.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            BORDER.setFill(true) ;
            
            // COLOR BACKGROUND
            Rectangle BACKGROUND(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE) ;
            BACKGROUND.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            BACKGROUND.setFill(true) ;
            
            // START GAME
            Rectangle STARTGAME(WINDOW_X/2,WINDOW_Y/5,WINDOW_X,OPTION_SIZE) ;
            STARTGAME.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            STARTGAME.setFill(true) ;
            Text STARTGAME_text(WINDOW_X/2,WINDOW_Y/5,"START GAME (press 1)") ;
            STARTGAME_text.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            // VIEW INSTRUCTIONS
            Rectangle VIEWINSTRUCTIONS(WINDOW_X/2,2*WINDOW_Y/5,WINDOW_X,OPTION_SIZE) ;
            VIEWINSTRUCTIONS.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            VIEWINSTRUCTIONS.setFill(true) ;
            Text VIEWINSTRUCTIONS_text(WINDOW_X/2,2*WINDOW_Y/5,"INSTRUCTIONS (press 2)") ;
            VIEWINSTRUCTIONS_text.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            // VIEW CONTROLS
            Rectangle VIEWCONTROLS(WINDOW_X/2,3*WINDOW_Y/5,WINDOW_X,OPTION_SIZE) ;
            VIEWCONTROLS.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            VIEWCONTROLS.setFill(true) ;
            Text VIEWCONTROLS_text(WINDOW_X/2,3*WINDOW_Y/5,"CONTROLS (press 3)") ;
            VIEWCONTROLS_text.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            // LEADERBOARD
            Rectangle LEADERBOARD(WINDOW_X/2,4*WINDOW_Y/5,WINDOW_X,OPTION_SIZE) ;
            LEADERBOARD.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            LEADERBOARD.setFill(true) ;
            Text LEADERBOARD_text(WINDOW_X/2,4*WINDOW_Y/5,"LEADERBOARD (press 4)") ;
            LEADERBOARD_text.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE

            XEvent e ;
            bool pendingEv = checkEvent(e);
            while(!pendingEv) {
                pendingEv = checkEvent(e) ;
            }
            if(pendingEv) {
                char c = charFromEvent(e);
                switch(c) {
                    case '1':
                        LEVEL=1 ;
                        break;
                    case '2':
                        LEVEL=-1 ;
                        break;
                    case '3':
                        LEVEL=-2 ;
                        break ;
                    case '4':
                        LEVEL=-3 ;
                        break ;
                    case 'q':
                        exit(0) ;
                        break ;
                    default:
                        break;
                }
            }
        }
        
        else if(LEVEL==-1) {
            
            // ************************ VIEW INSTRUCTIONS **************************
            
            // DRAW BORDER
            Rectangle BORDER(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y) ;
            BORDER.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            BORDER.setFill(true) ;
            
            // COLOR BACKGROUND
            Rectangle BACKGROUND(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE) ;
            BACKGROUND.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            BACKGROUND.setFill(true) ;
            
            // DRAW LIST
            Rectangle LIST(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-2*OFFSET_SIZE,WINDOW_Y-OFFSET_SIZE/2) ;
            LIST.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            LIST.setFill(true) ;
            
            // HEADING
            Text INSTRUCTIONS_NAME(WINDOW_X/2,0.8*OFFSET_SIZE,"INSTRUCTIONS") ;
            INSTRUCTIONS_NAME.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            // INSTRUCTIONS
            Text GOLD_COIN(WINDOW_X/2,2*OFFSET_SIZE-OFFSET_SIZE/3,"COIN : score increase by 1") ;
            GOLD_COIN.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text BLUE_COIN(WINDOW_X/2,2.7*OFFSET_SIZE-OFFSET_SIZE/3,"SAPPHIRE : score increase by 3") ;
            BLUE_COIN.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text RED_COIN(WINDOW_X/2,3.4*OFFSET_SIZE-OFFSET_SIZE/3,"ELIXIR : increase speed of lasso") ;
            RED_COIN.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text GREEN_COIN(WINDOW_X/2,4.1*OFFSET_SIZE-OFFSET_SIZE/3,"ROYAL JELLY : lives increase by 1") ;
            GREEN_COIN.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text BOMB(WINDOW_X/2,4.9*OFFSET_SIZE-OFFSET_SIZE/3,"BOMB : decrease lives by 1") ;
            BOMB.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text BOMB1(WINDOW_X/2,4.9*OFFSET_SIZE,"(catch before it reaches ground)") ;
            BOMB1.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            Circle GOLD_COIN_(1.5*OFFSET_SIZE,2*OFFSET_SIZE-OFFSET_SIZE/3,COIN_SIZE) ;
            GOLD_COIN_.setColor(COLOR("gold")) ;
            GOLD_COIN_.setFill(true) ;
            Circle BLUE_COIN_(1.5*OFFSET_SIZE,2.7*OFFSET_SIZE-OFFSET_SIZE/3,BLUECOIN_SIZE) ;
            BLUE_COIN_.setColor(COLOR(0,64,255));  // BLUE COLOR CODE
            BLUE_COIN_.setFill(true) ;
            Circle RED_COIN_(1.5*OFFSET_SIZE,3.4*OFFSET_SIZE-OFFSET_SIZE/3,REDCOIN_SIZE) ;
            RED_COIN_.setColor(COLOR("red")) ;
            RED_COIN_.setFill(true) ;
            Circle GREEN_COIN_(1.5*OFFSET_SIZE,4.1*OFFSET_SIZE-OFFSET_SIZE/3,GREENCOIN_SIZE) ;
            GREEN_COIN_.setColor(COLOR("green")) ;
            GREEN_COIN_.setFill(true) ;
            Circle BOMB_(1.5*OFFSET_SIZE,4.9*OFFSET_SIZE-OFFSET_SIZE/3,BOMB_SIZE) ;
            BOMB_.setColor(COLOR("black")) ;
            BOMB_.setFill(true) ;
            
            XEvent e ;
            bool pendingEv = checkEvent(e);
            while(!pendingEv) {
                pendingEv = checkEvent(e) ;
            }
            if(pendingEv) {
                char c = charFromEvent(e);
                switch(c) {
                    case 'm':
                        LEVEL=0 ;
                        break;
                    case 'q':
                        exit(0) ;
                        break ;
                    default:
                        break;
                }
            }
            
        }
        
        else if(LEVEL==-2) {
            
            // ******************************** VIEW CONTROLS *************************************
            
            // DRAW BORDER
            Rectangle BORDER(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y) ;
            BORDER.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            BORDER.setFill(true) ;
            
            // COLOR BACKGROUND
            Rectangle BACKGROUND(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE) ;
            BACKGROUND.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            BACKGROUND.setFill(true) ;
            
            // DRAW LIST
            Rectangle LIST(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-2*OFFSET_SIZE,WINDOW_Y-OFFSET_SIZE/2) ;
            LIST.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            LIST.setFill(true) ;
            
            // HEADING
            Text CONTROLS_NAME(WINDOW_X/2,0.7*OFFSET_SIZE,"CONTROLS") ;
            CONTROLS_NAME.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            // CONTROLS
            Text LASSO_THROW(WINDOW_X/2,OFFSET_SIZE*1.8-OFFSET_SIZE/3,"a : throw lasso") ;
            LASSO_THROW.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LASSO_LOOP(WINDOW_X/2,OFFSET_SIZE*2.4-OFFSET_SIZE/3,"d : loop lasso") ;
            LASSO_LOOP.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LASSO_YANK(WINDOW_X/2,OFFSET_SIZE*3.0-OFFSET_SIZE/3,"s : yank lasso") ;
            LASSO_YANK.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LASSO_INCREASE_ANGLE(WINDOW_X/2,OFFSET_SIZE*3.6-OFFSET_SIZE/3,"l : increase angle") ;
            LASSO_INCREASE_ANGLE.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LASSO_DECREASE_ANGLE(WINDOW_X/2,OFFSET_SIZE*4.2-OFFSET_SIZE/3,"k : decrease angle") ;
            LASSO_DECREASE_ANGLE.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text MAIN_MENU(WINDOW_X/2,OFFSET_SIZE*4.8-OFFSET_SIZE/3,"m : open main lobby") ;
            MAIN_MENU.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text QUIT_GAME(WINDOW_X/2,OFFSET_SIZE*5.4-OFFSET_SIZE/3,"q : quit game") ;
            QUIT_GAME.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            XEvent e ;
            bool pendingEv = checkEvent(e);
            while(!pendingEv) {
                pendingEv = checkEvent(e) ;
            }
            if(pendingEv) {
                char c = charFromEvent(e);
                switch(c) {
                    case 'm':
                        LEVEL=0 ;
                        break;
                    case 'q':
                        exit(0) ;
                        break ;
                    default:
                        break;
                }
            }
        }
        
        else if(LEVEL==-3) {
            
            // ************************ VIEW LEADERBOARD **************************
            
            // DRAW BORDER
            Rectangle BORDER(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y) ;
            BORDER.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            BORDER.setFill(true) ;
            
            // COLOR BACKGROUND
            Rectangle BACKGROUND(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE) ;
            BACKGROUND.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            BACKGROUND.setFill(true) ;
            
            // DRAW LIST
            Rectangle LIST(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-2*OFFSET_SIZE,WINDOW_Y-OFFSET_SIZE/2) ;
            LIST.setColor(COLOR(49,29,0)) ;  // BROWN COLOR CODE
            LIST.setFill(true) ;
            
            // HEADING
            Text LEADERBOARD_NAME(WINDOW_X/2,1*OFFSET_SIZE,"LEADERBOARD") ;
            LEADERBOARD_NAME.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            // LEADERBOARD
            ifstream infile ;
            infile.open("leaderboard.txt");
            string name ;
            int score ;
            
            infile >> name >> score ;
            Text LEADERBOARD_NAME1(WINDOW_X/2,2*OFFSET_SIZE,name) ;
            LEADERBOARD_NAME1.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LEADERBOARD_SCORE1(WINDOW_X-2*OFFSET_SIZE,2*OFFSET_SIZE,score) ;
            LEADERBOARD_SCORE1.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            infile >> name >> score ;
            Text LEADERBOARD_NAME2(WINDOW_X/2,2.7*OFFSET_SIZE,name) ;
            LEADERBOARD_NAME2.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LEADERBOARD_SCORE2(WINDOW_X-2*OFFSET_SIZE,2.7*OFFSET_SIZE,score) ;
            LEADERBOARD_SCORE2.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            infile >> name >> score ;
            Text LEADERBOARD_NAME3(WINDOW_X/2,3.4*OFFSET_SIZE,name) ;
            LEADERBOARD_NAME3.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LEADERBOARD_SCORE3(WINDOW_X-2*OFFSET_SIZE,3.4*OFFSET_SIZE,score) ;
            LEADERBOARD_SCORE3.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            infile >> name >> score ;
            Text LEADERBOARD_NAME4(WINDOW_X/2,4.1*OFFSET_SIZE,name) ;
            LEADERBOARD_NAME4.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LEADERBOARD_SCORE4(WINDOW_X-2*OFFSET_SIZE,4.1*OFFSET_SIZE,score) ;
            LEADERBOARD_SCORE4.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            infile >> name >> score ;
            Text LEADERBOARD_NAME5(WINDOW_X/2,4.8*OFFSET_SIZE,name) ;
            LEADERBOARD_NAME5.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            Text LEADERBOARD_SCORE5(WINDOW_X-2*OFFSET_SIZE,4.8*OFFSET_SIZE,score) ;
            LEADERBOARD_SCORE5.setColor(COLOR(249,229,188)) ;  // CREAM COLOR CODE
            
            XEvent e ;
            bool pendingEv = checkEvent(e) ;
            while(!pendingEv) {
                pendingEv = checkEvent(e) ;
            }
            if(pendingEv) {
                char c = charFromEvent(e);
                switch(c) {
                    case 'm':
                        LEVEL=0 ;
                        break;
                    case 'q':
                        exit(0) ;
                        break ;
                    default:
                        break;
                }
            }
        }
        
        else if (LEVEL==1) {
            
            // ******************************** STAGE 1 *************************************
            
            // Draw BORDER
            Rectangle BORDER(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y) ;
            BORDER.setColor(COLOR(2,7,93)) ; // DARK BLUE COLOR CODE
            BORDER.setFill(true) ;
            
            // COLOR BACKGROUND
            Rectangle BACKGROUND(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE) ;
            BACKGROUND.setColor(COLOR(0,204,255)) ; // SKY BLUE COLOR CODE
            BACKGROUND.setFill(true) ;
            
            // DRAW BOTTOM GROUND
            Rectangle BOTTOMGROUND(WINDOW_X/2,(WINDOW_Y-BORDER_SIZE/2+PLAY_Y_HEIGHT)/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE/2-PLAY_Y_HEIGHT) ;
            BOTTOMGROUND.setColor(COLOR(11,102,35)) ;
            BOTTOMGROUND.setFill(true) ;
            
            // SHOW LIVES
//            Text SHOW_LIVES(LIFE_X_POSITION,LIFE_Y_POSITION,"LIVES") ;
            
            LIVES=5 ;
            
            int stepCount = 0;
            float stepTime = STEP_TIME;
            float runTime = 180 ; // sec; -ve means infinite
            float currTime = 0;

            // Draw lasso at start position
            double release_speed = INIT_RELEASE_SPEED; // m/s
            double release_angle_deg = INIT_RELEASE_ANGLE_DEG; // degrees
            double lasso_ax = 0;
            double lasso_ay = LASSO_G;
            bool paused = true;
            bool rtheta = true;
            Lasso lasso(release_speed, release_angle_deg, lasso_ax, lasso_ay, paused, rtheta);
            
//            CODE REMOVED FROM ORIGINAL MAIN.CPP
//            Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
//            b1.setColor(COLOR("blue"));
//            Line b2(PLAY_X_START, 0, PLAY_X_START, WINDOW_Y);
//            b2.setColor(COLOR("blue"));

//            string msg("Cmd: _");
//            Text charPressed(PLAY_X_START+50, PLAY_Y_HEIGHT+20, msg) ;
            char coinScoreStr[256] ;
            sprintf(coinScoreStr, "SCORE: %d", lasso.getNumCoins()) ;
            Text coinScore(PLAY_X_START+50, PLAY_Y_HEIGHT+70, coinScoreStr) ;
            
            char livesStr[256] ;
            sprintf(livesStr, "LIVES: %d", LIVES) ;
            Text livesScore(PLAY_X_START+50, PLAY_Y_HEIGHT+40, livesStr) ;

            paused = true; rtheta = true;
            double coin_speed = COIN_SPEED;
            double coin_angle_deg = COIN_ANGLE_DEG;
            double coin_ax = 0;
            double coin_ay = COIN_G;
            Coin coin(coin_speed, coin_angle_deg, coin_ax, coin_ay, paused, rtheta);
            
            double greencoin_speed = GREENCOIN_SPEED;
            double greencoin_angle_deg = GREENCOIN_ANGLE_DEG;
            double greencoin_ax = 0;
            double greencoin_ay = GREENCOIN_G;
            GreenCoin greencoin(greencoin_speed, greencoin_angle_deg, greencoin_ax, greencoin_ay, paused, rtheta);
            
            double redcoin_speed = REDCOIN_SPEED;
            double redcoin_angle_deg = REDCOIN_ANGLE_DEG;
            double redcoin_ax = 3.5*REDCOIN_G;
            double redcoin_ay = REDCOIN_G;
            RedCoin redcoin(redcoin_speed, redcoin_angle_deg, redcoin_ax, redcoin_ay, paused, rtheta);
            
            double bluecoin_speed = BLUECOIN_SPEED;
            double bluecoin_angle_deg = BLUECOIN_ANGLE_DEG;
            double bluecoin_ax = -BLUECOIN_G;
            double bluecoin_ay = 0 ;
            BlueCoin bluecoin(bluecoin_speed, bluecoin_angle_deg, bluecoin_ax, bluecoin_ay, paused, rtheta);
            
            double bomb_speed = 0 ;
            double bomb_angle_deg = BOMB_ANGLE_DEG ;
            double bomb_ax = 0;
            double bomb_ay = BOMB_G ;
            Bomb bomb(bomb_speed, bomb_angle_deg, bomb_ax, bomb_ay, paused, rtheta);
            
            int count_bombs=0 ;
            int count_greencoins=0 ;
            int count_bluecoins=0 ;
            int count_redcoins=0 ;
            
            

            // After every COIN_GAP sec, make the coin jump
            double last_coin_jump_end = 0;
            double last_bomb_jump_end = 0;
            double last_greencoin_jump_end = 0;
            double last_redcoin_jump_end = 0;
            double last_bluecoin_jump_end = 0;

            // When t is pressed, throw lasso
            // If lasso within range, make coin stick
            // When y is pressed, yank lasso
            // When l is pressed, loop lasso
            // When q is pressed, quit

            for(;;) {
                if((runTime > 0) && (currTime > runTime)) {
                    LEVEL=2 ;
                    SCORE_VALUE=lasso.getNumCoins()+3*lasso.getNumBlueCoins() ;
                    break ;
                }
                
                // TIME DISPLAY
                string REMAINING_TIME ;
                REMAINING_TIME[0]='T' ;
                REMAINING_TIME[1]='I' ;
                REMAINING_TIME[2]='M' ;
                REMAINING_TIME[3]='E' ;
                REMAINING_TIME[4]=' ' ;
                REMAINING_TIME[5]=((int)runTime-(int)currTime)/60+'0' ;
                REMAINING_TIME[6]=':' ;
                REMAINING_TIME[7]=(((int)runTime-(int)currTime)%60)/10+'0' ;
                REMAINING_TIME[8]=(((int)runTime-(int)currTime)%60)%10+'0' ;
                Text TIME_DISPLAY(WINDOW_X-1.5*OFFSET_SIZE,OFFSET_SIZE/2,REMAINING_TIME) ;
                
                
                XEvent e;
                bool pendingEv = checkEvent(e);
                bool go_to_menu=0 ;
                if(pendingEv) {
                    char c = charFromEvent(e);
//                    msg[msg.length()-1] = c;
//                    charPressed.setMessage(msg);
                    switch(c) {
                        case 'a':
                            lasso.unpause();
                            break;
                        case 's':
                            lasso.yank();
                            break;
                        case 'd':
                            lasso.loopit();
                            lasso.check_for_coin(&coin);
                            lasso.check_for_bomb(&bomb);
                            lasso.check_for_greencoin(&greencoin);
                            lasso.check_for_redcoin(&redcoin);
                            lasso.check_for_bluecoin(&bluecoin);
//                            wait(STEP_TIME*5);
                            break;
                        case 'k':
                            if(lasso.isPaused()) { lasso.addAngle(-RELEASE_ANGLE_STEP_DEG);    }
                            break;
                        case 'l':
                            if(lasso.isPaused()) { lasso.addAngle(+RELEASE_ANGLE_STEP_DEG); }
                            break;
//                        case '-':
//                            if(lasso.isPaused()) { lasso.addSpeed(-RELEASE_SPEED_STEP); }
//                            break;
//                        case '=':
//                            if(lasso.isPaused()) { lasso.addSpeed(+RELEASE_SPEED_STEP); }
//                            break;
                        case 'm':
                            LEVEL=0 ;
                            go_to_menu=1 ;
                            break ;
                        case 'q':
                            exit(0);
                        default:
                            break;
                    }
                }
                if(go_to_menu==1) break ;

                lasso.nextStep(stepTime);

                coin.nextStep(stepTime);
                if(coin.isPaused()) {
                    if((currTime-last_coin_jump_end) >= COIN_GAP) {
                        coin.unpause();
                    }
                }
                
                if(lasso.getNumGreenCoins()-count_greencoins>0) {
                    LIVES++ ;
                    count_greencoins=lasso.getNumGreenCoins() ;
                    last_greencoin_jump_end=currTime ;
                }
                
                greencoin.nextStep(stepTime);
                if(greencoin.isPaused()) {
                    if((currTime-last_greencoin_jump_end) >= GREENCOIN_GAP) {
                        greencoin.unpause();
                    }
                }
                
                if(lasso.getNumRedCoins()-count_redcoins>0) {
                    lasso.addSpeed(+RELEASE_SPEED_STEP);
                    count_redcoins=lasso.getNumRedCoins() ;
                    last_redcoin_jump_end=currTime ;
                }
                
                redcoin.nextStep(stepTime);
                if(redcoin.isPaused()) {
                    if((currTime-last_redcoin_jump_end) >= REDCOIN_GAP) {
                        redcoin.unpause();
                    }
                }
                
                if(lasso.getNumBlueCoins()-count_bluecoins>0) {
                    count_bluecoins=lasso.getNumBlueCoins() ;
                    last_bluecoin_jump_end=currTime ;
                }
                
                bluecoin.nextStep(stepTime);
                if(bluecoin.isPaused()) {
                    if((currTime-last_bluecoin_jump_end) >= BLUECOIN_GAP) {
                        bluecoin.unpause();
                    }
                }
                
                if(lasso.getNumBombs()-count_bombs) {
                    count_bombs=lasso.getNumBombs() ;
                    last_bomb_jump_end=currTime ;
                }
                
                bomb.nextStep(stepTime);
                if(bomb.isPaused()) {
                    if((currTime-last_bomb_jump_end) >= BOMB_GAP) {
                        bomb.unpause();
                    }
                }

                if(coin.getYPos() > PLAY_Y_HEIGHT) {
                    coin.resetCoin();
                    last_coin_jump_end = currTime;
                }
                
                if(greencoin.getYPos() > PLAY_Y_HEIGHT) {
                    greencoin.resetGreenCoin();
                    last_greencoin_jump_end = currTime;
                }
                
                if(bluecoin.getYPos() > PLAY_Y_HEIGHT) {
                    bluecoin.resetBlueCoin();
                    last_bluecoin_jump_end = currTime;
                }
                
                if(redcoin.getYPos() > PLAY_Y_HEIGHT) {
                    redcoin.resetRedCoin();
                    last_redcoin_jump_end = currTime;
                }
                
                if(bomb.getYPos() > PLAY_Y_HEIGHT) {
                    bomb.resetBomb() ;
                    LIVES-- ;
                    last_bomb_jump_end = currTime;
                }
                
                if(LIVES==0) {
                    LEVEL=-10 ;
                    break ;
                }

                sprintf(coinScoreStr, "SCORE: %d", lasso.getNumCoins()+3*lasso.getNumBlueCoins());
                coinScore.setMessage(coinScoreStr);
                sprintf(livesStr, "LIVES: %d", LIVES);
                livesScore.setMessage(livesStr);

                stepCount++;
                currTime += stepTime;
                wait(stepTime);
            }
            
            wait(3) ;

        }
        
        else if (LEVEL==2) {
            //********************* GAME WON WINDOW ************************
            
            // Draw BORDER
            Rectangle BORDER(WINDOW_X/2,WINDOW_Y/2,WINDOW_X,WINDOW_Y) ;
            BORDER.setColor(COLOR("white")) ;
            BORDER.setFill(true) ;
            
            // COLOR BACKGROUND
            Rectangle BACKGROUND(WINDOW_X/2,WINDOW_Y/2,WINDOW_X-BORDER_SIZE,WINDOW_Y-BORDER_SIZE) ;
            BACKGROUND.setColor(COLOR(138,3,3)) ;  // BLOOD RED COLOR CODE
            BACKGROUND.setFill(true) ;
            
            // TEXT GAME WON
            Text GAME_WON(WINDOW_X/2,WINDOW_Y/2-OFFSET_SIZE,"CONGRATULATIONS") ;
            GAME_WON.setColor(COLOR("white")) ;
            GAME_WON.setFill(true) ;
            
            // DISPLAY SCORE
            Text YOUR_SCORE(WINDOW_X/2,WINDOW_Y/2,"Your Score : ") ;
            YOUR_SCORE.setColor(COLOR("white")) ;
            YOUR_SCORE.setFill(true) ;
            
            Text YOUR_SCORE1(WINDOW_X/2+5*OFFSET_SIZE/6,WINDOW_Y/2,SCORE_VALUE) ;
            YOUR_SCORE1.setColor(COLOR("white")) ;
            YOUR_SCORE1.setFill(true) ;
            
            ifstream infile ;
            infile.open("leaderboard.txt");
            string name[5] ;
            int score[5] ;
            for(int i=0;i<5;i++) {
                infile >> name[i] >> score[i] ;
            }
            
            bool SHOW_LEADERBOARD=1 ; // to show leaderboard if score if in top 5
            
            Text YOUR_POS(WINDOW_X/2,WINDOW_Y/2+OFFSET_SIZE,"1st position") ;
            YOUR_POS.setColor(COLOR("white")) ;
            
            if(SCORE_VALUE>score[0]) {
                YOUR_POS.setMessage("1st position") ;
            }
            else if(SCORE_VALUE>score[1]) {
                YOUR_POS.setMessage("2nd position") ;
            }
            else if(SCORE_VALUE>score[2]) {
                YOUR_POS.setMessage("3rd position") ;
            }
            else if(SCORE_VALUE>score[3]) {
                YOUR_POS.setMessage("4th position") ;
            }
            else if(SCORE_VALUE>score[4]) {
                YOUR_POS.setMessage("5th position") ;
            }
            else {
                YOUR_POS.setMessage("NO position") ;
                SHOW_LEADERBOARD=0 ;
            }
            
            Text YOUR_NAME(WINDOW_X/2,WINDOW_Y/2+2*OFFSET_SIZE,"Type your First Name") ;
            YOUR_NAME.setColor(COLOR("white")) ;
            Text YOUR_NAME1(WINDOW_X/2,WINDOW_Y/2+2.6*OFFSET_SIZE,"(Start and End your name with '0')") ;
            YOUR_NAME1.setColor(COLOR("white")) ;
            
            string NAME_INPUT ;
            while(true) {
                XEvent e ;
                bool name_start=false ;
                bool pendingEv = checkEvent(e);
                while(!pendingEv) {
                    pendingEv = checkEvent(e) ;
                }
                if(pendingEv) {
                    char c = charFromEvent(e);
                    if(c=='0') {
                        name_start=true ;
                        break ;
                    }
                }
                if(name_start) break ;
            }
            
            while(true) {
                XEvent e ;
                bool name_end=0 ;
                bool pendingEv = checkEvent(e);
                while(!pendingEv) {
                    pendingEv = checkEvent(e) ;
                }
                if(pendingEv) {
                    char c = charFromEvent(e);
                    if(c=='0') {
                        name_end=1 ;
                        break ;
                    }
                    else {
                        NAME_INPUT=NAME_INPUT+c ;
                    }
                }
                if(name_end) break ;
            }
            
            ofstream outfile ;
            outfile.open("leaderboard.txt", ios::out | ios::trunc );
            
            int count=0 ;
            bool YOUR_SCORE_ADDED=false ;
            for(int i=0;i<5 && count<5 ;i++) {
                count ++ ;
                if(SCORE_VALUE>score[i] && !YOUR_SCORE_ADDED) {
                    outfile << NAME_INPUT << " " << SCORE_VALUE << endl ;
                    i-- ;
                    YOUR_SCORE_ADDED=true ;
                }
                else {
                    outfile << name[i] << " " << score[i] << endl ;
                }
            }
            
            if(SHOW_LEADERBOARD) LEVEL=-3 ;
            else LEVEL=0 ;
        }
        
    } // End for(;;)

    
    wait(3);
} // End main_program
