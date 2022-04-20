//
// Created by Katie Murphy on 4/12/22.
//

#include "SpriteHolder.h"

map<string, Texture> SpriteHolder::images;

void SpriteHolder::loadImage(string fileName){
    string path = "P3 Images/" + fileName + ".png";
    images[fileName].loadFromFile(path);

}

Texture& SpriteHolder::getImage(string textureName){
    if(images.find(textureName) == images.end()){
        loadImage(textureName);
    }

    return images[textureName];
}

void SpriteHolder::Clear(){
    images.clear();
}