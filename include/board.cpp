#include "board.hpp"

/// @brief Default board class constructor, if no FEN is provided it will use startpos (the default chess starting postition)
Board::Board()
{
    setBoardStateFromFen(startpos);
}

/// @brief Board class to hold and handle bitboards for the current boardstate
/// @param FEN Input FEN string to initialize the board with
Board::Board(std::string FEN)
{
    setBoardStateFromFen(FEN);
}

/// @brief Get the bitboard showing all occupied squares
/// @return Bitboard of all pieces
uint64_t Board::getPopCount()
{
    uint64_t boardState = getWhitePieces() | getBlackPieces();
    return boardState;
}

/// @brief Get the bitboard showing all squares with white pieces
/// @return Bitboard of all white pieces
uint64_t Board::getWhitePieces()
{
    return whitePieces;
}

/// @brief Get the bitboard showing all squares with black pieces
/// @return Bitboard of all black pieces
uint64_t Board::getBlackPieces()
{
    return blackPieces;
}

/// @brief Get the bitboard showing all squares with pawns
/// @return Bitboard of all pawns
uint64_t Board::getPawns()
{
    return pawnPieces;
}

/// @brief Get the bitboard showing all squares with knights
/// @return Bitboard of all knights
uint64_t Board::getKnights()
{
    return knightPieces;
}

/// @brief Get the bitboard showing all squares with bishops
/// @return Bitboard of all bishops
uint64_t Board::getBishops()
{
    return bishopPieces;
}

/// @brief Get the bitboard showing all squares with rooks
/// @return Bitboard of all rooks
uint64_t Board::getRooks()
{
    return rookPieces;
}

/// @brief Get the bitboard showing all squares with queens
/// @return Bitboard of all queens
uint64_t Board::getQueens()
{
    return queenPieces;
}

/// @brief Get the bitboard showing all squares with kings
/// @return Bitboard of all kings
uint64_t Board::getKings()
{
    return kingPieces;
}

/// @brief Get the currently active color
/// @return Bool of the currently active color, 0 = white 1 = black
bool Board::getActiveColor()
{
    return activeColor;
}

/// @brief Get the value of the half move clock
/// @return Int of the half move clock
int Board::getHalfMoveClock()
{
    return halfMoveClock;
}

/// @brief Get the value of the full move counter
/// @return Int of the full move counter
int Board::getFullMoveCounter()
{
    return fullMoveCounter;
}

/// @brief Get the string of the en passant target square
/// @return String of the en passant target square
std::string Board::getEnPassantTargetSquare()
{
    return enPassantTargetSquare;
}

/// @brief Get the bool of if white's kingside rook can castle
/// @return Bool of if white's kingside rook can castle
bool Board::getWhiteKingRookCastle()
{
    return whiteKingRookCastle;
}

/// @brief Get the bool of if white's queenside rook can castle
/// @return Bool of if white's queenside rook can castle
bool Board::getWhiteQueenRookCastle()
{
    return whiteQueenRookCastle;
}

/// @brief Get the bool of if black's kingside rook can castle
/// @return Bool of if black's kingside rook can castle
bool Board::getBlackKingRookCastle()
{
    return blackKingRookCastle;
}

/// @brief Get the bool of if black's queenside rook can castle
/// @return Bool of if black's queenside rook can castle
bool Board::getBlackQueenRookCastle()
{
    return blackQueenRookCastle;
}

/// @brief Set the board state according to the provided FEN
/// @param FEN Forsyth–Edwards Notation string of the boardstate
void Board::setBoardStateFromFen(std::string FEN)
{

    // pop off the first section of the FEN string, which is the current board position
    std::string FENBoard = FEN.substr(0, FEN.find(" "));
    FEN.erase(0, FEN.find(" ") + 1);

    // pop off the next section of the FEN string which is the currently active color
    std::string FENColorToPlay = FEN.substr(0, FEN.find(" "));
    FEN.erase(0, FEN.find(" ") + 1);

    // pop off the next section of the FEN string, for the castling ability
    std::string FENCastlingAbility = FEN.substr(0, FEN.find(" "));
    FEN.erase(0, FEN.find(" ") + 1);

    // pop off the next section of the FEN string, for the en passant target square
    std::string FENEnPassantTargetSquare = FEN.substr(0, FEN.find(" "));
    FEN.erase(0, FEN.find(" ") + 1);

    // pop off the next section of the FEN string, for the half move clock
    std::string FENHalfMoveClock = FEN.substr(0, FEN.find(" "));
    FEN.erase(0, FEN.find(" ") + 1);

    // All thats left of the original FEN string is the full move counter
    std::string FENFullMoveCounter = FEN;

    // Why does FEN start at a8??? I would have assumed it started at a1 and went to h8
    // That seems the most intuitive but w/e I guess

    int fenFile = 1;
    int fenRank = 8;

    uint64_t boardPosition;

    // Iterate through FENBoard string, setting the piece bitboards appropriately
    for (int i = 0; i < FENBoard.length(); i++)
    {
        if(FENBoard[i] == '/'){
            fenRank--;
            fenFile = 1;
        }

        // gets the bitboard position indicated by the current rank and file
        boardPosition = convertToBitboard(fenFile, fenRank);

            // Sets the white or black piece bitboard location bit accordingly
            if(isalpha(FENBoard[i])){
                isupper(FENBoard[i]) ? setWhitePieces(getWhitePieces() | boardPosition) : setBlackPieces(getBlackPieces() | boardPosition);
            }

            switch (FENBoard[i])
            {
            case 'P':
            case 'p':
                // sets the pawn bitboard location bit
                setPawns(getPawns() | boardPosition);
                fenFile++;
                break;

            case 'N':
            case 'n':
                // sets the knight bitboard location bit
                setKnights(getKnights() | boardPosition);
                fenFile++;
                break;

            case 'B':
            case 'b':
                // sets the knight bitboard location bit
                setBishops(getBishops() | boardPosition);
                fenFile++;
                break;

            case 'R':
            case 'r':
                // set the rook bitboard location bit
                setRooks(getRooks() | boardPosition);
                fenFile++;
                break;

            case 'Q':
            case 'q':
                // set the queen bitboard location bit
                setQueens(getQueens() | boardPosition);
                fenFile++;
                break;

            case 'K':
            case 'k':
                // set the king bitboard location bit
                setKings(getKings() | boardPosition);
                fenFile++;
                break;
            
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                fenFile += (FENBoard[i] - '0');
                break;
            
            default:
                break;
            }
        
    }

    // Set the currently active turn provided by the FEN string
    setActiveColor(FENColorToPlay);

    // Set the castling ability provided by the FEN string
    setCastlingAbility(FENCastlingAbility);

    // Set the en passant target square provided by the FEN string
    setEnPassantTargetSquare(FENEnPassantTargetSquare);

    // Set the half move clock provided by the FEN string
    setHalfMoveClock(stoi(FENHalfMoveClock));

    setFullMoveCounter(stoi(FENFullMoveCounter));
}

/// @brief Replaces whitePieces bitboard with provided bitboard
/// @param whiteLocations Bitboard of all white piece locations
void Board::setWhitePieces(uint64_t whiteLocations)
{
    whitePieces = whiteLocations;
    std::cout << "Updating white pieces" << std::endl;
    printDebugHelp(whiteLocations);
}

/// @brief Replaces blackPieces bitboard with provided bitboard
/// @param blackLocations Bitboard of all black piece locations
void Board::setBlackPieces(uint64_t blackLocations)
{
    blackPieces = blackLocations;
    std::cout << "Updating black pieces" << std::endl;
    printDebugHelp(blackLocations);
}

/// @brief Replaces pawnPieces bitboard with provided bitboard
/// @param pawnLocations Bitboard of all pawn piece locations
void Board::setPawns(uint64_t pawnLocations)
{
    pawnPieces = pawnLocations;
    std::cout << "Updating pawns" << std::endl;
    printDebugHelp(pawnLocations);
}

/// @brief Replaces knightPieces bitboard with provided bitboard
/// @param knightLocations Bitboard of all knight piece locations
void Board::setKnights(uint64_t knightLocations)
{
    knightPieces = knightLocations;
    std::cout << "Updating knights" << std::endl;
    printDebugHelp(knightLocations);
}

/// @brief Replaces bishopPieces bitboard with provided bitboard
/// @param bishopLocations Bitboard of all bishop piece locations
void Board::setBishops(uint64_t bishopLocations)
{
    bishopPieces = bishopLocations;
    std::cout << "Updating bishops" << std::endl;
    printDebugHelp(bishopLocations);
}

/// @brief Replaces rookPieces bitboard with provided bitboard
/// @param rookLocations Bitboard of all rook piece locations
void Board::setRooks(uint64_t rookLocations)
{
    rookPieces = rookLocations;
    std::cout << "Updating rooks" << std::endl;
    printDebugHelp(rookLocations);
}

/// @brief Replaces queenPieces bitboard with provided bitboard
/// @param queenLocations Bitboard of all queen piece locations
void Board::setQueens(uint64_t queenLocations)
{
    queenPieces = queenLocations;
    std::cout << "Updating queens" << std::endl;
    printDebugHelp(queenLocations);
}

/// @brief Replaces kingPieces bitboard with provided bitboard
/// @param kingLocations Bitboard of all king piece locations
void Board::setKings(uint64_t kingLocations)
{
    kingPieces = kingLocations;
    std::cout << "Updating kings" << std::endl;
    printDebugHelp(kingLocations);
}

/// @brief Set the color's turn, i.e. white to play, black to play, etc
/// @param colorToSet
void Board::setActiveColor(std::string colorToSet)
{
    if (colorToSet == "w")
    {
        activeColor = 0;
    }
    else if (colorToSet == "b")
    {
        activeColor = 1;
    }
}

/// @brief Set the half move clock to provided int
/// @param providedHalfMove Int to set the half move clock to
void Board::setHalfMoveClock(int providedHalfMove)
{
    halfMoveClock = providedHalfMove;
}

/// @brief Set the full move counter to provided int
/// @param providedFullMove Int to set the full move counter to
void Board::setFullMoveCounter(int providedFullMove)
{
    fullMoveCounter = providedFullMove;
}

/// @brief Set the en passant target square to provided square
/// @param providedEnPassantTargetSquare String to set the en passant target square to
void Board::setEnPassantTargetSquare(std::string providedEnPassantTargetSquare)
{
    enPassantTargetSquare = providedEnPassantTargetSquare;
}

void Board::setCastlingAbility(std::string castlingAbility)
{
    for (int i = 0; i < castlingAbility.length(); i++)
    {
        switch (castlingAbility[i])
        {
        case 'K':
            setWhiteKingRookCastle(1);
            break;

        case 'Q':
            setWhiteQueenRookCastle(1);
            break;

        case 'k':
            setBlackKingRookCastle(1);
            break;

        case 'q':
            setBlackQueenRookCastle(1);
            break;
        }
    }
}

/// @brief Set white's kingside rook's castling ability
/// @param canWhiteKingRookCastle Bool of if white's kingside rook can castle
void Board::setWhiteKingRookCastle(bool canWhiteKingRookCastle)
{
    whiteKingRookCastle = canWhiteKingRookCastle;
}

/// @brief Set white's queenside rook's castling ability
/// @param canWhiteQueenRookCastle Bool of if white's queenside rook can castle
void Board::setWhiteQueenRookCastle(bool canWhiteQueenRookCastle)
{
    whiteQueenRookCastle = canWhiteQueenRookCastle;
}

/// @brief Set black's kingside rook's castling ability
/// @param canBlackKingRookCastle Bool of if black's kingside rook can castle
void Board::setBlackKingRookCastle(bool canBlackKingRookCastle)
{
    blackKingRookCastle = canBlackKingRookCastle;
}

/// @brief Set black's queenside rook's castling ability
/// @param canWhiteQueenRookCastle Bool of if black's queenside rook can castle
void Board::setBlackQueenRookCastle(bool canBlackQueenRookCastle)
{
    blackQueenRookCastle = canBlackQueenRookCastle;
}

//----------------------------------------------------

// Helper functions

/// @brief Converts algebraic notation position into a bitboard position
/// @param algebraicInput Algebraic notation chess position e.g. [a-h][1-8]
/// @return Bitboard position indicated by the algebraic input
uint64_t Board::convertToBitboard(std::string algebraicInput)
{

    std::string validFiles = "abcdefgh";
    char fileChar = tolower(algebraicInput[0]);
    std::cout << fileChar << std::endl;

    // check if the provided file is in the string of validfiles
    if (validFiles.find(fileChar) == -1)
    {
        throw std::invalid_argument("Invalid file");
    }

    int file = (int)fileChar - 96;
    
    if (file < 1 || file > 8){
        throw std::invalid_argument("Invalid file");
    }

    return convertToBitboard(file, (int)algebraicInput[1]);
}

/// @brief Convert given file and rank to bitboard position
/// @param file Int of chess file starting at 1
/// @param rank Int of chess rank starting at 1
/// @return
uint64_t Board::convertToBitboard(int file, int rank)
{
    std::cout << "File: " << file << " Rank: " << rank << std::endl;
    if (rank < 1 || rank > 8)
    {
        throw std::invalid_argument("Invalid rank");
    }
    if (file < 1 || file > 8){
        throw std::invalid_argument("Invalid file");
    }


    int squareIndex = ((rank - 1) * 8) + (file - 1);

    uint64_t resultBoard = (uint64_t)1 << squareIndex;
    return resultBoard;
}

void Board::printDebugHelp(uint64_t input)
{
    std::cout << "Updating with the following bitboard: " << std::endl;
    std::string output = std::bitset<64>(input).to_string();
    std::cout << output.substr(0, 8) << std::endl;
    std::cout << output.substr(8, 8) << std::endl;
    std::cout << output.substr(16, 8) << std::endl;
    std::cout << output.substr(24, 8) << std::endl;
    std::cout << output.substr(32, 8) << std::endl;
    std::cout << output.substr(48, 8) << std::endl;
    std::cout << output.substr(56, 8) << std::endl;
    std::cout << std::endl;
}