//
//  Board.h
//  Homework 1 - Second Year - Semester 1
//
//  Created by Shai Shalev on 08/12/2019.
//  Copyright © 2019 Shai Shalev. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include "cell.h"
#include <iostream>
#include <list>
using namespace std;


class Board {
    Cell **board;
    
    
public:
    int size;

    //Constructors
    Board(int size) {
        board = new Cell*[size];
        for(int i = 0; i < size; i++){
            board[i] = new Cell[size];
        }
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                board[i][j].c = '.';
            }
        }
        this->size = size;
    };
    
    Board(const Board &other){
            size = other.size;
            board = new Cell*[size];
                   for(int i = 0; i < size; i++){
                       board[i] = new Cell[size];
                       for (int j = 0; j < size; j++) {
                           board[i][j].c = '.';
                       }
                   }
                    
                   for(int i = 0; i < size; i++){
                       for(int j = 0; j < size; j++){
                           board[i][j].c = other.board[i][j].c;
                       }
                   }
    };
    
    
    Cell& operator[](list<int> list) {
        Cell s;
        int x = list.front(), y = list.back();
        if((x < size && y < size) && (x >= 0 && y >= 0)){
            return board[x][y];
        } else {
            cout << "Out Of Limits!" << endl;
            return s;
        }
    };
    
    
    void operator=(const Board& other){
        size = other.size;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                board[i][j].c = other.board[i][j].c;
            };
        };
    };
    
    void operator=(char c){
        if(c == '.'){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    board[i][j].c = '.';
                }
            }
        } else {
            cout << "You Can't Fill the board with this character!" << endl;
        }
    }

    
    friend ostream& operator<<(ostream &os, const Board &board);
    //Destructor
    ~Board(){
        for(int i = 0; i < this->size; i++){
//            cout << endl;
            delete[] this->board[i];
        };
//        delete this->board;
//        cout << endl;

};
};

    ostream& operator<<(ostream &os, const Board &board){
                for(int i = 0; i < board.size; i++){
                        for(int j = 0; j < board.size; j++){
                            os << board.board[i][j].c;
                        }
                    os << endl;
                }
        return os;
    };
    #endif /* Board_h */
