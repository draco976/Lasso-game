//
//  tree.cpp
//  
//
//  Created by harshvardhan agarwal on 12/02/21.
//

#include <simplecpp>
#include "tree.h"

void draw(Turtle t,double d,int n,bool x,int &i) {
    if (n==0) {
        if(i%3==0) t.setColor(COLOR("red")) ;
        else if(i%3==1) t.setColor(COLOR("purple")) ;
        else  t.setColor(COLOR("blue")) ;
        if (x==1) t.imprint() ;
        i++ ;
        return ;
    }
    t.forward(0.6*d) ;
    t.left(5+3*n) ;
    draw(t,d*0.8,n-1,0,i) ;
    t.right(5+4*n) ;
    t.right(10+4*n) ;
    if(n==8) return ;
    draw(t,0.9*d,n-1,1,i) ;
    // t.left(45) ;
    // t.forward(-0.8*l) ;
}
