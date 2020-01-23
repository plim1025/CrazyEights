#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"
#define DECK_SIZE 52

Game::Game() {
    cards = Deck();
    players[0] = Player();
    players[1] = Player();
}

Game::Game(Deck init_cards, Player init_players[2]) {
    cards = init_cards;
    players[0] = init_players[0];
    players[1] = init_players[1];
}

Game::~Game() {};

Player* Game::get_players() {
    return players;
}

void Game::set_cards(Deck new_cards) {
    cards = new_cards;
}

void Game::set_players(Player new_players[2]) {
    players[0] = new_players[0];
    players[1] = new_players[1];
}

bool Game::check_game_status() {
    // This works since it will return 0 (false) if there are zero cards, else true
    return cards.get_n_cards();
}

void Game::print_game_status() {
    // Assuming human player is players[0]
    Hand player_hand = players[0].get_hand();
    Card *human_cards = cards.get_cards();
    cout << "Your hand:" << endl;
    player_hand.print_hand();
    cout << endl << "Card on top of stockpile: ";
    for(int i = 0; i < DECK_SIZE; i++) {
        if(human_cards[i].is_valid_card()) {
            cout << "Rank: " << human_cards[i].get_rank() << " Suit: " << human_cards[i].get_suit() << endl;
            break;
        }
    }
}
