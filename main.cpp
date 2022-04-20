//BEFORE SUBMIT DELETE THE COOL SHIT

#include <iostream>                             // for standard input/output
using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

#include "Ball.h"

int main() {
    // display "Hello, World!" -- this still appears in our Run terminal as before
    cout << "Hello, World!" << endl;

    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window( VideoMode(1200, 800), "SFML Example Window" );

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************
    vector<Ball> mainBubble;
    Ball inputBub;
    int numBubs = 5;
    srand(time(0));
    rand();
    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame
                                                // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************
        for(int j = 0; j < mainBubble.size(); ++j){
            mainBubble.at(j).updatePosition();
            window.draw(mainBubble.at(j).bubGet());
        }
        //****************************************
        //  ADD ALL OF OUR DRAWING ABOVE HERE
        //****************************************

        window.display();                       // display the window

        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            if( event.type == Event::Closed ) { // if event type is a closed event
                                                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            }
            if(event.type == Event::MouseButtonPressed){
                Vector2<int> mousePos;
                mousePos = Mouse::getPosition(window);
                numBubs += 1;
                cout << numBubs << endl;
                inputBub.bubConstr();
                inputBub.spawnClick(mousePos);
                mainBubble.push_back(inputBub);
            }
            if(event.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::D)){
                if(numBubs != 0){
                    numBubs -= 1;
                    cout << numBubs << endl;
                    mainBubble.pop_back();
                }
            }
        }
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}