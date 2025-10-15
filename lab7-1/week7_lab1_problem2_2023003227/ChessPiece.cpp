#include "ChessPiece.h"
#include "Board.h"

ChessPiece::ChessPiece(int r, int c, PieceType t)
    : /* TODO: initialize row, col, type using initializer list */
      row(r), col(c), type(t) {
  switch (t) {
  case PAWN:
    symbol = PAWN_SYMBOL;
    break;
  case ROOK:
    symbol = ROOK_SYMBOL;
    break;
  case KNIGHT:
    symbol = KNIGHT_SYMBOL;
    break;
  case BISHOP:
    symbol = BISHOP_SYMBOL;
    break;
  case QUEEN:
    symbol = QUEEN_SYMBOL;
    break;
  case KING:
    symbol = KING_SYMBOL;
    break;
  }
}

PieceType ChessPiece::getPieceType() const {
  // TODO: return this piece's type
  return type;
}

char ChessPiece::getSymbol() const {
  // TODO: return the display symbol associated with this piece.
  return symbol;
}

int ChessPiece::getRow() const {
  // TODO: provide the current row position.
  return row;
}

int ChessPiece::getCol() const {
  // TODO: provide the current column position.
  return col;
}

void ChessPiece::setRow(int row) {
  // TODO: update the stored row when the piece moves.
  this->row = row;
}

void ChessPiece::setCol(int col) {
  // TODO: update the stored column when the piece moves.
  this->col = col;
}

bool ChessPiece::isWithinBounds(int row, int col) const {
  return /* TODO: confirm the coordinates stay inside the playable 1~5 range. */
      ((row >= 1) && (row <= 5) && (col >= 1) && (col <= 5)) ? true : false;
}

bool ChessPiece::isSquareEmpty(int row, int col,
                               const Board &game_board) const {
  return /* TODO: ask the board for the piece at (row, col) and test whether the
            slot is empty. (nullptr) */
      game_board.getPieceAt(row, col) == nullptr ? true : false;
}

void ChessPiece::markSquareAsMovable(int row, int col,
                                     char display_board[6][6]) const {
  // TODO: place the MOVABLE marker at (row, col) to highlight a legal move.
  display_board[row][col] = 'O';
}

bool ChessPiece::canMoveToSquare(int row, int col,
                                 const Board &game_board) const {
  return /* TODO: A square is movable if it's both within the board's bounds AND
            empty. Call the appropriate member functions to check these two
            conditions. return true if both are true */
      isWithinBounds(row, col) && isSquareEmpty(row, col, game_board);
}

void ChessPiece::moveInDirection(int dr, int dc, char display_board[6][6],
                                 const Board &game_board) const {
  int new_row = row + dr
      /* TODO: calculate new row using current row and direction dr */;
  int new_col = col + dc
      /* TODO: calculate new column using current column and direction dc */;

  while (isWithinBounds(new_row, new_col)/* TODO: Use a member function to check if new_row and new_col are within bounds */) {
    if (isSquareEmpty(new_row, new_col, game_board)/* TODO: Use a member function to check if the square at the new coordinates is empty. */) {
      // TODO: mark square as movable for new position (use a member function)
      markSquareAsMovable(new_row, new_col, display_board);
      // TODO: update new_row and new_col for next iteration using dr and dc
      new_row += dr;
      new_col += dc;
    } else {
      break; // Piece blocks further movement
    }
  }
}

Pawn::Pawn(int r, int c)
    : ChessPiece(r, c, PAWN) /*TODO : call parent constructor with r,
    c, and PAWN enum type */
{}

// Pawn moves forward one square (row increases by 1)
void Pawn::show_movable(char display_board[6][6], const Board &game_board) {
  int new_row = getRow() + 1;
  int new_col = getCol();

  if (canMoveToSquare(new_row, new_col, game_board)/* TODO: Use the member function that checks if a piece can move to the new coordinates */) {
    // TODO: mark square as movable for new position (use a member function)
    markSquareAsMovable(new_row, new_col, display_board);
  }

  // TODO: set current position on display_board to current piece's symbol
  display_board[getRow()][getCol()] = getSymbol();
}

Rook::Rook(int r, int c)
    : ChessPiece(r, c, ROOK) /* TODO: call parent constructor with r, c, and
                                ROOK enum type */
{}

// Rook moves in straight lines: horizontally and vertically
void Rook::show_movable(char display_board[6][6], const Board &game_board) {
  // TODO: Mark all possible moves along the four straight directions
  // (horizontally and vertically). Hint: Call the member function designed to
  // trace a path **four times** in a given direction until blocked. Hint: The
  // four directions can be represented as (0, 1), (0, -1), (1, 0), (-1, 0).
  moveInDirection(0, 1, display_board, game_board);
  moveInDirection(0, -1, display_board, game_board);
  moveInDirection(1, 0, display_board, game_board);
  moveInDirection(-1, 0, display_board, game_board);

  // TODO: set current position on display_board to current piece's symbol
  display_board[getRow()][getCol()] = getSymbol();
}

Knight::Knight(int r, int c)
    : ChessPiece(r, c, KNIGHT) /* TODO : call parent constructor with r,
    c, and KNIGHT enum type */
{}

// Knight moves in L-shape: 2 squares in one direction, then 1 square
// perpendicular
void Knight::show_movable(char display_board[6][6], const Board &game_board) {
  // moves[i][0] = row offset, moves[i][1] = column offset for all 8 L-shaped
  // moves
  int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                     {1, -2},  {1, 2},  {2, -1},  {2, 1}};

  for (int i = 0; i < 8; i++) {
    // calculate new position using current position and moves array
    int new_row = getRow() + moves[i][0] /* TODO */;
    int new_col = getCol() + moves[i][1] /* TODO */;

    if (canMoveToSquare(new_row, new_col, game_board)/* TODO: Use the member function that checks if a piece can move to the new coordinates */) {
      // TODO: mark square as movable for new position (use a member function)
      markSquareAsMovable(new_row, new_col, display_board);
    }
  }

  // TODO: set current position on display_board to current piece's symbol
  display_board[getRow()][getCol()] = getSymbol();
}

Bishop::Bishop(int r, int c)
    : ChessPiece(r, c, BISHOP) /* TODO: call parent constructor with r, c, and
                                  BISHOP enum type */
{}

// Bishop moves diagonally in straight lines
void Bishop::show_movable(char display_board[6][6], const Board &game_board) {
  // TODO: Mark all possible moves for the Bishop along the four diagonal
  // directions Hint: The logic is identical to the Rook's but for diagonal
  // directions Hint: The four diagonal directions can be represented as (1, 1),
  // (1, -1), (-1, 1), (-1, -1)
  moveInDirection(1, 1, display_board, game_board);
  moveInDirection(1, -1, display_board, game_board);
  moveInDirection(-1, 1, display_board, game_board);
  moveInDirection(-1, -1, display_board, game_board);

  // TODO: set current position on display_board to current piece's symbol
  display_board[getRow()][getCol()] = getSymbol();
}

Queen::Queen(int r, int c)
    : ChessPiece(r, c, QUEEN) /* TODO: call parent constructor with r, c, and
                                 QUEEN enum type */
{}

// Queen combines Rook and Bishop moves: all 8 directions in straight lines
void Queen::show_movable(char display_board[6][6], const Board &game_board) {
  // TODO: Mark all possible moves for the Queen in all 8 directions
  // Hint: The logic is a combination of the Rook's and Bishop's
  // Hint: call the member function for all 8 directions (call it 8 times)
  // Straight: (0, 1), (0, -1), (1, 0), (-1, 0)
  // Diagonal: (1, 1), (1, -1), (-1, 1), (-1, -1)
  moveInDirection(0, 1, display_board, game_board);
  moveInDirection(0, -1, display_board, game_board);
  moveInDirection(1, 0, display_board, game_board);
  moveInDirection(-1, 0, display_board, game_board);
  moveInDirection(1, 1, display_board, game_board);
  moveInDirection(1, -1, display_board, game_board);
  moveInDirection(-1, 1, display_board, game_board);
  moveInDirection(-1, -1, display_board, game_board);

  // TODO: set current position on display_board to current piece's symbol
  display_board[getRow()][getCol()] = getSymbol();
}

King::King(int r, int c)
    : ChessPiece(r, c, KING) /* TODO: call parent constructor with r, c, and
                                KING enum type */
{}

// King moves one square in any direction (8 adjacent squares)
void King::show_movable(char display_board[6][6], const Board &game_board) {
  // moves[i][0] = row offset, moves[i][1] = column offset for all 8 adjacent
  // moves
  int moves[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                     {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  for (int i = 0; i < 8; i++) {
    // calculate new position using current position and moves array
    int new_row = getRow() + moves[i][0] /* TODO */;
    int new_col = getCol() + moves[i][1] /* TODO */;

    if (canMoveToSquare(new_row, new_col, game_board)/* TODO: Use the member function that checks if a piece can move to the new coordinates */) {
      // TODO: mark square as movable for new position (use a member function)
      markSquareAsMovable(new_row, new_col, display_board);
    }
  }

  // TODO: set current position on display_board to current piece's symbol
  display_board[getRow()][getCol()] = getSymbol();
}