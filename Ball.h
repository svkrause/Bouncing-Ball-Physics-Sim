//
// Created by Seth Krause on 12/1/21.
//

#ifndef SFML_TEMPLATE_BALL_H
#define SFML_TEMPLATE_BALL_H
#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;

class Ball {
private:
    CircleShape bubShape;
    double xDir;
    double yDir;
    double timeElap;
    double yVel;
    double dirVal;
    double finalV;
    int i;
public:
    void updatePosition();
    void bubConstr();
    void spawnClick(Vector2<int> mousePos);
    CircleShape bubGet();
    void updateTime();
    void velocityCalc();
};


#endif //SFML_TEMPLATE_BALL_H
