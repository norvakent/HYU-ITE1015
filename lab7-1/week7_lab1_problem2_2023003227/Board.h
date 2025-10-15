#ifndef BOARD_H
#define BOARD_H

#include "ChessPiece.h"

class Board {
    private:
        // 6x6 board: index 0 for coordinate labels, 1-5 for actual game positions
        ChessPiece* board[6][6];
    
    public:
        // Constructor - initializes board with nullptr
        Board();

        // Destructor - safely deallocates all chess pieces
        ~Board();

        // Add a new chess piece at specified position (row, col: 1-5 range)
        // Returns true if successful, false if position is occupied
        bool addPiece(int row, int col, PieceType type);

        // Remove chess piece at specified position (row, col: 1-5 range)
        void removePiece(int row, int col);

        // Get pointer to piece at specified position (row, col: 1-5 range)
        // Returns nullptr if no piece exists at the position
        ChessPiece* getPieceAt(int row, int col) const;

        // Display possible moves for piece at specified position (row, col: 1-5 range)
        // Shows only the selected piece and marks movable squares with 'O'
        void displayMovesFor(int row, int col);

        // Print current board state to console
        void printBoard() const;
};

#endif