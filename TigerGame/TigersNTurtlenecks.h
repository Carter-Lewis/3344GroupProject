//
// Created by Carter Lewis on 4/23/25.
//

#ifndef TIGERGAME_TIGERSNTURTLENECKS_H
#define TIGERGAME_TIGERSNTURTLENECKS_H

#include "constants.h"

using namespace std;

static Token_t tiger;

enum direction{ NONE,N,NE,E,SE,S,SW,W,NW };

Move_t Move_TigersNTurtlenecks (vector<Token_t> tokens, Color_t turn);
double distance(Point_t p1, Point_t p2);
direction hasEdgeBetween(Point_t point1, Point_t point2);
bool isJumpable(const vector<Token_t>& tokens, const Token_t t);
bool empty(Point_t p, vector<Token_t> tokens);
bool  isForkable(vector<Token_t> tokens);
Move_t getForkMove (vector<Token_t> tokens);

//Man Functions
bool menAboveAttackLine (vector<Token_t> tokens);
Move_t marchForward(Token_t token);
Move_t marchForward(vector<Token_t> tokens);
int horizontalDistanceToTiger(Token_t token, Token_t tiger);
Move_t moveJumpableMan(vector<Token_t> jumpable, vector<Token_t> tokens);
Point_t findPotentialJumpLoc(Point_t tigerLocation, Point_t p);

//Tiger Functions
vector<Token_t> getJumpableMen(const vector<Token_t>& tokens);
Move_t moveTowardMostMen(const vector<Token_t>& tokens);
Move_t tigerJump(vector<Token_t> tokens);
Move_t moveTowardClosestMan(const vector<Token_t>& tokens);
int totalDistanceToAllMen(Point_t p, vector<Token_t> tokens);
Move_t getForkMove (vector<Token_t> tokens);

//TODO: following functions not done yet
bool onDiagonalSquare(Token_t man);

vector<Point_t> potentialJumpLocations();
bool onPositiveDiagonal();
bool onNegativeDiagonal();

struct marchMenPriority {
    bool operator()(Token_t t1, Token_t t2) {
        return t1.location.row < t2.location.row;
    }
};

//TODO this is the main function
Move_t Move_TigersNTurtlenecks (vector<Token_t> tokens, Color_t turn) {

    tiger = tokens.at(0);
    if(turn == BLUE) {
        vector<Token_t> jumpable = getJumpableMen(tokens);
        if(!jumpable.empty()) {
            return moveJumpableMan(jumpable, tokens);
        }
        if (menAboveAttackLine(tokens)) {
            //move things inward on the sides
        }
        return marchForward(tokens);
    }

    //Tiger algorithm
    else {
        if(getJumpableMen(tokens).size() > 1) {
            return getForkMove(tokens);
        }
        if(getJumpableMen(tokens).size() > 0) {
            return tigerJump(tokens);
        }
        else {
            return moveTowardMostMen(tokens);
        }
    }

    return {tokens[1], {5,5}};
}

Move_t moveJumpableMan(vector<Token_t> jumpable, vector<Token_t> tokens) {
    Token_t tokenInDanger = jumpable.front();
    Point_t emptyPoint = findPotentialJumpLoc(tokens[0].location, tokenInDanger.location);

    Token_t movedToken;
    Point_t dest = tokenInDanger.location;

    for (int i = 0; i < tokens.size(); i++) {
        Token_t j = tokens.at(i);
        if (tokenInDanger.location.row != j.location.row && tokenInDanger.location.col != j.location.col) {
            direction d = hasEdgeBetween(emptyPoint, j.location);
            if (d != NONE) {
                movedToken.color = j.color;
                movedToken.location = j.location;

                dest = j.location;

                switch(d) {
                    case N:
                        dest.row++;
                        break;
                    case NE:
                        dest.row++;
                        dest.col--;
                        break;
                    case E:
                        dest.col--;
                        break;
                    case SE:
                        dest.row--;
                        dest.col--;
                        break;
                    case S:
                        dest.row--;
                        break;
                    case SW:
                        dest.row--;
                        dest.col++;
                        break;
                    case W:
                        dest.col++;
                        break;
                    case NW:
                        dest.col++;
                        dest.row++;
                        break;
                    case NONE:
                        break;
                }
//                break;
            }
        }
    }

    if (dest == tokenInDanger.location) {
        switch(hasEdgeBetween(emptyPoint, tokenInDanger.location)) {
            case NONE:
                break;
            case N:
                dest.row++;
                break;
            case NE:
                dest.row++;
                dest.col--;
                break;
            case E:
                dest.col--;
                break;
            case SE:
                dest.row--;
                dest.col--;
                break;
            case S:
                dest.row--;
                break;
            case SW:
                dest.row--;
                dest.col++;
                break;
            case W:
                dest.col++;
                break;
            case NW:
                dest.col++;
                dest.row++;
                break;
        }
    }

    return {movedToken, dest};
}

double distance(Point_t p1, Point_t p2) {
    return abs(p1.row-p2.row) + abs(p1.col-p2.col);
}

bool insideMainGrid(Point_t p) {
    return (p.row < 4 || p.row > 12 || p.col > 8);
}

direction hasEdgeBetween(Point_t point1, Point_t point2) {
    int rowDiff = point2.row - point1.row;
    int colDiff = point2.col - point1.col;

    // Check all 8 directions
    if(point2.row < 4) {
        if(rowDiff == 0 || colDiff == 0) return NONE;
        if(rowDiff == -1 && colDiff ==  1 && (point1.row + point1.col == 4
            || point1.row + point1.col == 6  || point1.row + point1.col == 8)) return NE;
        if (rowDiff ==  1 && colDiff == -1 && (point1.row + point1.col == 4
            || point1.row + point1.col == 6 || point1.row + point1.col == 8)) return SW;
        if (rowDiff == -1 && colDiff == -1 && (point1.row - point1.col == 4
            || point1.row - point1.col == 2 || point1.row - point1.col == 0)) return NW;
        if (rowDiff ==  1 && colDiff ==  1 && (point1.row - point1.col == 4
            || point1.row - point1.col == 2 || point1.row - point1.col == 0)) return SE;
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

Point_t findPotentialJumpLoc(Point_t tigerLocation, Point_t p) {
    direction d = hasEdgeBetween(tigerLocation, p);

    switch(d) {
        case N:
            p.row--;
            break;
        case NE:
            p.row--;
            p.col++;
            break;
        case E:
            p.col++;
            break;
        case SE:
            p.row++;
            p.col++;
            break;
        case S:
            p.row++;
            break;
        case SW:
            p.row++;
            p.col--;
            break;
        case W:
            p.col--;
            break;
        case NW:
            p.col--;
            p.row--;
            break;
        default:
            p.col = -1;
            p.row = -1;
            break;
    }

    return p;
}

bool isJumpable(const vector<Token_t> &tokens, const Token_t t) {
    if(t.color != BLUE) return false;

    Point_t tigerLocation = tokens.at(0).location;
    Point_t jumpPosition = findPotentialJumpLoc(tigerLocation, t.location);

    if (jumpPosition.row == -1 || jumpPosition.col == -1) return false;
    return empty(jumpPosition, tokens);
}

vector<Token_t> getJumpableMen(const vector<Token_t> &tokens) {
    vector<Token_t> jumpableMen;
    for (int i = 0; i < tokens.size(); i++) {
        if (isJumpable(tokens, tokens.at(i))) {
            jumpableMen.push_back(tokens.at(i));
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
    for (int i = 0; i < tokens.size(); i++) {
        if (isEndagered(tokens, tokens.at(0))) {
            endagered.push_back(tokens.at(0));
        }
    }

    return endagered;
}

bool menAboveAttackLine (vector<Token_t> tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).color == BLUE && tokens.at(i).location.row > 6) {
            return false;
        }
    }
    return true;
}

Move_t marchForward(Token_t token) {
    return {token, {token.location.row, token.location.col-1}};
}

bool empty(Point_t p, vector<Token_t> tokens) {
    for (int i = 0; i < tokens.size(); i++) {
        if(tokens.at(i).location == p) {
            return false;
        }
    }
    return true;
}

bool isNextMoveUnJumpable(vector<Token_t> tokens, Point_t currentLocation, Point_t nextLocation) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).location == currentLocation) {
            tokens.at(i).location = nextLocation;
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

bool isNextMoveForkable(vector<Token_t> tokens, Point_t currentLocation, Point_t nextLocation) {
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).location == currentLocation) {
            tokens.at(i).location = nextLocation;
            break;
        }
    }
    return isForkable(tokens);
}

Move_t marchForward(vector<Token_t> tokens) {
    priority_queue<Token_t, vector<Token_t>, marchMenPriority> sortedMen;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).color == BLUE) {
            sortedMen.push(tokens.at(i));
        }
    }

    while (!sortedMen.empty()) {
        Token_t tmp = sortedMen.top();
        sortedMen.pop();

        Point_t nextSpot = {tmp.location.row - 1, tmp.location.col};

        // Check if the spot in front is empty
        if (empty(nextSpot, tokens)) {
            // Only march if no jump is creaetd
            if (isNextMoveUnJumpable(tokens, tmp.location, nextSpot) && !isNextMoveForkable(tokens, tmp.location, nextSpot)) {
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

// bool onDiagonalSquare(Token_t man) {
//
// }
//
// vector<Move_t> getForkMoves (vector<Token_t> tokens) {
//
// }
//
// vector<Point> potentialJumpLocations() {
//
// }

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
        case NONE:
            return {tiger, {tiger.location.row, tiger.location.col}};
    }
}
/*
 * TODO fill in all Positive Diagonal coordinates
 * Positive meaning it would have a positive slope in xy plane
 */
// bool tigerOnPositiveDiagonal() {
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
//}

/*
 * TODO do the same for negative diagonals
 */
// bool onNegativeDiagonal() {
//
// }

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

        if (next.row < 0 || next.row > GRID_ROW || next.col < 0 || next.col > GRID_COL)
            continue;

        if (hasEdgeBetween(current, next) == NONE)
            continue;

        if (!empty(next, tokens))
            continue;

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

        if (next.row < 0 || next.row >= GRID_ROW || next.col < 0 || next.col >= GRID_COL)
            continue;

        if (hasEdgeBetween(current, next) == NONE)
            continue;


        if (!empty(next, tokens))
            continue;

        int closestDist = INT_MAX;
        for (int i = 0; i < tokens.size(); i++) {
            Token_t t = tokens.at(i);
            if (t.color == BLUE) {
                int dist = abs(t.location.row - next.row) + abs(t.location.col - next.col);
                if (dist < closestDist) {
                    closestDist = dist;
                }
            }
        }

        if (closestDist < minDistanceToClosestMan) {
            minDistanceToClosestMan = closestDist;
            bestMove = {tiger, next};
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

Move_t getForkMove (vector<Token_t> tokens) {
    Point_t current = tokens[0].location;
    const int d[8][2] = {
            {-1,  0}, {-1,  1}, {0,  1}, {1,  1},
            { 1,  0}, { 1, -1}, {0, -1}, {-1, -1}
    };

    for (int i = 0; i < 8; i++) {
        Point_t next = {current.row + d[i][0], current.col + d[i][1]};
        tokens[0].location = next;
        if(getJumpableMen(tokens).size() > 1) {
            return {tokens[0], next};
        }
    }
    return {tokens[0], current};
}
bool  isForkable(vector<Token_t> tokens) {
    Point_t current = tokens[0].location;
    const int d[8][2] = {
            {-1,  0}, {-1,  1}, {0,  1}, {1,  1},
            { 1,  0}, { 1, -1}, {0, -1}, {-1, -1}
    };

    for (int i = 0; i < 8; i++) {
        Point_t next = {current.row + d[i][0], current.col + d[i][1]};
        tokens[0].location = next;
        if(getJumpableMen(tokens).size() > 1) {
            return true;
        }
    }
    return false;
}


#endif //TIGERGAME_TIGERSNTURTLENECKS_H
