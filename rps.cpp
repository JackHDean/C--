#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std;

vector<string> moves {"rock", "paper", "scissors"};
string human_choice;
string computer_choice;


void print_move(string move, vector<string> choices) {
    if (move == choices[0]) {
        cout << move << "\n";
    }
    if (move == choices[1]) {
        cout << move << "\n";
    }
    if (move == choices[2]) {
        cout << move << "\n";
    }
   
}
string get_human_choice(vector<string> choices) {
    string userMove;
    cout << "Please select either rock, paper, or scissors." << "\n";
    transform(userMove.begin(), userMove.end(), userMove.begin(), ::tolower);
    cin >> userMove;
    cout << "You chose: ";
    print_move(userMove, choices);
    return userMove;

}
string get_computer_choice(vector<string> choices) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0,2);
    auto computer_choice = choices[distr(gen)];
    cout << "Computer chose: ";
    print_move(computer_choice, choices);
    return computer_choice;


}

bool beats(string moveA, string moveB) {
    if (moveA == "rock") {
        return moveB == "scissors";
    } if (moveA == "paper") {
        return moveB == "rock";
    } if (moveA == "scissors") {
        return moveB == "paper";
    }
    return false;
}
void game(string player_1, string player_2) {

    bool playerWon = false;
    string winner;

    while (playerWon == false) {
        player_1 = get_human_choice(moves);
        player_2 = get_computer_choice(moves);
         if (beats(player_1, player_2)) {
                winner = "Player";
                playerWon = true;
                break;
         } else if (beats(player_2, player_1)){
                winner = "Computer";
                playerWon = true;
                break;
         }  else {
                cout << "It's a draw! Let's keep playing!\n";
                continue;
                game(human_choice, computer_choice);
         }
    }
    cout << "The winner is: " << winner;

}
int main() {
    game(human_choice, computer_choice);
}

