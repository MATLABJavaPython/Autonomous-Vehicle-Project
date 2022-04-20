//
// Created by Katie Murphy on 4/12/22.
//
#include "GUI.h"
#include "SpriteHolder.h"

//adds all sprites to the map that contains the images for the sprites
void GUI::spriteSetup(Field& field){
    //tiles
    Sprite floorTile(SpriteHolder::getImage("floorTile"));
    sprites.emplace("floorTile", floorTile);
    Sprite obstacleTile(SpriteHolder::getImage("obstacleTile"));
    sprites.emplace("obstacleTile", obstacleTile);

    //to and from icons
    Sprite robotStart(SpriteHolder::getImage("RobotStart"));
    robotStart.setScale(0.3, 0.3);
    robotStart.setPosition(field.from.second*4-60, field.from.first*4-80);
    sprites.emplace("robotStart", robotStart);

    Sprite target(SpriteHolder::getImage("target"));
    target.setPosition(field.to.second*4-45, field.to.first*4-45);
    sprites.emplace("target", target);

    //buttons
    Sprite PDF1(SpriteHolder::getImage("PDF1"));
    PDF1.setScale(0.25, 0.25);
    PDF1.scale(1.91, 1.91);
    PDF1.setPosition(1350, 70);
    sprites.emplace("PDF1", PDF1);

    Sprite PDF2(SpriteHolder::getImage("PDF2"));
    PDF2.setPosition(1683, 70);
    PDF2.setScale(0.25, 0.25);
    PDF2.scale(1.91, 1.91);
    sprites.emplace("PDF2", PDF2);

    Sprite PDF3(SpriteHolder::getImage("PDF3"));
    PDF3.setPosition(2016, 70);
    PDF3.setScale(0.25, 0.25);
    PDF3.scale(1.91, 1.91);
    sprites.emplace("PDF3", PDF3);

    Sprite clear(SpriteHolder::getImage("clear"));
    clear.setPosition(1350, 1109);
    clear.setScale(0.25, 0.25);
    clear.scale(2.88, 2);
    sprites.emplace("clear", clear);

    Sprite Run(SpriteHolder::getImage("Run"));
    Run.setPosition(1350, 867);
    Run.setScale(0.25, 0.25);
    Run.scale(2.88, 2);
    sprites.emplace("Run", Run);
}

//adds the obstacles into the field to display them at the specified x,y locations by setting Node.obstacle = true
void GUI::setInitialObstacles(Field& field){
    for(int i=0; i < field.obstacles.size(); i++){
        for(int n = 0; n < field.obstacles[i].size(); n++){
            nodes[field.obstacles[i][n].first][field.obstacles[i][n].second].obst = true;
        }
    }
}

//inserts the paths (updates booleans)
void GUI::setPaths(Field& field){
    //set dijkstra's path
    for(int i=0; i < field.dijkPath.size(); i++){
            nodes[field.dijkPath[i].first][field.dijkPath[i].second].dij = true;
    }
    //set breadth path
    for(int i=0; i < field.breadthPath.size(); i++){
        nodes[field.breadthPath[i].first][field.breadthPath[i].second].bfs = true;
    }

    for(int i=0; i < field.depthPathMaybeLaterlol.size(); i++){
        nodes[field.depthPathMaybeLaterlol[i].first][field.depthPathMaybeLaterlol[i].second].dfs = true;
    }
}

////DRAWING GUI////
//tests drawing background
void GUI::drawShapes(RenderWindow& window){
    for(int i = 0; i < 320; i++){
        for(int j = 0; j < 320; j++){
            sf::RectangleShape tile;
            tile.setSize(sf::Vector2f(4, 4));

            if(nodes[i][j].obst){
                tile.setFillColor(Color(0,0,0));
            }else if(nodes[i][j].dij && nodes[i][j].bfs || nodes[i][j].dij && nodes[i][j].dfs || nodes[i][j].bfs && nodes[i][j].dfs){
                tile.setFillColor(Color(128,0,128));
            }else if(nodes[i][j].dij){
                tile.setFillColor(Color(255,0,0));
            }else if(nodes[i][j].bfs) {
                tile.setFillColor(Color(0, 0, 255));
            }else if(nodes[i][j].dfs){
                tile.setFillColor(Color(0, 255, 0));
            }
            tile.setPosition(j*4, i*4);
            window.draw(tile);
        }
    }
}

//draws buttons in window
void GUI::drawButtons(RenderWindow& window){
    Sprite button = sprites["PDF1"];
    window.draw(button);

    button = sprites["PDF2"];
    window.draw(button);

    button = sprites["PDF3"];
    window.draw(button);

    button = sprites["Run"];
    window.draw(button);

    button = sprites["clear"];
    window.draw(button);

    //to and from icons
   button = sprites["robotStart"];
    window.draw(button);

    button = sprites["target"];
    window.draw(button);
}

void GUI::drawKey(RenderWindow& window, Field& field, Text& text, Font& font){
    sf::RectangleShape dijKey;
    dijKey.setFillColor(Color(255,0,0));
    dijKey.setSize(sf::Vector2f(80, 80));
    dijKey.setPosition(40, 1280);
    window.draw(dijKey);

    Text text2;
    text2.setFont(font);
    text2.setString("= Dijkstra's \n Algorithm");
    text2.setPosition(130, 1300);
    text2.setColor(Color(255, 255, 255));
    text2.setCharacterSize(20);
    window.draw(text2);

    //BFS Key
    sf::RectangleShape bfs;
    bfs.setFillColor(Color(0, 0, 255));
    bfs.setSize(sf::Vector2f(80, 80));
    bfs.setPosition(260, 1280);
    window.draw(bfs);

    Text text3;
    text3.setFont(font);
    text3.setString("= BFS \n Algorithm");
    text3.setPosition(350, 1300);
    text3.setColor(Color(255, 255, 255));
    text3.setCharacterSize(20);
    window.draw(text3);

    //DFS Key
    sf::RectangleShape dfs;
    dfs.setFillColor(Color(0, 255, 0));
    dfs.setSize(sf::Vector2f(80, 80));
    dfs.setPosition(480, 1280);
    window.draw(dfs);

    Text text4;
    text4.setFont(font);
    text4.setString("= DFS \n Algorithm");
    text4.setPosition(570, 1300);
    text4.setColor(Color(255, 255, 255));
    text4.setCharacterSize(20);
    window.draw(text4);

    //Overlap Key
    sf::RectangleShape overlap;
    overlap.setFillColor(Color(128, 0, 128));
    overlap.setSize(sf::Vector2f(80, 80));
    overlap.setPosition(700, 1280);
    window.draw(overlap);

    Text text5;
    text5.setFont(font);
    text5.setString("= Overlap");
    text5.setPosition(790, 1300);
    text5.setColor(Color(255, 255, 255));
    text5.setCharacterSize(20);
    window.draw(text5);

}

void GUI::drawText(RenderWindow& window, Field& field, Text& text, Font& font){
    text.setFont(font);
    string display = "test";
    text.setString("Dijkstra's Algorithm: \n"
                   "    Time taken: " + to_string(field.dijkTime) +" microseconds" + "\n" +
  "    Length of Path: " + to_string(field.dijkLength)+ " \n" + "Breadth First Search: \n" +
  "    Time taken: " + to_string(field.breadthTime) + " microseconds \n" + "    Length of Path: " + to_string(field.breadthLength) +
  "\n" + "Depth First Search: \n" + "    Time taken: " + to_string(field.depthTime) + " microseconds " + "\n"
   "    Length of Path: " + to_string(field.depthLength));
    text.setCharacterSize(45);
    text.setPosition(1350, 310);
    text.setColor(Color::White);


}

////managing GUI events
void GUI::pdf1ButtonClicked(RenderWindow& window, Field& field){
    string spriteTo = "PDF1";
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
   {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::FloatRect bounds = sprites[spriteTo].getGlobalBounds();
        if (bounds.contains(mouse))
        {
            clearEverything(field);
            cout << "first button clicked!" << endl;
            field.LoadPDF1();
        }
    }
}
void GUI::pdf2ButtonClicked(RenderWindow& window, Field& field){
    string spriteToAccess = "PDF2";
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::FloatRect bounds = sprites[spriteToAccess].getGlobalBounds();
        if (bounds.contains(mouse))
        {
            clearEverything(field);
            cout << "second button clicked!" << endl;
            field.LoadPDF2();

        }
    }
}
void GUI::pdf3ButtonClicked(RenderWindow& window, Field& field){
    string spriteToAccess = "PDF3";
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::FloatRect bounds = sprites[spriteToAccess].getGlobalBounds();
        if (bounds.contains(mouse))
        {
            clearEverything(field);
            cout << "third button clicked!" << endl;
            field.LoadPDF3();

        }
    }
}
void GUI::runButtonClicked(RenderWindow& window, Field& field){
    string spriteToAccess = "Run";
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::FloatRect bounds = sprites[spriteToAccess].getGlobalBounds();
        if (bounds.contains(mouse))
        {
            cout << "Run button clicked!" << endl;

            //field.FindPaths();
            setInitialObstacles(field);
            field.FindPaths();
            setPaths(field);
        }
    }
}
void GUI::clearButtonClicked(RenderWindow& window, Field& field){
    string spriteToAccess = "clear";
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::FloatRect bounds = sprites[spriteToAccess].getGlobalBounds();
        if (bounds.contains(mouse))
        {
            cout << "Clear button clicked!" << endl;
            clearEverything(field);

        }
    }
}

//adds obstacles manually based on user input (mouse position)
void GUI::rightClickObstacles(RenderWindow& window, Field& field, Vector2i mousePosition){
    if(mousePosition.x <= 1280 && mousePosition.y <= 1280){
        cout <<" right clicked within bounds " << endl;
        int nodeX = mousePosition.x/4;
        int nodeY = mousePosition.y/4;
        field.AddObst(nodeY, nodeX, 20, 20);
    }else{
        cout<< "not clicked within bounds " << endl;
    }

}

GUI::GUI() {

}

void GUI::clearEverything(Field& field){
    field.Clear();
   for(int i = 0; i < 320; i++){
        for(int j = 0; j < 320; j++){
            nodes[i][j].open = true;
            nodes[i][j].obst = false;
            nodes[i][j].bfs = false;
            nodes[i][j].dfs = false;
            nodes[i][j].dij = false;
        }
    }



}
