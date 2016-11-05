//
//  GameBoard.hpp
//  gameOfLife
//
//  Created by Seth Lewis on 9/16/16.
//  Copyright © 2016 Jackson Lewis. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <GameBoard.hpp>
#include <map>
#include <iostream>
using namespace std;
class GameBoard{
    float sizeScale; //for later
    int x;
    int y;
    void runCellCheck();
    public:
    int** board;
    map<pair<int,int>,int> changes;
    GameBoard(int x, int y);
    ~GameBoard(){
        delete[] board;
    }
    void update();
    void copydoubleint(bool);
    void clearBoard();
    void getUserInput(sf::Event,sf::RenderWindow&);
    void draw(sf::RenderWindow&,sf::Font) const;
};

#endif /* GameBoard_hpp */
