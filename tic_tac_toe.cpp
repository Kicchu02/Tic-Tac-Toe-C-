#include<iostream>
using namespace std;

// Product Information
const string title = "Tic Tac Toe";
const string version = "v1.0";
const string author = "Narayana Murthy. B";
const string platform = "Microsoft Windows";
const string architecture = "x86_64";
// //

// Initial Values
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};
bool running = true;
bool isFirstPlayer = true;
// //

// Function Definitions
void displayInfo();
void draw(char[][3]);
void putMarker(int, int);
bool isWinner(char);
void gameLogic();
void retryOrExit();
void resetGame();
// //

void displayInfo()
{
    cout << endl;
    cout << "\t--Product Information--" << endl;
    cout << "Title:\t\t" << title << endl;
    cout << "Version:\t" << version << endl;
    cout << "Author:\t\t" << author << endl;
    cout << "Platform:\t" << platform << endl;
    cout << "Architecture:\t" << architecture << endl;
    cout << endl;
}

void draw(char board[][3]) 
{
    cout << endl;
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "- - - - -" << endl; 
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "- - - - -" << endl; 
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << endl;
}

void putMarker(int row, int col) 
{
    if (row > 3 || row < 0) 
    {
        cout << "Invalid Row" << endl;
        return;
    }
    if (col > 3 || col < 0) 
    {
        cout << "Invalid Column" << endl;
        return;
    }
    if (board[row][col] != ' ') 
    {
        cout << "Cell not available" << endl;
        return;
    }
    board[row][col] = isFirstPlayer ? 'X' : 'O';
    gameLogic();
}

bool isWinner(char c) 
{
    return 
        (board[0][0] == c && board[0][0] == board[0][1] && board[0][0] == board[0][2]) ||
        (board[1][0] == c && board[1][0] == board[1][1] && board[1][0] == board[1][2]) ||
        (board[2][0] == c && board[2][0] == board[2][1] && board[2][0] == board[2][2]) ||

        (board[0][0] == c && board[0][0] == board[1][0] && board[0][0] == board[2][0]) ||
        (board[0][1] == c && board[0][1] == board[1][1] && board[0][1] == board[2][1]) ||
        (board[0][2] == c && board[0][2] == board[1][2] && board[0][2] == board[2][2]) ||

        (board[0][0] == c && board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] == c && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    ;
}

void gameLogic() 
{
    if (isWinner('X')) 
    {
        cout << "Player 1 Won!!!" << endl;
        retryOrExit();
    }
    if (isWinner('O')) 
    {
        cout << "Player 2 Won!!!" << endl;
        retryOrExit();
    }
}

void retryOrExit() 
{
    char c;
    while (true) 
    {        
        cout << "Do you want to play again? (Y/N) : ";
        cin >> c;
        switch (c)
        {
            case 'y': case 'Y':
                resetGame();
                return;
            case 'n': case 'N':
                running = false;
                return;            
            default:
                cout << "Please enter Y or N" << endl;
                continue;
        }
    }    
}

void resetGame() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
            isFirstPlayer = false;
        }    
}

int main() {
    displayInfo();

    cout << "\t--Game--" << endl << endl;
    int r, c;
    while (running)
    {        
        draw(board);
        cout << "Player " << (isFirstPlayer ? "1" : "2") << endl;
        cout << "Enter cell : ";
        cin >> r;
        cin >> c;
        putMarker(r, c);
        isFirstPlayer = !isFirstPlayer;
    }    

    return 0;
}