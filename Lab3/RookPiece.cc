#include "RookPiece.hh"

/**
 * Student implementation of a Rook chess piece.
 * The class is defined within the Student namespace.
 */

using Student::RookPiece;

RookPiece::RookPiece(ChessBoard& board, Color color, int row, int column): ChessPiece(board, color, row, column){
            
}

Type RookPiece::getType(){
    return Type::Rook;
}

bool RookPiece::canMoveToLocation(int row, int col){
    int move_row = row - getRow();
    int move_col = col - getColumn();

    // Rook can only move horizontally or vertically
    if (move_row != 0 && move_col != 0) {
        return false; // Not a valid rook move
    }
    // check for if there is a piece blocking the path
    if (move_row > 0) {
        for (int i = 1; i < move_row; i++) {
            if (_board.getPiece(getRow() + i, getColumn()) != nullptr) {
                return false; 
            }
        }
    } 
    else if (move_row < 0) {
        for (int i = -1; i > move_row; i--) {
            if (_board.getPiece(getRow() + i, getColumn()) != nullptr) {
                return false; 
            }
        }
    } 
    else if (move_col > 0) {
        for (int i = 1; i < move_col; i++) {
            if (_board.getPiece(getRow(), getColumn() + i) != nullptr) {
                return false; 
            }
        }
    } 
    else if (move_col < 0) {
        for (int i = -1; i > move_col; i--) {
            if (_board.getPiece(getRow(), getColumn() + i) != nullptr) {
                return false; 
            }
        }
    }

    return true;
}

const char* RookPiece::toString(){
    if(getColor() == Color::Black)
        return ("U+265D");
    else
        return ("U+2657");
}
