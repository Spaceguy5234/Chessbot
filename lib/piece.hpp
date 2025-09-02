#pragma once
#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <stdint.h>

class Piece{

private:
    std::string pieceName;
    unsigned int pieceValue;
    bool pieceColor;
    uint64_t pieceMovesBoard;

public:
    //constructor
    Piece(std::string name, unsigned int value, bool color, uint64_t movesBoard);

    bool getPieceColor();
    std::string getPieceName();
    unsigned int getPieceValue();
    uint64_t getPieceMovesBoard();

};

#endif