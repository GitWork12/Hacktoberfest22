#include <bits/stdc++.h>
using namespace std;

string tboard[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void begin()
{
    cout << "Press the ENTER key to begin:" << endl;
    getchar(); 
    cout << "\n";

    cout << "\n";
    cout << "-----------\n";
    cout << "Tic-Tac-Toe\n";
    cout << "-----------\n";

    cout << "Player 1 has been assigned X\n";
    cout << "Player 2 has been assigned O\n";

    cout << "The tic-tac-toe grid is shown below:\n\n";

    cout << "     |     |      \n";
    cout << "  1  |  2  |  3   \n";
    cout << "   __|_____|__ \n";
    cout << "     |     |      \n";
    cout << "  4  |  5  |  6   \n";
    cout << "   __|_____|__ \n";
    cout << "     |     |      \n";
    cout << "  7  |  8  |  9   \n";
    cout << "     |     |      \n\n";
}

bool winner()
{
    bool winner = false;
    
    if ((tboard[0] == tboard[1]) && (tboard[1] == tboard[2]) && tboard[0] != " ")
    {
        winner = true;
    }
    else if ((tboard[3] == tboard[4]) && (tboard[4] == tboard[5]) && tboard[3] != " ")
    {
        winner = true;
    }
    else if ((tboard[6] == tboard[7]) && (tboard[7] == tboard[8]) && tboard[6] != " ")
    {
        winner = true;
    }

    
    else if ((tboard[0] == tboard[3]) && (tboard[3] == tboard[6]) && tboard[0] != " ")
    {
        winner = true;
    }
    else if ((tboard[1] == tboard[4]) && (tboard[4] == tboard[7]) && tboard[1] != " ")
    {
        winner = true;
    }
    else if ((tboard[2] == tboard[5]) && (tboard[5] == tboard[8]) && tboard[2] != " ")
    {
        winner = true;
    }

    
    else if ((tboard[0] == tboard[4]) && (tboard[4] == tboard[8]) && tboard[0] != " ")
    {
        winner = true;
    }
    else if ((tboard[2] == tboard[4]) && (tboard[4] == tboard[6]) && tboard[2] != " ")
    {
        winner = true;
    }

    return winner;
}

bool filled_cells()
{
    bool filled = true;

    for (int i = 0; i < 9; i++)
    {
        if (tboard[i] == " ")
        {
            filled = false;
        }
    }

    return filled;
}

void ongoing_game()
{
    cout << "     |     |      \n";
    cout << "  " << tboard[0] << "  |  " << tboard[1] << "  |  " << tboard[2] << "\n";
    cout << "   __|_____|__ \n";
    cout << "     |     |      \n";
    cout << "  " << tboard[3] << "  |  " << tboard[4] << "  |  " << tboard[5] << "\n";
    cout << "   __|_____|__ \n";
    cout << "     |     |      \n";
    cout << "  " << tboard[6] << "  |  " << tboard[7] << "  |  " << tboard[8] << "\n";
    cout << "     |     |      \n";
    cout << "\n";
}

void set_position()
{
    cout << "Player " << player << "'s turn now: (Enter cell no.: 1-9)" << endl;
    while (!(cin >> position))
    {
        cout << "Please enter a valid number between 1 and 9." << endl;
    }
    cout << endl;

    while (tboard[position - 1] != " ")
    {
        cout << "Oops, that position is already filled.\nPlease try again!\n";
        cout << "Player " << player << "'s turn now: (Enter cell no.: 1-9): ";
        cin >> position;
        cout << "\n";
    }
}

void mark_position()
{
    if (player % 2 == 1)
    {
        tboard[position - 1] = "X";
    }
    else
    {
        tboard[position - 1] = "O";
    }
}

void change_player()
{
    if (player == 1)
    {
        player++;
    }
    else
    {
        player--;
    }
}

void play_turn()
{
    while (!winner() && !filled_cells())
    {
        set_position();
        mark_position();
        change_player();
        ongoing_game();
    }
}

void finish()
{
    if (winner())
    {
        cout << "CONGRATULATIONS! We have our winner: Player " << player << endl;
    }

    else if (filled_cells())
    {
        cout << "Oops, this round was a tie!" << endl;
    }
}

int num_rows;
int num_cols;
int num_mines;
const int maxlen = 15;
const int maxmines = 40;

char indexToChar(int index)
{
    if (index < 10)
        return index + '0';
    else
        return 'a' + (index - 10);
}

int charToIndex(char ch)
{
    if (ch <= '9')
        return ch - '0';
    else
        return (ch - 'a') + 10;
}

void displayBoard(char gBoard[][maxlen])
{
    cout << "    ";
    for (int i = 0; i < num_cols; i++)
        cout << indexToChar(i) << ' ';
    cout << endl
         << endl;

    for (int i = 0; i < num_cols; i++)
    {
        cout << indexToChar(i) << "   ";
        for (int j = 0; j < num_cols; j++)
            cout << gBoard[i][j] << " ";
        cout << "  " << indexToChar(i);
        cout << endl;
    }

    cout << endl
         << "    ";
    for (int i = 0; i < num_cols; i++)
        cout << indexToChar(i) << ' ';
    cout << endl;

    return;
}

void difficultySelect()
{
    int lvl;
    cout << "Enter the Difficulty Level" << endl;
    cout << "Enter 0 for Easy     (5  * 5  cells and 4 mines)" << endl;
    cout << "Enter 1 for Medium   (7 * 7 cells and 8 mines)" << endl;
    cout << "Enter 2 for Hard     (10 * 10 cells and 16 mines)" << endl;

    cin >> lvl;

    if (lvl == 0)
    {
        num_rows = 5;
        num_cols = 5;
        num_mines = 4;
    }

    if (lvl == 2)
    {
        num_rows = 10;
        num_cols = 10;
        num_mines = 16;
    }

    if (lvl == 1)
    {
        num_rows = 7;
        num_cols = 7;
        num_mines = 8;
    }

    return;
}

bool ValidMove(int row, int column)
{
    return (row >= 0) && (row < num_rows) && (column >= 0) && (column < num_cols);
}
bool MineFound(int row, int col, char board[][maxlen])
{
    return (board[row][col] == '*');
}

void clearBoards(char mBoard[][maxlen], char gBoard[][maxlen])
{
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            gBoard[i][j] = mBoard[i][j] = '.';
    return;
}
void placeMines(char mineBoard[][maxlen], int mines)
{
    int placed = 0;
    while (placed < mines)
    {
        int random = rand() % (num_rows * num_cols);
        int row = random / num_cols;
        int column = random % num_rows;
        if (mineBoard[row][column] == '*')
            continue;
        mineBoard[row][column] = '*';
        placed++;
    }
    return;
}

void changeMinePos(int row, int column, char mBoard[][maxlen])
{
    placeMines(mBoard, 1);
    mBoard[row][column] = '.';
    return;
}

vector<pair<int, int>> getAdj(int row, int column)
{
    vector<pair<int, int>> adj;
    for (int x_var = -1; x_var <= 1; x_var++)
        for (int y_var = -1; y_var <= 1; y_var++)
            if (x_var != 0 || y_var != 0)
                if (ValidMove(row + x_var, column + y_var))
                    adj.push_back(make_pair(row + x_var, column + y_var));
    return adj;
}

int adjMineCount(int row, int col, char mBoard[][maxlen])
{
    vector<pair<int, int>> adj = getAdj(row, col);
    int numMines = 0;
    for (int i = 0; i < adj.size(); i++)
        if (MineFound(adj[i].first, adj[i].second, mBoard))
            numMines++;

    return numMines;
}

void revealAdj(char gBoard[][maxlen], char mBoard[][maxlen], int row, int column, int *nMoves)
{
    (*nMoves)++;
    int numMines = adjMineCount(row, column, mBoard);
    gBoard[row][column] = numMines + '0';

    if (numMines == 0)
    {
        vector<pair<int, int>> adj = getAdj(row, column);
        for (int i = 0; i < adj.size(); i++)
            if (gBoard[adj[i].first][adj[i].second] == '.')
                revealAdj(gBoard, mBoard, adj[i].first, adj[i].second, nMoves);
    }

    return;
}

void markMines(char gBoard[][maxlen], char mBoard[][maxlen], bool won)
{
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            if (gBoard[i][j] == '.' && mBoard[i][j] == '*')
            {
                if (won)
                {
                    gBoard[i][j] = 'F';
                }
                else
                {
                    gBoard[i][j] = '*';
                }
            }
        }
    }
}
void playMinesweeper()
{
    char mBoard[maxlen][maxlen], gBoard[maxlen][maxlen];
    int nMovesTotal = num_rows * num_cols - num_mines, flags = num_mines;

    clearBoards(mBoard, gBoard);
    placeMines(mBoard, num_mines);

    int num_moves = 0;
    bool gameOver = false;

    while (!gameOver)
    {
        displayBoard(gBoard);
        cout << flags << " flags are left" << endl
             << endl;

        char x, y, z;
        cout << "Enter your move (row, column, safe(s) or flag(f)) -> ";
        cin >> x >> y >> z;
        cout << endl;

        int row = charToIndex(x);
        int col = charToIndex(y);

        if (num_moves == 0)
            if (MineFound(row, col, mBoard))
                changeMinePos(row, col, mBoard);

        if (z == 's')
        {
            if (gBoard[row][col] == '.' && mBoard[row][col] == '.')
            {
                revealAdj(gBoard, mBoard, row, col, &num_moves);
                if (num_moves == nMovesTotal)
                {
                    markMines(gBoard, mBoard, true);
                    displayBoard(gBoard);
                    cout << endl
                         << "You won!!! :)" << endl;
                    gameOver = true;
                }
            }
            else if (gBoard[row][col] == '.' && mBoard[row][col] == '*')
            {
                gBoard[row][col] = '*';
                markMines(gBoard, mBoard, false);
                displayBoard(gBoard);
                cout << endl
                     << "You lost! :(" << endl;
                gameOver = true;
            }
            else
            {
                cout << "Illegal move. ";
                if (gBoard[row][col] == 'F')
                    cout << "Cell is a flag. Use f to toggle flag off. ";
                else
                    cout << "Cell is already a number. ";
                cout << endl;
            }
        }

        if (z == 'f')
        {
            if (gBoard[row][col] == '.')
            {
                if (flags != 0)
                {
                    gBoard[row][col] = 'F';
                    flags--;
                }
                else
                {
                    cout << "Illegal move. Too many flags!" << endl;
                }
            }
            else if (gBoard[row][col] == 'F')
            {
                gBoard[row][col] = '.';
                flags++;
            }
            else
            {
                cout << "Illegal move. Cell is a number. " << endl;
            }
        }
    }

    return;
}

int board[4][4];
int dirLine[] = {1, 0, -1, 0};
int dirColumn[] = {0, 1, 0, -1};

pair<int, int> generateUnoccupiedPosition()
{
    int occupied = 1, line, column;
    while (occupied)
    {
        line = rand() % 4;
        column = rand() % 4;
        if (board[line][column] == 0)
        {
            occupied = 0;
        }
    }
    return make_pair(line, column);
}

void addPiece()
{
    pair<int, int> pos = generateUnoccupiedPosition();
    board[pos.first][pos.second] = 2;
}

void newGame()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            board[i][j] = 0;
        }
    }
    addPiece();
}

void printUI()
{
    system("cls");
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] == 0)
            {
                cout << setw(4) << "*";
            }
            else
            {
                cout << setw(4) << board[i][j];
            }
        }
        cout << "\n";
    }
    cout << "n: new game, w: up, s: down, d: right, a: left, q: quit\n";
}

bool canDoMove(int line, int column, int nextLine, int nextColumn)
{
    if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 || board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0)
    {
        return false;
    }
    return true;
}

void applyMove(int direction)
{
    int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
    if (direction == 0)
    {
        startLine = 3;
        lineStep = -1;
    }
    if (direction == 1)
    {
        startLine = 3;
        lineStep = -1;
    }
    int movePossible, canAddPiece = 0;
    do
    {
        movePossible = 0;
        for (int i = startLine; i >= 0 && i < 4; i += lineStep)
        {
            for (int j = startColumn; j >= 0 && j < 4; j += columnStep)
            {
                int nextI = i + dirLine[direction], nextJ = j + dirColumn[direction];
                if (board[i][j] != 0 && canDoMove(i, j, nextI, nextJ))
                {
                    board[nextI][nextJ] += board[i][j];
                    board[i][j] = 0;
                    movePossible = canAddPiece = 1;
                }
            }
        }
    } while (movePossible);

    if (canAddPiece)
    {
        addPiece();
    }
}

int main()
{
    while (true)
    {
        int option;
        cout << "GAMES GALLERY" << endl;
        cout << "1. TIC TAC TOE" << endl;
        cout << "2. Minesweeper" << endl;
        cout << "3. 2048" << endl;
        cout << "4. QUIT" << endl;
        cin >> option;
        if (option == 1)
        {
            begin();
            play_turn();
            finish();
        }
        else if (option == 2)
        {
            srand(time(NULL));
            difficultySelect();
            playMinesweeper();
        }
        else if (option == 3)
        {
            srand(time(0));
            char commandToDir[128];
            commandToDir['s'] = 0;
            commandToDir['d'] = 1;
            commandToDir['w'] = 2;
            commandToDir['a'] = 3;
            newGame();
            while (true)
            {
                printUI();
                char command;
                cin >> command;
                if (command == 'n')
                {
                    newGame();
                }
                else if (command == 'q')
                {
                    break;
                }
                else
                {
                    int currentDirection = commandToDir[command];
                    applyMove(currentDirection);
                }
            }
        }
        else if (option == 4)
        {
            break;
        }
        else
        {
            cout <<"INVALID SELECTED" << endl;
        }
    }
    return 0;
}