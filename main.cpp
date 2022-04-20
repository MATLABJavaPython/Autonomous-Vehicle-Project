
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include <sstream>
#include "Field.h"
#include "Field.cpp"
#include "SpriteHolder.h"
#include "SpriteHolder.cpp"
#include "GUI.h"
#include "GUI.cpp"
#include "Node.h"
//#include "Node.cpp"

using namespace std;
using namespace sf;

int main() {
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

    cout<< "printing sizes of elements " << endl;
    cout << "predefined buttons x:" << gui.sprites["PDF1"].getTexture()->getSize().x * gui.sprites["PDF1"].getScale().x<< " y: " << gui.sprites["PDF1"].getTexture()->getSize().y * gui.sprites["PDF1"].getScale().y<< endl;
    cout << "run/enter buttons x:" << gui.sprites["clear"].getTexture()->getSize().x * gui.sprites["clear"].getScale().x<< " y: " << gui.sprites["clear"].getTexture()->getSize().y * gui.sprites["clear"].getScale().y<< endl;
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
            //window.draw(dijKey);
            window.display();
        }

        SpriteHolder::Clear();

    }
