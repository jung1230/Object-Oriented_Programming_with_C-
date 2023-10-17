#include "ChessBoard.hh"
#include "Chess.h"
#include "vector"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include <iostream>

using Student::ChessBoard;

/**
 * @brief
 * Allocates memory on the heap for the board.
 * Remember to initialise all pointers to nullptr.
 * @param numRow
 * Number of rows of the chess board.
 * @param numCol
 * Number of columns of the chessboard
 */
ChessBoard::ChessBoard(int numRow, int numCol){
    numRows = numRow;
    numCols = numCol;
    for(int i = 0; i < numRow; i++){
        board.push_back(std::vector<ChessPiece *>(numCol));
        for(int j = 0; j < numCol; j++){
            board.at(i).at(j) = nullptr;
        }
    }
}

/**
 * @brief
 * Returns an output string stream displaying the layout of the board.
 * An ostringstream is used to automatically handle formatting of integers
 * and special characters into their string representations.
 * @return
 * An output stream containing the full board layout.
 */
std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}

/**
 * @brief
 * Checks if a move is valid without accounting for turns.
 * @param fromRow
 * The row of the piece to be moved.
 * @param fromColumn
 * The column of the piece to be moved.
 * @param toRow
 * The row of the destination position.
 * @param toColumn
 * The column of the destination position.
 * @return
 * Returns true if move may be executed without accounting for turn.
 */
bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn){
    // First, Check whether it is in the bound
    if((fromRow < 0) || (fromColumn < 0) || (toRow < 0) || (toColumn < 0)){
        std::cout << "1" << std::endl;
        return false;

    }
    if((fromRow >= numRows) || (toRow >= numRows) || (fromColumn >= numCols) || (toColumn >= numCols)){
         std::cout << "2" << std::endl;
       return false;

    }
    // Then Check whether there is a piece at the fromRow and fromColumn
    if(board.at(fromRow).at(fromColumn) == nullptr){
         std::cout << "3" << std::endl;
       return false;

    }
    std::cout << "11" << std::endl;
    // Then, Check whether the piece is at the same place
    if((fromRow == toRow) && (fromColumn == toColumn)){
         std::cout << "4" << std::endl;
       return false;

    }
    std::cout << "12" << std::endl;
    // Then Check the piece moved is the right color
    if(board.at(fromRow).at(fromColumn)->getColor() != turn){
        std::cout << "5" << std::endl;
        return false;

    }
    std::cout << "13" << std::endl;
    // Next, Check the destination is same color
    // seg falut here
    if(board.at(toRow).at(toColumn)->getColor() == turn){
        std::cout << "6" << std::endl;
        return false;
    }
    
    // Then use piece's canMoveToLocation to check
    if(board.at(fromRow).at(fromColumn)->canMoveToLocation(toRow, toColumn)){
        std::cout << "7" << std::endl;
        return true;

    }
    else
        return false;
}

/**
         * @brief
         * Allocates memory for a new chess piece and assigns its
         * address to the corresponding pointer in the 'board' variable.
         * Remove any existing piece first before adding the new piece.
         * @param col
         * Color of the piece to be created.
         * @param ty
         * Type of the piece to be created.
         * @param startRow
         * Starting row of the piece to be created.
         * @param startColumn
         * Starting column of the piece to be created.
         */
void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn){
    //  Remove any existing piece first before adding the new piece.
    ChessPiece* existing_piece = getPiece(startRow, startColumn);
    if (existing_piece != nullptr) {
        delete existing_piece; // Delete the existing piece
    }

    // adding new piece with its type
    ChessPiece* new_piece = nullptr;
    if (ty == Pawn) { 
        new_piece = new PawnPiece(*this, col, startRow, startColumn);
    }
    else if (ty == Bishop) { 
        new_piece = new BishopPiece(*this, col, startRow, startColumn);
    }
    else if (ty == Rook) { 
        new_piece = new RookPiece(*this, col, startRow, startColumn);
    }

    // Put the new piece on the board
    board[startRow][startColumn] = new_piece;
}

bool ChessBoard::isPieceUnderThreat(int row, int col) {
    // dummy implementation
    return false;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    // dummy implementation
    return true;
}