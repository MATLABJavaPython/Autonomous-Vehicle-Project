//
// Created by Katie Murphy on 4/12/22.
//
#ifndef GUI_H
#define GUI_H
#pragma once
#include<map>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include <sstream>
#include "Node.h"
#include "Field.h"
//#include "Field.cpp"
using namespace std;
using namespace sf;
class GUI{

    public:
    GUI();
    map<string, Sprite> sprites;
    Node nodes[320][320];
    void spriteSetup(Field& field);
    void setInitialObstacles(Field& field);
    void drawNodes(RenderWindow& window);
    void drawShapes(RenderWindow &window);
    void setPaths(Field &field);

    void drawButtons(RenderWindow &window);

    void pdf1ButtonClicked(RenderWindow &window, Field& field);

    void pdf2ButtonClicked(RenderWindow &window, Field& field);

    void pdf3ButtonClicked(RenderWindow &window, Field& field);

    void runButtonClicked(RenderWindow &window, Field& field);

    void clearButtonClicked(RenderWindow &window, Field& field);

    void rightClickObstacles(RenderWindow &window, Field &field, Vector2i mousePosition);

    void clearEverything(Field &field);

    void drawText(RenderWindow &window, Field &field, Text& text, Font& font);

    void drawKey(RenderWindow &window, Field &field, Text &text, Font &font);
};

#endif