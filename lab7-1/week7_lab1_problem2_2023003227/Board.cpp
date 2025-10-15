#include "Board.h"

Board::Board() {
  for (int i = 0; i < 6; i++ /* TODO: loop through all rows */) {
    for (int j = 0; j < 6; j++ /* TODO: loop through all columns */) {
      // TODO: set current board position to nullptr
      board[i][j] = nullptr;
    }
  }
}

Board::~Board() {
  for (int i = 0; i < 6; i++ /* TODO: loop through all rows */) {
    for (int j = 0; j < 6; j++ /* TODO: loop through all columns */) {
      if (board[i][j] != nullptr/* TODO: check if current position has a chess piece (not nullptr) */) {
        // TODO: deallocate the chess piece object
        delete board[i][j];

        // TODO: set current board position to nullptr
        board[i][j] = nullptr;
      }
    }
  }
}

bool Board::addPiece(int r, int c, PieceType type) {
  if ((r >= 1) && (r <= 5) && (c >= 1) && (c <= 5))
  /* TODO: check if row and column are within valid range (1 to 5) */
  {
    if (board[r][c] != nullptr /* TODO: check if position already has a chess piece (not nullptr) */) {
      return false;
    }

    switch (type /* TODO: piece type parameter */) {
    case PAWN:
      // TODO: create new Pawn object and assign to board position
      board[r][c] = new Pawn(r, c);
      break;
    case ROOK:
      // TODO: create new Rook object and assign to board position
      board[r][c] = new Rook(r, c);
      break;
    case KNIGHT:
      // TODO: create new Knight object and assign to board position
      board[r][c] = new Knight(r, c);
      break;
    case BISHOP:
      // TODO: create new Bishop object and assign to board position
      board[r][c] = new Bishop(r, c);
      break;
    case QUEEN:
      // TODO: create new Queen object and assign to board position
      board[r][c] = new Queen(r, c);
      break;
    case KING:
      // TODO: create new King object and assign to board position
      board[r][c] = new King(r, c);
      break;
    }
    return true; // Successfully added piece
  }
  return false; // Invalid position
}

void Board::removePiece(int r, int c) {
  if ((r >= 1) && (r <= 5) && (c >= 1) && (c <= 5))
  /* TODO: check if row and column are within valid range (1 to 5) */ {
    if (board[r][c] !=
        nullptr /* TODO: check if position has a chess piece (not nullptr) */) {
      // TODO: deallocate the chess piece object
      delete board[r][c];

      // TODO: set board position to nullptr
      board[r][c] = nullptr;
    }
  }
}

ChessPiece *Board::getPieceAt(int r, int c) const {
  if ((r >= 1) && (r <= 5) && (c >= 1) && (c <= 5))
  /* TODO: check if row and column are within board bounds (0 to 5) */ {
    // TODO: return piece at the specified position
    return board[r][c];
  }
  return nullptr;
}

void Board::displayMovesFor(int r, int c) {
  ChessPiece *piece = getPieceAt(r, c);
  if (piece == nullptr) {
    cout << "No piece at this position" << endl;
    return;
  }

  char display_board[6][6];
  display_board[0][0] = '/';
  for (int i = 1; i < 6; i++) {
    display_board[0][i] = 'a' - 1 + i;
    display_board[i][0] = '1' - 1 + i;
  }
  // Initialize board with empty spaces (don't show other pieces)
  for (int i = 1; i < 6; i++) {
    for (int j = 1; j < 6; j++) {
      display_board[i][j] = EMPTY;
    }
  }

  PieceType pieceType = piece->getPieceType();

  switch (pieceType) {
  case PAWN: {
    Pawn *pawn = (Pawn *)piece;
    pawn->show_movable(display_board, *this);
    break;
  }
  case ROOK: {
    Rook *rook = (Rook *)piece;
    rook->show_movable(display_board, *this);
    break;
  }
  case KNIGHT: {
    Knight *knight = (Knight *)piece;
    knight->show_movable(display_board, *this);
    break;
  }
  case BISHOP: {
    Bishop *bishop = (Bishop *)piece;
    bishop->show_movable(display_board, *this);
    break;
  }
  case QUEEN: {
    Queen *queen = (Queen *)piece;
    queen->show_movable(display_board, *this);
    break;
  }
  case KING: {
    King *king = (King *)piece;
    king->show_movable(display_board, *this);
    break;
  }
  }

  for (int j = 5; j >= 0; j--) {
    for (int i = 0; i < 6; i++) {
      cout << display_board[j][i] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void Board::printBoard() const {
  char display_board[6][6];
  display_board[0][0] = '/';
  for (int i = 1; i < 6; i++) {
    display_board[0][i] = 'a' - 1 + i;
    display_board[i][0] = '1' - 1 + i;
  }

  for (int i = 1; i < 6; i++) {
    for (int j = 1; j < 6; j++) {
      if (board[i][j] != nullptr) {
        display_board[i][j] = board[i][j]->getSymbol();
      } else {
        display_board[i][j] = EMPTY;
      }
    }
  }

  for (int j = 5; j >= 0; j--) {
    for (int i = 0; i < 6; i++) {
      cout << display_board[j][i] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}