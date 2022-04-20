
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Field.h"
#include "Field.cpp"
#include "SpriteHolder.h"
#include "SpriteHolder.cpp"
#include "GUI.h"
#include "GUI.cpp"
#include "Node.h"


using namespace std;
using namespace sf;

int main() {

    //create/set up window, GUI, Field objects
    RenderWindow window(sf::VideoMode(2350, 1500), "Autonomous Pathfinding");
    GUI gui;
    Field field;
    gui.spriteSetup(field);

    sf::RectangleShape background;
    background.setPosition(0,0);
    background.setFillColor(Color(130,130,130));
    background.setSize(sf::Vector2f(2350, 1500));

    //setup font
    Font font;
    if(!font.loadFromFile("P3 Images/nasalization-rg.otf")){
        cout << "ERROR loading file "<< endl;
    }

    Text text;
    Text dijKey;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                gui.pdf1ButtonClicked(window, field);
                gui.pdf2ButtonClicked(window, field);
                gui.pdf3ButtonClicked(window, field);
                gui.runButtonClicked(window, field);
                gui.clearButtonClicked(window, field);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                gui.rightClickObstacles(window, field, sf::Mouse::getPosition(window));
            }
            window.clear();
        }
            window.draw(background);
            gui.setInitialObstacles(field);
            gui.drawShapes(window);
            gui.drawButtons(window);
            gui.drawText(window, field, text, font);
            gui.drawKey(window, field, dijKey, font);
            window.draw(text);
            window.display();
        }
        SpriteHolder::Clear();
    }

