#include <iostream>
#include <bitset>
#include <string>

#include "board.hpp"

int main()
{

    Board board("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
    std::cout << std::endl;
    std::string output = std::bitset<64>(board.getKings()).to_string();
    std::cout << output.substr(0, 8) << std::endl;
    std::cout << output.substr(8, 8) << std::endl;
    std::cout << output.substr(16, 8) << std::endl;
    std::cout << output.substr(24, 8) << std::endl;
    std::cout << output.substr(32, 8) << std::endl;
    std::cout << output.substr(48, 8) << std::endl;
    std::cout << output.substr(56, 8) << std::endl;

    std::cout << "Active color(0=w, 1=b): " << board.getActiveColor() << std::endl;

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