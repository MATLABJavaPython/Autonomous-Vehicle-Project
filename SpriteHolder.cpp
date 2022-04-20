//
// Created by Katie Murphy on 4/12/22.
//

#include "SpriteHolder.h"

map<string, Texture> SpriteHolder::images;

//loads image from file
void SpriteHolder::loadImage(string fileName){
    string path = "P3 Images/" + fileName + ".png";
    images[fileName].loadFromFile(path);

}

//gets image
Texture& SpriteHolder::getImage(string textureName){
    if(images.find(textureName) == images.end()){
        loadImage(textureName);
    }

    return images[textureName];
}

//clears container
void SpriteHolder::Clear(){
    images.clear();
}