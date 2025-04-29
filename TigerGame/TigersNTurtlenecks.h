//
// Created by Carter Lewis on 4/23/25.
//

#ifndef TIGERGAME_TIGERSNTURTLENECKS_H
#define TIGERGAME_TIGERSNTURTLENECKS_H

#include "constants.h"
Token_t tiger;
int horizontalDistanceToTiger(Token_t token, Token_t tiger);
struct compareMenByColumn {
    bool operator()(Token_t t1, Token_t t2) {
        if(t1.location.row != t2.location.row) return t1.location.row < t2.location.row;
        return horizontalDistanceToTiger(t1, tiger) < horizontalDistanceToTiger(t2, tiger);
    }
};
bool menAboveAttackLine (vector<Token_t> tokens);
Move_t marchForward(vector<Token_t> tokens);

Move_t Move_TigersNTurtlenecks (vector<Token_t> tokens, Color_t turn) {

    tiger = tokens.at(0);
    if(turn == BLUE) {
        bool marchingForward = !menAboveAttackLine(tokens);
        if(marchingForward) {
            return marchForward(tokens);
        }
        else {

        }
    }
    else {

    }

    return {tokens[1], {5,5}};


}

bool menAboveAttackLine (vector<Token_t> tokens) {
    for(Token_t i: tokens) {
        if(i.color==BLUE&&i.location.row> 5) return false;
    }
    return true;
}

vector<Token_t> getJumpableMen(vector<Token_t> tokens) {

}

vector<Move_t> getForkMoves (vector<Token_t> tokens) {

}

Move_t marchForward(Token_t token) {
    return {token, {token.location.row, token.location.col-1}};
}

bool empty(Point_t p, vector<Token_t> tokens) {
    for(Token_t i: tokens) {
        if(i.location == p) return false;
    }
    return true;
}

Move_t marchForward(vector<Token_t> tokens) {
    priority_queue<Token_t, vector<Token_t>, compareMenByColumn> sortedMen;
    for(Token_t i : tokens) {
        if(i.color == BLUE) {
            sortedMen.push(i);
        }
    }

    while(!sortedMen.empty()) {
        Token_t tmp = sortedMen.top();
        sortedMen.pop();
        if(empty({tmp.location.row-1, tmp.location.col}, tokens)) {
            return {tmp, {tmp.location.row-1, tmp.location.col}};
        }
    }
}

int horizontalDistanceToTiger(Token_t token, Token_t tiger) {
    return abs(token.location.col-tiger.location.col);
}


#endif //TIGERGAME_TIGERSNTURTLENECKS_H
