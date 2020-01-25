#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

#define DECK_SIZE 52

using namespace std;

int main() {
    Game game = Game();
    game.deal_cards();
    // game.start_turn();
    game.print_game_status();

    return 0;
}