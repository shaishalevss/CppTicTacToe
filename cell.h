//
//  cell.h
//  Homework 1 - Second Year - Semester 1
//
//  Created by Shai Shalev on 11/12/2019.
//  Copyright © 2019 Shai Shalev. All rights reserved.
//

#ifndef cell_h
#define cell_h
#include <iostream>
#include "Board.h"
using namespace std;


class Cell{
public:
    char c;
    
    Cell(){};
    
//    Cell(char c){
//        if(c == 'X' || c == 'O' || c == '.'){
//            this->c = c;
//        }else{
//            cout << "Wrong Input Character!" << endl;
//        }
//    };
    
    Cell operator=(const char& c){
        if(c == 'X' || c == 'O'){
            this->c = c;
        }
        else if(c == '.'){
            this->c = c;
        }
        else {
            cout << "Illegal sign" << endl;
        }
        return *this;
    };
    
    friend ostream& operator<<(ostream &os, const Cell &cell);

    ~Cell(){
//        cout << "Destroyed!!" << endl;
    };
};

ostream& operator<<(ostream &os, const Cell &cell){
    os << cell.c;
    return os;
};

#endif /* cell_h */
