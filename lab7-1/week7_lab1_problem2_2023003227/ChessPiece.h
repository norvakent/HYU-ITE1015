#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <string>
using namespace std;

// Enum for piece type identification
enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };

// Chess piece symbol constants
const char PAWN_SYMBOL = 'P';
const char ROOK_SYMBOL = 'R';
const char KNIGHT_SYMBOL = 'N';
const char BISHOP_SYMBOL = 'B';
const char QUEEN_SYMBOL = 'Q';
const char KING_SYMBOL = 'K';

// Board display constants - use MOVABLE to mark valid moves, EMPTY for empty squares
const char MOVABLE = 'O';
const char EMPTY = ' ';

// Forward declaration for Board class
class Board;

class ChessPiece {
    private:
        int row, col;
        char symbol;
        PieceType type;
    
    public:
        // Constructor with position and type parameters
        ChessPiece(int r, int c, PieceType t);

        // Getter functions for accessing piece information
        PieceType getPieceType() const;
        char getSymbol() const;
        int getRow() const;
        int getCol() const;
        
        // Setter functions for modifying piece position
        void setRow(int r);
        void setCol(int c);
        
    protected:
        // Helper functions for show_movable implementations
        
        // Check if the given position is within the chess board boundaries
        bool isWithinBounds(int row, int col) const;
        
        // Check if the given position is empty (no chess piece)
        bool isSquareEmpty(int row, int col, const Board& game_board) const;
        
        // Mark the given position as movable on the display board
        void markSquareAsMovable(int row, int col, char display_board[6][6]) const;
        
        // Check if a piece can move to the given position (within bounds AND empty)
        bool canMoveToSquare(int row, int col, const Board& game_board) const;
        
        // Move continuously in a given direction until hitting a boundary or piece
        void moveInDirection(int dr, int dc, char display_board[6][6], const Board& game_board) const;
};


class Pawn : public ChessPiece {
    public:
        // Constructor with position parameters
        Pawn(int r, int c);

        // Show possible moves for pawn (moves forward one square)
        void show_movable(char display_board[6][6], const Board& game_board);
};

class Rook : public ChessPiece {
    public:
        // Constructor with position parameters
        Rook(int r, int c);

        // Show possible moves for rook (moves in straight lines)
        void show_movable(char display_board[6][6], const Board& game_board);
};

class Knight : public ChessPiece {
    public:
        // Constructor with position parameters
        Knight(int r, int c);

        // Show possible moves for knight (moves in L-shape)
        void show_movable(char display_board[6][6], const Board& game_board);
};

class Bishop : public ChessPiece {
    public:
        // Constructor with position parameters
        Bishop(int r, int c);

        // Show possible moves for bishop (moves diagonally)
        void show_movable(char display_board[6][6], const Board& game_board);
};

class Queen : public ChessPiece {
    public:
        // Constructor with position parameters
        Queen(int r, int c);

        // Show possible moves for queen (moves in straight lines and diagonally)
        void show_movable(char display_board[6][6], const Board& game_board);
};

class King : public ChessPiece {
    public:
        // Constructor with position parameters
        King(int r, int c);

        // Show possible moves for king (moves one square in any direction)
        void show_movable(char display_board[6][6], const Board& game_board);
};

#endif