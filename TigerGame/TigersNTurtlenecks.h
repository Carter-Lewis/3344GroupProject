//
// Created by Carter Lewis on 4/23/25.
//

#ifndef TIGERGAME_TIGERSNTURTLENECKS_H
#define TIGERGAME_TIGERSNTURTLENECKS_H

#include "constants.h"

struct compareMenByColumn {
    bool operator()(Token_t t1, Token_t t2) {
        return t1.location.col < t2.location.col;
    }
};
Move_t Move_TigersNTurtlenecks (vector<Token_t> tokens, Color_t turn) {


    return {tokens[1], {5,5}};
}

vector<Token_t> getJumpableMen(vector<Token_t> tokens) {

}

vector<Move_t> getForkMoves (vector<Token_t> tokens) {

}

Move_t marchForward(Token_t token) {
    return {token, {token.location.row, token.location.col+1}};
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
        if(empty({tmp.location.row, tmp.location.col+1}, tokens)) {
            return {tmp, {tmp.location.row, tmp.location.col+1}};
        }
    }
}


#endif //TIGERGAME_TIGERSNTURTLENECKS_H
