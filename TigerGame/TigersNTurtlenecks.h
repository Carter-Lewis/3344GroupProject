//
// Created by Carter Lewis on 4/23/25.
//

#ifndef TIGERGAME_TIGERSNTURTLENECKS_H
#define TIGERGAME_TIGERSNTURTLENECKS_H

#include "constants.h"

//TODO why is this here...?
Token_t tiger;

set<pair<Point, Point>> diagonalEdgeList() {
    set<pair<Point, Point>> edges;
    edges.insert(make_pair(Point(0, 4), Point(1, 3)));
    edges.insert(make_pair(Point(1, 3), Point(0, 4)));
    edges.insert(make_pair(Point(0, 4), Point(1, 5)));
    edges.insert(make_pair(Point(1, 5), Point(0, 4)));
    edges.insert(make_pair(Point(1, 3), Point(2, 2)));
    edges.insert(make_pair(Point(2, 2), Point(1, 3)));
    edges.insert(make_pair(Point(2, 2), Point(3, 3)));
    edges.insert(make_pair(Point(3, 3), Point(2, 2)));
    edges.insert(make_pair(Point(1, 3), Point(2, 4)));
    edges.insert(make_pair(Point(2, 4), Point(1, 3)));
    edges.insert(make_pair(Point(2, 4), Point(3, 3)));
    edges.insert(make_pair(Point(3, 3), Point(2, 4)));
    edges.insert(make_pair(Point(1, 5), Point(2, 4)));
    edges.insert(make_pair(Point(2, 4), Point(1, 5)));
    edges.insert(make_pair(Point(1, 5), Point(2, 6)));
    edges.insert(make_pair(Point(2, 6), Point(1, 5)));
    edges.insert(make_pair(Point(2, 4), Point(3, 5)));
    edges.insert(make_pair(Point(3, 5), Point(2, 4)));
    edges.insert(make_pair(Point(2, 6), Point(3, 5)));
    edges.insert(make_pair(Point(3, 5), Point(2, 6)));
    edges.insert(make_pair(Point(3, 3), Point(4, 4)));
    edges.insert(make_pair(Point(4, 4), Point(3, 3)));
    edges.insert(make_pair(Point(3, 5), Point(4, 4)));
    edges.insert(make_pair(Point(4, 4), Point(3, 5)));

    edges.insert(make_pair(Point(4, 4), Point(5, 3)));
    edges.insert(make_pair(Point(5, 3), Point(4, 4)));

    edges.insert(make_pair(Point(5, 3), Point(6, 2)));
    edges.insert(make_pair(Point(6, 2), Point(5, 3)));

    edges.insert(make_pair(Point(6, 2), Point(7, 1)));
    edges.insert(make_pair(Point(7, 1), Point(6, 2)));

    edges.insert(make_pair(Point(7, 1), Point(8, 0)));
    edges.insert(make_pair(Point(8, 0), Point(7, 1)));

    edges.insert(make_pair(Point(8, 0), Point(9, 1)));
    edges.insert(make_pair(Point(9, 1), Point(8, 0)));

    edges.insert(make_pair(Point(9, 1), Point(10, 2)));
    edges.insert(make_pair(Point(10, 2), Point(9, 1)));

    edges.insert(make_pair(Point(10, 2), Point(11, 3)));
    edges.insert(make_pair(Point(11, 3), Point(10, 2)));

    edges.insert(make_pair(Point(11, 3), Point(12, 4)));
    edges.insert(make_pair(Point(12, 4), Point(11, 3)));

    edges.insert(make_pair(Point(12, 4), Point(11, 5)));
    edges.insert(make_pair(Point(11, 5), Point(12, 4)));

    edges.insert(make_pair(Point(11, 5), Point(10, 6)));
    edges.insert(make_pair(Point(10, 6), Point(11, 5)));

    edges.insert(make_pair(Point(10, 6), Point(9, 7)));
    edges.insert(make_pair(Point(9, 7), Point(10, 6)));

    edges.insert(make_pair(Point(9, 7), Point(8, 8)));
    edges.insert(make_pair(Point(8, 8), Point(9, 7)));

    edges.insert(make_pair(Point(8, 8), Point(7, 7)));
    edges.insert(make_pair(Point(7, 7), Point(8, 8)));

    edges.insert(make_pair(Point(7, 7), Point(6, 6)));
    edges.insert(make_pair(Point(6, 6), Point(7, 7)));

    edges.insert(make_pair(Point(6, 6), Point(5, 5)));
    edges.insert(make_pair(Point(5, 5), Point(6, 6)));

    edges.insert(make_pair(Point(5, 5), Point(4, 4)));
    edges.insert(make_pair(Point(4, 4), Point(5, 5)));

    return edges;
}
enum direction{ NONE,N,NE,E,SE,S,SW,W,NW };

Move_t Move_TigersNTurtlenecks (vector<Token_t> tokens, Color_t turn);
double distance(Point_t p1, Point_t p2);
direction hasEdgeBetween(Point_t point1, Point_t point2);
bool isJumpable(const vector<Token_t>& tokens, const Token_t t);
vector<Token_t> getJumpableMen(const vector<Token_t>& tokens);
bool menAboveAttackLine (vector<Token_t> tokens);
Move_t marchForward(Token_t token);
bool empty(Point_t p, vector<Token_t> tokens);
Move_t marchForward(vector<Token_t> tokens);
int horizontalDistanceToTiger(Token_t token, Token_t tiger);

//TODO: following functions not done yet
bool onDiagonalSquare(Token_t man);
vector<Move_t> getForkMoves (vector<Token_t> tokens);
vector<point> potentialJumpLocations();
bool onPositiveDiagonal();
bool onNegativeDiagonal();

struct marchMenPriority {
    bool operator()(Token_t t1, Token_t t2) {
        if(t1.location.row != t2.location.row) return t1.location.row < t2.location.row;
        return horizontalDistanceToTiger(t1, tiger) < horizontalDistanceToTiger(t2, tiger);
    }
};

//TODO this is the main function
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

double distance(Point_t p1, Point_t p2) {
    return sqrt(pow(p1.col - p2.col, 2) + pow(p1.row - p2.row, 2));
}

direction hasEdgeBetween(Point_t point1, Point_t point2) {
    int rowDiff = point1.row - point2.row;
    int colDiff = point1.col - point2.col;

    // Check 4 simple directions
    if (rowDiff == -1 && colDiff ==  0) return N;
    if (rowDiff ==  0 && colDiff ==  1) return E;
    if (rowDiff ==  1 && colDiff ==  0) return S;
    if (rowDiff ==  0 && colDiff == -1) return W;

    pair<Point, Point> edge = make_pair(Point(point1.row, point1.col),
                                            Point(point2.row, point2.col));

    for (pair<Point, Point> e: diagonalEdgeList()) {
        if (e == edge) {
            if (rowDiff == -1 && colDiff ==  1) return NE;
            if (rowDiff ==  1 && colDiff ==  1) return SE;
            if (rowDiff ==  1 && colDiff == -1) return SW;
            if (rowDiff == -1 && colDiff == -1) return NW;
        }
    }

    return NONE;
}

bool isJumpable(const vector<Token_t> &tokens, const Token_t t) {
    bool result = true;

    direction tiger_direction_of_token = hasEdgeBetween(tokens[0].location, t.location);
    Point_t location = t.location;
    switch (tiger_direction_of_token) {
        case N:
            location.row += 1;
            break;
        case NE:
            location.row += 1;
            location.col -= 1;
            break;
        case E:
            location.col -= 1;
            break;
        case SE:
            location.row -= 1;
            location.col -= 1;
            break;
        case S:
            location.row -= 1;
            break;
        case SW:
            location.row -= 1;
            location.col += 1;
            break;
        case W:
            location.col += 1;
            break;
        case NW:
            location.row += 1;
            location.col += 1;
            break;
        default: break;
    }

    result = empty(location, tokens);
}

vector<Token_t> getJumpableMen(const vector<Token_t> &tokens) {
    vector<Token_t> jumpableMen;
    for (Token_t t : tokens) {
        if (isJumpable(tokens, t)) {
            jumpableMen.push_back(t);
        }
    }

    return jumpableMen;
}

bool isEndagered(const vector<Token_t> &tokens, const Token_t t) {
    bool result = true;

    //TODO figure this out


    return result;
}


vector<Token_t> getEndageredMen(const vector<Token_t> &tokens) {
    vector<Token_t> endagered;
    for (Token_t t : tokens) {
        if (isEndagered(tokens, t)) {
            endagered.push_back(t);
        }
    }

    return endagered;
}

bool menAboveAttackLine (vector<Token_t> tokens) {
    for(Token_t i: tokens) {
        if(i.color==BLUE&&i.location.row > 6) return false;
    }
    return true;
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
    priority_queue<Token_t, vector<Token_t>, marchMenPriority> sortedMen;
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

bool onDiagonalSquare(Token_t man) {

}

vector<Move_t> getForkMoves (vector<Token_t> tokens) {

}

vector<point> potentialJumpLocations() {

}
/*
 * TODO fill in all Positive Diagonal coordinates
 * Positive meaning it would have a positive slope in xy plane
 */
bool onPositiveDiagonal() {
//    return tiger.location.row == 12 && tiger.location.col == 3
//        &&
//        &&
//        &&
//        &&;
}

/*
 * TODO do the same for negative diagonals
 */
bool onNegativeDiagonal() {

}


#endif //TIGERGAME_TIGERSNTURTLENECKS_H
