#include "Board.h"

// Display the main menu options
void showMenu() {
    cout << "\n=== Chess Board Menu ===" << endl;
    cout << "1. Add chess piece" << endl;
    cout << "2. Display board / Show piece moves" << endl;
    cout << "3. Remove chess piece" << endl;
    cout << "4. Exit program" << endl;
    cout << "Choose option: ";
}

// Get piece type from user input (returns -1 if invalid)
PieceType getPieceType() {
    string piece_name;
    cout << "Choose Piece (Pawn/Rook/Knight/Bishop/Queen/King): ";
    if (!(cin >> piece_name)) {
        return (PieceType)-1;
    }
    
    if (piece_name == "Pawn") return PAWN;
    else if (piece_name == "Rook") return ROOK;
    else if (piece_name == "Knight") return KNIGHT;
    else if (piece_name == "Bishop") return BISHOP;
    else if (piece_name == "Queen") return QUEEN;
    else if (piece_name == "King") return KING;
    else {
        cout << "Invalid piece type" << endl;
        return (PieceType)-1;
    }
}

// Get board position from user input (e.g., "a1", "e5")
// Converts to internal coordinates (1-5 range)
bool getPosition(int& row, int& col, const string& prompt = "Position") {
    string coord_symbol;
    cout << prompt << " (e.g., a1-e5): ";
    if (!(cin >> coord_symbol)) {
        return false;
    }
    
    if (coord_symbol.length() != 2) {
        cout << "Invalid position format." << endl;
        return false;
    }
    
    col = coord_symbol[0] - 'a' + 1;
    row = coord_symbol[1] - '1' + 1;
    
    if (col < 1 || row < 1 || col > 5 || row > 5) {
        cout << "Position out of range." << endl;
        return false;
    }
    
    return true;
}

// Handle adding a new piece to the board
void addPiece(Board& board) {
    PieceType pieceType = getPieceType();
    if (pieceType == (PieceType)-1) {
        return;
    }
    
    int row, col;
    if (!getPosition(row, col, "Place at")) {
        return;
    }
    
    if (board.addPiece(row, col, pieceType)) {
        cout << "Piece added." << endl;
    } else {
        cout << "Position already occupied by another piece." << endl;
    }
}

// Handle display options (show all pieces or specific piece moves)
void displayOption(Board& board) {
    cout << "\t1) Show all pieces on board" << endl;
    cout << "\t2) Show possible moves for specific piece" << endl;
    cout << "Choose: ";
    
    int choice;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input" << endl;
        return;
    }
    
    if (choice == 1) {
        board.printBoard();
    } else if (choice == 2) {
        int row, col;
        if (getPosition(row, col, "Show moves for piece at")) {
            board.displayMovesFor(row, col);
        }
    } else {
        cout << "Invalid choice" << endl;
    }
}

// Handle removing a piece from the board
void removePiece(Board& board) {
    int row, col;
    if (getPosition(row, col, "Remove piece at")) {
        board.removePiece(row, col);
        cout << "Piece removed." << endl;
    }
}

int main() {
    Board board;
    int choice;
    
    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addPiece(board);
                break;
            case 2:
                displayOption(board);
                break;
            case 3:
                removePiece(board);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select 1-4." << endl;
        }
    }
    
    return 0;
}