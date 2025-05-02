//
// Created by Carter Lewis on 4/23/25.
//

#ifndef TIGERGAME_TIGERSNTURTLENECKS_H
#define TIGERGAME_TIGERSNTURTLENECKS_H

#include "constants.h"
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
bool empty(Point_t p, vector<Token_t> tokens);

//Man Functions
bool menAboveAttackLine (vector<Token_t> tokens);
Move_t marchForward(Token_t token);
Move_t marchForward(vector<Token_t> tokens);
int horizontalDistanceToTiger(Token_t token, Token_t tiger);

//Tiger Functions
vector<Token_t> getJumpableMen(const vector<Token_t>& tokens);
Move_t moveTowardMostMen(const vector<Token_t>& tokens);
Move_t tigerJump(vector<Token_t> tokens);
Move_t moveTowardClosestMan(const vector<Token_t>& tokens);
int totalDistanceToAllMen(Point_t p, vector<Token_t> tokens);

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
    //Tiger algorithm
    else {
        if(getJumpableMen(tokens).size() > 0) {
            return tigerJump(tokens);
        }
        else {
            return moveTowardMostMen(tokens);
        }
    }

    return {tokens[1], {5,5}};
}

double distance(Point_t p1, Point_t p2) {
    return abs(p1.row-p2.row) + abs(p1.col-p2.col);
}

direction hasEdgeBetween(Point_t point1, Point_t point2) {
    int rowDiff = point2.row - point1.row;
    int colDiff = point2.col - point1.col;

    // Check all 8 directions
    if(point2.row < 4) {
        if(rowDiff == 0 || colDiff == 0) return NONE;
        if(rowDiff == -1 && colDiff ==  1 && (point1.row + point1.col == 4 || point1.row + point1.col == 6  || point1.row + point1.col == 8)) return NE;
        if (rowDiff ==  1 && colDiff == -1 && (point1.row + point1.col == 4 || point1.row + point1.col == 6 || point1.row + point1.col == 8)) return SW;
        if (rowDiff == -1 && colDiff == -1 && (point1.row - point1.col == 4 || point1.row - point1.col == 2 || point1.row - point1.col == 0)) return NW;
        if (rowDiff ==  1 && colDiff ==  1 && (point1.row - point1.col == 4 || point1.row - point1.col == 2 || point1.row - point1.col == 0)) return SE;
    }
    if (rowDiff == -1 && colDiff ==  0) return N;
    if (rowDiff == -1 && colDiff ==  1 && (point1.row + point1.col == 16 || point1.row + point1.col == 8)) return NE;
    if (rowDiff ==  0 && colDiff ==  1) return E;
    if (rowDiff ==  1 && colDiff ==  1 && (point1.row - point1.col == 8 || point1.row - point1.col == 0)) return SE;
    if (rowDiff ==  1 && colDiff ==  0) return S;
    if (rowDiff ==  1 && colDiff == -1 && (point1.row + point1.col == 16 || point1.row + point1.col == 8)) return SW;
    if (rowDiff ==  0 && colDiff == -1) return W;
    if (rowDiff == -1 && colDiff == -1 && (point1.row - point1.col == 8 || point1.row - point1.col == 0)) return NW;

    return NONE;
}

bool isJumpable(const vector<Token_t> &tokens, const Token_t t) {
    if(t.color != BLUE) return false;

    Point_t tigerLocation = tokens.at(0).location;
    direction d = hasEdgeBetween(tigerLocation, t.location);
    if(d == NONE) return false;

    Point_t jumpPosition = t.location;

    switch(d) {
        case N:
            jumpPosition.row--;
            break;
        case NE:
            jumpPosition.row--;
            jumpPosition.col++;
            break;
        case E:
            jumpPosition.col++;
            break;
        case SE:
            jumpPosition.row++;
            jumpPosition.col++;
            break;
        case S:
            jumpPosition.row++;
            break;
        case SW:
            jumpPosition.row++;
            jumpPosition.col--;
            break;
        case W:
            jumpPosition.col--;
            break;
        case NW:
            jumpPosition.col--;
            jumpPosition.row--;
            break;
        default:
            return false;
    }
    return empty(jumpPosition, tokens);
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

bool isNextMoveJumpable(vector<Token_t> tokens, Point_t nextLocation) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).location == nextLocation) {
            tokens.at(i).location.row--;
            break;
        }
    }

    for (Token_t t : tokens) {
        if (isJumpable(tokens, t)) {
            return false;
        }
    }

    return true;
}

Move_t marchForward(vector<Token_t> tokens) {
    priority_queue<Token_t, vector<Token_t>, marchMenPriority> sortedMen;
    for (Token_t i : tokens) {
        if (i.color == BLUE) {
            sortedMen.push(i);
        }
    }

    while (!sortedMen.empty()) {
        Token_t tmp = sortedMen.top();
        sortedMen.pop();

        Point_t nextSpot = {tmp.location.row - 1, tmp.location.col};

        // Check if the spot in front is empty
        if (empty(nextSpot, tokens)) {
            // Only march if no jump is creaetd
            if (isNextMoveJumpable(tokens, nextSpot)) {
                return {tmp, nextSpot};
            }
        }
    }

    // No valid forward moves
    return {tokens[1], tokens[1].location};  // fallback: return a no-op move
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

Move_t tigerJump(vector<Token_t> tokens) {
    vector<Token_t> jumpableMen = getJumpableMen(tokens);
    switch(hasEdgeBetween(tiger.location, jumpableMen.at(0).location)) {
        case N:
            return {tiger, {tiger.location.row-2, tiger.location.col}};
        case NE:
            return {tiger, {tiger.location.row-2, tiger.location.col+2}};
        case E:
            return {tiger, {tiger.location.row, tiger.location.col+2}};
        case SE:
            return {tiger, {tiger.location.row+2, tiger.location.col+2}};
        case S:
            return {tiger, {tiger.location.row+2, tiger.location.col}};
        case SW:
            return {tiger, {tiger.location.row+2, tiger.location.col-2}};
        case W:
            return {tiger, {tiger.location.row, tiger.location.col-2}};
        case NW:
            return {tiger, {tiger.location.row-2, tiger.location.col-2}};
    }
}
/*
 * TODO fill in all Positive Diagonal coordinates
 * Positive meaning it would have a positive slope in xy plane
 */
bool tigerOnPositiveDiagonal() {
//    return tiger.location.row == 0 && tiger.location.col == 4
//        || tiger.location.row == 1 && tiger.location.col == 3
//        || tiger.location.row == 2 && tiger.location.col == 2
//        || tiger.location.row == 2 && tiger.location.col == 6
//        || tiger.location.row == 3 && tiger.location.col == 5
//        || tiger.location.row == 4 && tiger.location.col == 4
//        || tiger.location.row == 5 && tiger.location.col == 3
//        || tiger.location.row == 6 && tiger.location.col == 2
//        || tiger.location.row == 7 && tiger.location.col == 1
//        || tiger.location.row == 8 && tiger.location.col == 0;
}

/*
 * TODO do the same for negative diagonals
 */
bool onNegativeDiagonal() {

}

Move_t moveTowardMostMen(const vector<Token_t>& tokens) {
    Token_t tiger = tokens[0];
    Point_t current = tiger.location;

    const int d[8][2] = {
            {-1,  0}, {-1,  1}, {0,  1}, {1,  1},
            { 1,  0}, { 1, -1}, {0, -1}, {-1, -1}
    };

    Move_t bestMove = {tiger, current};  // fallback to no move
    int minTotalDistance = INT_MAX;
    bool foundValidMove = false;

    for (int i = 0; i < 8; i++) {
        Point_t next = {current.row + d[i][0], current.col + d[i][1]};

        // Must be within bounds
        if (next.row < 0 || next.row > GRID_ROW || next.col < 0 || next.col > GRID_COL)
            continue;

        // Must be a legal board edge
        if (hasEdgeBetween(current, next) == NONE)
            continue;

        // Must be empty
        if (!empty(next, tokens))
            continue;

        // Calculate total distance from 'next' to all blue tokens
        int totalDistance = totalDistanceToAllMen(next, tokens);

        if (totalDistance < minTotalDistance) {
            minTotalDistance = totalDistance;
            bestMove = {tiger, next};
            foundValidMove = true;
        }
    }

    return foundValidMove ? bestMove : moveTowardClosestMan(tokens);  // fallback to no-op
}

Move_t moveTowardClosestMan(const vector<Token_t>& tokens) {
    const Token_t& tiger = tokens[0];  // Assume tiger is at index 0
    Point_t current = tiger.location;

    const int d[8][2] = {
            {-1,  0}, {-1,  1}, {0,  1}, {1,  1},
            { 1,  0}, { 1, -1}, {0, -1}, {-1, -1}
    };

    Move_t bestMove = {tiger, current};  // Default to no move
    int minDistanceToClosestMan = INT_MAX;
    bool foundValidMove = false;

    for (int i = 0; i < 8; i++) {
        Point_t next = {current.row + d[i][0], current.col + d[i][1]};

        // 1. Check bounds
        if (next.row < 0 || next.row >= GRID_ROW || next.col < 0 || next.col >= GRID_COL)
            continue;

        // 2. Must be connected via edge
        if (hasEdgeBetween(current, next) == NONE)
            continue;

        // 3. Must be empty
        if (!empty(next, tokens))
            continue;

        // 4. Find distance to nearest blue token
        int closestDist = INT_MAX;
        for (const auto& t : tokens) {
            if (t.color == BLUE) {
                int dist = abs(t.location.row - next.row) + abs(t.location.col - next.col);
                if (dist < closestDist) {
                    closestDist = dist;
                }
            }
        }

        // 5. Choose best move
        if (closestDist < minDistanceToClosestMan) {
            minDistanceToClosestMan = closestDist;
            bestMove = {tiger, next};  // ✅ next is a Point_t
            foundValidMove = true;
        }
    }

    return foundValidMove ? bestMove : Move_t{tiger, {current.row+1, current.col}};  // fallback to current pos
}


int totalDistanceToAllMen(Point_t p, vector<Token_t> tokens) {
    int dist = 0;
    for(int i = 0; i < tokens.size(); i++) {
        dist += distance(p, tokens[i].location);
    }
    return dist;
}




#endif //TIGERGAME_TIGERSNTURTLENECKS_H
