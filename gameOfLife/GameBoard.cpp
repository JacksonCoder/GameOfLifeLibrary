//
//  GameBoard.cpp
//  gameOfLife
//
//  Created by Seth Lewis on 9/16/16.
//  Copyright © 2016 Jackson Lewis. All rights reserved.
//

#include "GameBoard.hpp"
GameBoard::GameBoard(int x, int y): x(x),y(y){
    board = new int*[y];
    for(int i = 0; i < y;i++){
        board[i] = new int[x];
    }
}
void GameBoard::getUserInput(sf::Event event, sf::RenderWindow& w){
    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
        int x = sf::Mouse::getPosition(w).x;
        int y = sf::Mouse::getPosition(w).y;
        int cx=0;
        int cy=0;
        for(int i = 0; i < this->y;i++){
            if(y > i*20 + 30){
                cy++;
            }
        }
        for(int a = 1; a < this->x - 1; a++){
            if(x > (a*20) - 10){
                cx++;
            }
            
        }
        if(board[cy][cx] == 0) board[cy][cx] = 1; else board[cy][cx] = 0;
    }
    
}
void GameBoard::runCellCheck(){
    changes.clear();
    for(int i = 1; i < y-1;i++){
        for(int a = 1; a < x-1;a++){
            int count = board[i][a+1] + board[i][a-1] + board[i-1][a] + board[i-1][a-1] + board[i-1][a+1] + board[i+1][a-1] + board[i+1][a] + board[i+1][a+1];
            if(board[i][a] == 1){
            if(count < 2){ changes[{i,a}] = 0;}
            if(count > 4 || count == 4){ changes[{i,a}] =0;}
            }
            else if(count == 3){ changes[{i,a}] = 1;}
        }
    }

    for(int i = 0; i < y;i++){
        for(int a=0;a<x;a++){
            if( changes.find({i,a}) == changes.end()){
              //nothing...
            }else{ board[i][a] = changes[{i,a}];}
        }
    }
    
}
void GameBoard::update(){
    runCellCheck();
}
void GameBoard::draw(sf::RenderWindow& w,sf::Font f) const{
    
    sf::Text buffer;
    buffer.setColor(sf::Color::White);
    buffer.setFont(f);
    //buffer.setString("hello!");
    for(int i = 1; i < y-1;i++){

            string line;
            for(int a = 1; a < x-1; a++){
                char c;
                if(board[i][a] == 0){
                    c = '0';
                }
                else c = '%';
                line += c;
                
            }

        buffer.setString(line);
        buffer.setPosition(10, 20*i);
        w.draw(buffer);
        
        
    }
}