# include <iostream>
# include <vector>
# include <set>
using namespace std;



/*
Tic Tac Toe C++
*/

vector <vector <int>> board_visited(3, vector <int> (3, -1));

void printboard( vector <vector <string>> &board){
    cout << "\n";
    cout << "Board: \n";
    cout << "          col = 0   col = 1    col = 2 \n";
    cout << "\n";
    for(int i = 0; i < board.size(); i++){
        cout << "row = " << i;
        for(int j = 0; j < board[i].size(); j++){
            cout << "  |  " + board[i][j] << "  |  ";
            
        }
        cout << "\n";
        cout << "        --------------------------------";
        cout << "\n";
        cout << "\n";
    
    }
    cout << "\n";
}

// Check winner or not
bool isWinner(vector <vector <string>> &board, int player1, int player2,  int row, int column){

    // for player 1
    if(player1){
        if(board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X"){
            return true;
        }
        if(board[2][0] == "X" && board[1][1] == "X" && board[0][2] == "X"){
            return true;
        }

        int j;
        for(j = 0; j < 3; j++){
            if(board[row][j] != "X"){
                break;
            }
        }
        if(j == 3){
            return true;
        }
        int i;
        for(i = 0; i < 3; i++){
            if(board[i][column] != "X"){
                break;
            }
        }
        if(i == 3){
            return true;
        }
        return false;
    }
    // for player 2
    else{
        if(board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O"){
            return true;
        }
        if(board[2][0] == "O" && board[1][1] == "O" && board[0][2] == "O"){
            return true;
        }

        int j;
        for(j = 0; j < 3; j++){
            if(board[row][j] != "O"){
                break;
            }
        }
        if(j == 3){
            return true;
        }
        int i;
        for(i = 0; i < 3; i++){
            if(board[i][column] != "O"){
                break;
            }
        }
        if(i == 3){
            return true;
        }
        return false;    
    }
    return false;
}

// filling the value with input
void getPlayerInput(vector <vector<string>> &board, int player1, int player2, int *row_pointer, int *col_pointer ){
    int row, col;
    cout << "Select Row:";
    cin >> row;
    cout << endl;
    cout << "Select Column:"; 
    cin >> col;
    *row_pointer = row;
    *col_pointer = col;
    
    if(player1 == 1){
        if(board_visited[row][col] == -1){
            board[row][col] = "X";
            board_visited[row][col] = 1;
            return;
        }
        else{
            cout << "Already filled the shell Try Again\n";
            getPlayerInput(board, player1, player2, row_pointer, col_pointer);
        }
        
    }
    else{
        if( board_visited[row][col] == -1){
            board[row][col] = "O";
            board_visited[row][col] = 1;
            return;
        }
        else{
            cout << "Already filled the shell Try Again\n";
            getPlayerInput(board, player1, player2, row_pointer, col_pointer);
        }

    }

}

int main(){
    system("CLS");
    vector <vector<string>> board(3, vector <string>(3, " "));
    string player1, player2;
    cout << "Player1:";
    cin >> player1;
    cout << "\n";
    cout << "Player2:";
    cin >> player2;
    cout << "\n";
    
    cout << "Hey " << player1 << "," << player2 << " press 1 to start.. \n";
    int dummy;
    cin >> dummy;
    if(dummy != 1){
        return -1;
    }
    cout << "\n";
    printboard(board);
    string active = player1;
    int row, col;
    int *row_pointer = &row;
    int *col_pointer = &col;
    int shell_left = 9;
    while(shell_left){
        if(active == player1){
            cout << player1 << " your turn\n";
            getPlayerInput(board, 1, 0, row_pointer, col_pointer);
            printboard(board);
            if(isWinner(board, 1, 0, row, col)){
                cout << player1 << " is the winner !!";
                return 0;
            }
            active = player2;
        }
        else{
            cout << player2 << " your turn\n";
            getPlayerInput(board, 0, 1, row_pointer, col_pointer);
            printboard(board);
            if(isWinner(board, 0, 1, row, col)){
                cout << player2 << " is the winner";
                return 0;
            }
            active = player1;
        }
        shell_left = shell_left - 1;
        
    }
    cout << "Draw !! Brrr";
    
}
