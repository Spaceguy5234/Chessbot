#include "board.hpp"

/// @brief Board class to hold and handle bitboards
/// @param FEN Forsyth–Edwards Notation string of the current boardstate
Board::Board(std::string FEN){
    //Initialize the board with the provided FEN
    //If no FEN provided, initialize with default starting position FEN
    setBoardState(FEN);
}

/// @brief Get the bitboard showing all occupied squares
/// @return Bitboard of all pieces
uint64_t Board::getBoardState(){
    uint64_t boardState = getWhitePieces() | getBlackPieces();
    return boardState;
}

/// @brief Get the bitboard showing all squares with white pieces
/// @return Bitboard of all white pieces
uint64_t Board::getWhitePieces(){
    return whitePieces;
}

/// @brief Get the bitboard showing all squares with black pieces
/// @return Bitboard of all black pieces
uint64_t Board::getBlackPieces(){
    return blackPieces;
}

/// @brief Get the bitboard showing all squares with pawns
/// @return Bitboard of all pawns
uint64_t Board::getPawns(){
    return pawnPieces;
}

/// @brief Get the bitboard showing all squares with knights
/// @return Bitboard of all knights
uint64_t Board::getKnights(){
    return knightPieces;
}

/// @brief Get the bitboard showing all squares with bishops
/// @return Bitboard of all bishops
uint64_t Board::getBishops(){
    return bishopPieces;
}

/// @brief Get the bitboard showing all squares with rooks
/// @return Bitboard of all rooks
uint64_t Board::getRooks(){
    return rookPieces;
}

/// @brief Get the bitboard showing all squares with queens
/// @return Bitboard of all queens
uint64_t Board::getQueens(){
    return queenPieces;
}

/// @brief Get the bitboard showing all squares with kings
/// @return Bitboard of all kings
uint64_t Board::getKings(){
    return kingPieces;
}

/// @brief Set the board state according to the provided FEN
/// @param FEN Forsyth–Edwards Notation string of the boardstate
void Board::setBoardState(std::string FEN){

    std::string FENBoard = FEN.substr(0,FEN.find(" "));

    //Why does FEN start at a8??? I would have assumed it started at a1 and went to h8
    //That seems the most intuitive but w/e

    int fenFile = 1;
    int fenRank = 8;

    uint64_t boardPosition;

    for (int i=0; i < FENBoard.length(); i++){

        //gets the bitboard position indicated by the current rank and file
        boardPosition = convertToBitboard(fenFile, fenRank);

        if(isalpha(FENBoard[i])){
            //Sets the white or black piece bitboard location bit accordingly
                isupper(FENBoard[i]) ? setWhitePieces(getWhitePieces() | boardPosition) : setBlackPieces(getBlackPieces() | boardPosition);
        }

        switch(tolower(FENBoard[i])){
            case '/':
                fenRank--;
                fenFile = 1;
                break;
            
            case 'p':
                //sets the pawn bitboard location bit
                setPawns(getPawns() | boardPosition);
                fenFile++;
                break;
            
            case 'n':
                //sets the knight bitboard location bit
                setKnights(getKnights() | boardPosition);
                fenFile++;
                break;
            
            case 'b':
                //sets the knight bitboard location bit
                setBishops(getBishops() | boardPosition);
                fenFile++;
                break;
            
            case 'r':
                //set the rook bitboard location bit
                setRooks(getRooks() | boardPosition);
                fenFile++;
                break;
            
            case 'q':
                //set the queen bitboard location bit
                setQueens(getQueens() | boardPosition);
                fenFile++;
                break;
            
            case 'k':
                //set the king bitboard location bit
                setKings(getKings() | boardPosition);
                fenFile++;
                break;
            
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                fenFile += FENBoard[i];
                break;
        }
    
    }


}

/// @brief Replaces whitePieces bitboard with provided bitboard
/// @param whiteLocations Bitboard of all white piece locations
void Board::setWhitePieces(uint64_t whiteLocations){
    whitePieces = whiteLocations;
}

/// @brief Replaces blackPieces bitboard with provided bitboard
/// @param blackLocations Bitboard of all black piece locations
void Board::setBlackPieces(uint64_t blackLocations){
    blackPieces = blackLocations;
}

/// @brief Replaces pawnPieces bitboard with provided bitboard
/// @param pawnLocations Bitboard of all pawn piece locations
void Board::setPawns(uint64_t pawnLocations){
    pawnPieces = pawnLocations;
}

/// @brief Replaces knightPieces bitboard with provided bitboard
/// @param knightLocations Bitboard of all knight piece locations
void Board::setKnights(uint64_t knightLocations){
    knightPieces = knightLocations;
}

/// @brief Replaces bishopPieces bitboard with provided bitboard
/// @param bishopLocations Bitboard of all bishop piece locations
void Board::setBishops(uint64_t bishopLocations){
    bishopPieces = bishopLocations;
}

/// @brief Replaces rookPieces bitboard with provided bitboard
/// @param rookLocations Bitboard of all rook piece locations
void Board::setRooks(uint64_t rookLocations){
    rookPieces = rookLocations;
}

/// @brief Replaces queenPieces bitboard with provided bitboard
/// @param queenLocations Bitboard of all queen piece locations
void Board::setQueens(uint64_t queenLocations){
    queenPieces = queenLocations;
}

/// @brief Replaces kingPieces bitboard with provided bitboard
/// @param kingLocations Bitboard of all king piece locations
void Board::setKings(uint64_t kingLocations){
    kingPieces = kingLocations;
}

//----------------------------------------------------

//Helper functions

/// @brief Converts algebraic notation position into a bitboard position
/// @param algebraicInput Algebraic notation chess position e.g. [a-h][1-8]
/// @return Bitboard position indicated by the algebraic input
uint64_t Board::convertToBitboard(std::string algebraicInput){

    std::string validFiles = "abcdefgh";
    char fileChar = tolower(algebraicInput[0]);

    //check if the provided file is in the string of validfiles
    if (validFiles.find(fileChar) == -1){
        throw std::invalid_argument("Invalid file");
    }

    int file = (int)fileChar - 96;

    return convertToBitboard(file, (int)algebraicInput[1]);

}

uint64_t Board::convertToBitboard(int file, int rank){
    if(rank < 1 || rank > 8){
        throw std::invalid_argument("Invalid rank");
    }

    uint64_t resultBoard = uint64_t(1) << ((file - 1) + ((rank - 1) * 8));
    return resultBoard;
}
