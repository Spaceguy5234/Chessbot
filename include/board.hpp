#pragma once
#ifndef BOARD_H
#define BOARD_H

//standard c/c++ includes
#include <string>
#include <stdexcept>
#include <stdint.h>
#include <ctype.h>


//external includes

//internal includes
#include "piece.hpp"

class Board{

private:
    uint64_t whitePieces = 0;
    uint64_t blackPieces = 0;
    uint64_t pawnPieces = 0;
    uint64_t knightPieces = 0;
    uint64_t bishopPieces = 0;
    uint64_t rookPieces = 0;
    uint64_t queenPieces = 0;
    uint64_t kingPieces = 0;
    const uint64_t EMPTY_BOARD = 0;

public:
    //Constructor
    Board(std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    uint64_t getBoardState();
    uint64_t getWhitePieces();
    uint64_t getBlackPieces();
    uint64_t getPawns();
    uint64_t getKnights();
    uint64_t getBishops();
    uint64_t getRooks();
    uint64_t getQueens();
    uint64_t getKings();
    
    uint64_t convertToBitboard(std::string algebraicInput);
    uint64_t convertToBitboard(int file, int rank);

    //FEN string for export

    std::string getBoardFEN();

    void setBoardState(std::string FEN);
    void setBoardState(uint64_t boardState);
    void setWhitePieces(uint64_t whiteLocations);
    void setBlackPieces(uint64_t blackLocations);
    void setPawns(uint64_t pawnLocations);
    void setKnights(uint64_t knightLocations);
    void setBishops(uint64_t bishopLocations);
    void setRooks(uint64_t rookLocations);
    void setQueens(uint64_t queenLocations);
    void setKings(uint64_t kingLocations);

};

#endif