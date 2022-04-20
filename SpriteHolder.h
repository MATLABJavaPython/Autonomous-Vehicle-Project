//
// Created by Katie Murphy on 4/12/22.

//a map to hold all  images for the sprites
//
#pragma once
#include<map>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

using namespace std;
using namespace sf;

class SpriteHolder{

public:
   static map<string,Texture> images;

    static Texture &getImage(string textureName);
    static void loadImage(string fileName);
    static void Clear();
};
