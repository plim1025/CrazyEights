#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

#define DECK_SIZE 52

using namespace std;

int main() {
    Deck deck = Deck();
    deck.fill_cards();
    deck.shuffle_cards();
    Player players[2] = {Player(Hand(), "Human"), Player(Hand(), "Computer")};
    Game game = Game(deck, players);
    game.flip_top_card();
    game.print_game_status();

    return 0;
}