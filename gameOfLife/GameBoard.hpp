//
//  GameBoard.hpp
//  gameOfLife
//
//  Created by Seth Lewis on 9/16/16.
//  Copyright © 2016 Jackson Lewis. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp
#include <vector>
using namespace std;
class GameBoard {
    float sizeScale;
    
    public:
    vector<vector<int> > board;
    GameBoard();
    void update();
    void clearBoard();
    void getUserInput();
};

#endif /* GameBoard_hpp */
