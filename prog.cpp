/*
** Program: CrazyEights
** Author: Paul Lim
** Date: 1/27/2020
** Description: a game that deals cards to players and whoever has the least cards at the end wins
** Input: none
** Output: winner of game
*/

#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

#define DECK_SIZE 52

using namespace std;

int main() {
    string play_again = "1";
    while(play_again == "1") {
        Game game = Game();
        game.deal_cards();
        game.print_game_status();
        do {
            game.start_turn();
            game.print_game_status();
        } while(!game.game_over());

        do {
            cout << "Enter 1 to play again or 0 to exit the program: ";
            getline(cin, play_again);
        } while(play_again != "1" && play_again != "0");
    }


    return 0;
}