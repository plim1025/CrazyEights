#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

int main() {
    Card cards[52];
    Deck deck(cards);

    Card cards = deck.get_cards();

    return 0;
}