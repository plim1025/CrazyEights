#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

#define DECK_SIZE 52

using namespace std;

int main() {
    Card cards[5];
    cards[0].set_suit(1);
    Hand hand = Hand(cards, 5);
    Player player = Player(hand, "player");
    int suit = player.ask_suit();


    return 0;
}