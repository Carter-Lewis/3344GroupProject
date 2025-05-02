//
// Created by Kiera Shepperd on 5/1/25.
//

#include <iostream>
#include "constants.h"
#include "TigersNTurtlenecks.h"
#include "Point.h"
#include "Token.h"
using namespace std;

Token token[19];

vector<Token_t> makeVector(){
    vector<Token_t> v;
    Token_t T;
    Point p;
    for(int i = 0; i < NUM_TOKENS; i++){
        if(token[i].isActive()){
            if(i>0){
                T.color = BLUE;
            }
            else{
                T.color = RED;
            }
            p = token[i].getLocation();
            T.location.row = p.x;
            T.location.col = p.y;
            v.push_back(T);
        }
    }

    return v;
}

int main() {
    Point_t p1, p2;
    p1.row = 4;
    p1.col = 4;

    p2.row = 5;
    p2.col = 5;
    cout << distance(p1, p2) << endl;

    token[0].setColor(red);
    token[0].setAttached(false);
    token[0].setLocation(Point(2, 4));
    for(int i = 1; i <= 18; i++){
        token[i].setColor(blue);
        token[i].setAttached(false);
        token[i].setActive(true);
        int col = (i-1)%9;
        int row = 11+(i-1)/9;
        token[i].setLocation(Point(row, col));
    }

    Token_t t = Token_t();
    t.location.row = 5;
    t.location.col = 8;
    t.color = BLUE;

    cout << hasEdgeBetween(p1, p2) << endl;
    cout << isJumpable(makeVector(), t);

}

