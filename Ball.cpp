//
// Created by Seth Krause on 12/1/21.
//

#include "Ball.h"
#include <iostream>
#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;
using namespace std;


void Ball::bubConstr() {
    bubShape.setRadius(rand() % 40 + 10);
    bubShape.setFillColor(Color(rand()%255, rand()%255, rand()%255));
    bubShape.setPosition(rand() % 300 + 100, rand() % 300 + 100);
    xDir = 0.0;
    yDir = 0.0 + (double)(rand()) / ((double)(RAND_MAX/(0.5 - 0.0)));
    dirVal = 1;
    i = 0;
}

CircleShape Ball::bubGet() {
    return bubShape;
}

void Ball::updatePosition(){
    updateTime();
    velocityCalc();
    Vector2f pos = bubShape.getPosition();
    if(pos.x < 0){
        xDir *= -1;
    }
    if(pos.x > 1200-2*(bubShape.getRadius())){
        xDir *= -1;
    }
    if(pos.y < 0){
        yDir *= -1;
    }
    if(pos.y > 800-2*(bubShape.getRadius())){
        if(i < 1){
            finalV = yVel;
            timeElap = 0;
            dirVal *= -1;
        }
        i += 1;
        if(i > 2){
            i = 0;
        }
    }

    bubShape.setPosition(pos.x += xDir, pos.y += yVel);
}

void Ball::spawnClick(Vector2<int> mousePos){
    double xCoord = mousePos.x;
    double yCoord = mousePos.y;
    bubShape.setPosition(xCoord - bubShape.getRadius(), yCoord - bubShape.getRadius());
}

void Ball::velocityCalc(){
    if(dirVal == 1){
        yVel = dirVal * (4.0*(timeElap*timeElap));
    }
    else{
        yVel = -finalV + (16.0*(timeElap*timeElap));
        if(yVel >= 0){
            timeElap = 0.06;
            dirVal = 1;
            finalV = 0;
        }
    }
}

void Ball::updateTime(){
    timeElap += 0.0001;
}



