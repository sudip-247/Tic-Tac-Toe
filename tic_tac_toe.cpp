#include<iostream>
#include <array>
using namespace std;

class tictactoe{
private:
    array<char, 9> board;
    char current_player;

public:
    tictactoe(){
        board.fill(' ');
        current_player = 'X';
    }
void printboard(){
    cout<<"\n";
     for(int row = 0; row < 3; row++) {
        cout<<" " << board[row * 3] << " | "<< board[row * 3 + 1] << " | "<< board[row * 3 + 2] << "\n";
        if(row < 2) cout<<"---|---|---\n";
    }
    cout<< "\n";
}
void printnumber(){
        cout<<"Positions are numbered 1-9 like this:\n";
        cout<<" 1 | 2 | 3 \n---|---|---\n 4 | 5 | 6 \n---|---|---\n 7 | 8 | 9 \n\n";
    }
bool make_move(int pos) {
    if(pos<1 || pos>9 || board[pos-1] !=' '){
        return false;
    }
    board[pos-1] = current_player;
    return true;
}
bool win() {
    static const int winPatterns[8][3]={
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };
    for (auto& pattern : winPatterns) {
        if(board[pattern[0]]!=' ' &&
          board[pattern[0]]==board[pattern[1]] &&
          board[pattern[1]]==board[pattern[2]]) {
          return true;
        }
    }
    return false;
}
bool is_board_full(){
     for(char c : board) {
            if(c ==' ') return false;
    }
    return true;
}
void switch_player(){
    current_player =(current_player=='X') ? 'O' : 'X';
}
char getcurrent_player(){
    return current_player;
}
void play(){
    cout<<"=== Tic Tac Toe ===\n\n";
    printnumber();
    printboard();
    while (true) {
        cout<<"Player"<<current_player<<", enter position (1-9):";
        int pos;
        if (!(cin>> pos)){
            cout<<"Invalid input. Please enter a number.\n";
            cin.clear();
             cin.ignore(10000, '\n');
             continue;
        }

        if (!make_move(pos)){
            cout<<"Invalid move. That position is either taken or out of range. Try again.\n";
            continue;
        }
        printboard();

         if (win()){
             cout<<"Player"<<current_player<<"wins! Congratulations!\n";
             break;
        }

        if (is_board_full()){
        cout<<"It's a draw!\n";
            break;
        }

        switch_player();
    }
}
};

int main(){
    char play_again ='y';
    while(play_again =='y' || play_again == 'Y') {
        tictactoe game;
        game.play();

        cout<<"Play again? (y/n): ";
        cin>>play_again;
    }
    cout<<"Thanks for playing!\n";
    return 0;
}