#include "piece.hpp"

/// @brief Generic chess piece
/// @param name Name of the piece
/// @param value Value of the piece ()
/// @param color Color of the piece (White/Black)
Piece::Piece(std::string name, unsigned int value, bool color, uint64_t movesBoard){

    pieceName = name;
    pieceValue = value;
    pieceColor = color;
    pieceMovesBoard = movesBoard;

}

std::string Piece::getPieceName(){
    return pieceName;
}

unsigned int Piece::getPieceValue(){
    return pieceValue;
}


bool Piece::getPieceColor(){
    return pieceColor;
}

uint64_t Piece::getPieceMovesBoard(){
    return pieceMovesBoard;
}

