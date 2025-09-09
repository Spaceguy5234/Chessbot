#include <iostream>
#include <bitset>
#include <string>

#include "board.hpp"

std::string reverseString(std::string input);

int main()
{

    Board board("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
    std::cout << std::endl;

    std::cout << "Active color: " << board.getActiveColorString() << std::endl;

    std::cout << "Castling ability(KQkq): " << board.getWhiteKingRookCastle() << board.getWhiteQueenRookCastle();
    std::cout << board.getBlackKingRookCastle() << board.getBlackQueenRookCastle() << std::endl;

    std::cout << "Target en passant square: " << board.getEnPassantTargetSquare() << std::endl;

    std::cout << "Half move clock: " << board.getHalfMoveClock() << std::endl;

    std::cout << "Full move counter: " << board.getFullMoveCounter() << std::endl;
    uint64_t blackKingPosition = (board.getBlackPieces() & board.getKings());
    uint64_t blackKingFile = (blackKingPosition & (uint64_t)7);
    uint64_t blackKingRank = (blackKingPosition >> (uint64_t)3);
    std::cout << "Black king is at: " << blackKingFile << " " << blackKingRank << std::endl;
}

std::string reverseString(std::string input){
    int inputStringLength = (int)input.length();
    std::string outputString;
    for (int i = inputStringLength; i > 0; i--){
        outputString.push_back(input[i]);
    }
    return outputString;
}