#pragma once
#ifndef BOARD_H
#define BOARD_H

// standard c/c++ includes
#include <string>
#include <stdexcept>
#include <stdint.h>
#include <ctype.h>
#include <iostream>
#include <bitset>


// external includes

// internal includes

class Board
{

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

    bool activeColor = 0;
    bool whiteKingRookCastle = 0;
    bool whiteQueenRookCastle = 0;
    bool blackKingRookCastle = 0;
    bool blackQueenRookCastle = 0;

    std::string enPassantTargetSquare = "-";

    int halfMoveClock = 0;
    int fullMoveCounter = 1;

    std::string startpos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

public:
    Board();
    Board(std::string FEN);
    uint64_t getPopCount();
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

    bool getActiveColorBool();
    bool getWhiteKingRookCastle();
    bool getWhiteQueenRookCastle();
    bool getBlackKingRookCastle();
    bool getBlackQueenRookCastle();

    int getHalfMoveClock();
    int getFullMoveCounter();

    std::string getEnPassantTargetSquare();
    std::string getBoardFEN();
    std::string getActiveColorString();

    void setBoardStateFromFen(std::string FEN);
    void setWhitePieces(uint64_t whiteLocations);
    void setBlackPieces(uint64_t blackLocations);
    void setPawns(uint64_t pawnLocations);
    void setKnights(uint64_t knightLocations);
    void setBishops(uint64_t bishopLocations);
    void setRooks(uint64_t rookLocations);
    void setQueens(uint64_t queenLocations);
    void setKings(uint64_t kingLocations);
    void setActiveColor(std::string activeColor);
    void setHalfMoveClock(int providedHalfMove);
    void setFullMoveCounter(int providedFullMove);
    void setEnPassantTargetSquare(std::string providedEnPassantTargetSquare);
    void setCastlingAbility(std::string castlingAbility);
    void setWhiteKingRookCastle(bool canWhiteKingRookCastle);
    void setWhiteQueenRookCastle(bool canWhiteQueenRookCastle);
    void setBlackKingRookCastle(bool canBlackKingRookCastle);
    void setBlackQueenRookCastle(bool canBlackQueenRookCastle);

    void printDebugHelp(uint64_t input);
};

#endif