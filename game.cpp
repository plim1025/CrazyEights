#include <iostream>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"
#define DECK_SIZE 52

Game::Game() {
    cards = Deck();
    cards.fill_cards();
    cards.shuffle_cards();
    flip_top_card();
    players[0] = Player(Hand(), "Human");
    players[1] = Player(Hand(), "Computer");
    player_turn = 0;
}

Game::Game(const Deck &init_cards, const Player (&init_players)[2]) {
    cards = init_cards;
    players[0] = init_players[0];
    players[1] = init_players[1];
}

Game::~Game() {
    cout << "Game over" << endl;
};

Deck& Game::get_cards() {
    return cards;
}

Player* Game::get_players() {
    return players;
}

Card Game::get_faceup_card() {
    return faceup_card;
}

void Game::set_cards(const Deck &new_cards) {
    cards = new_cards;
}

void Game::set_players(const Player (&new_players)[2]) {
    players[0] = new_players[0];
    players[1] = new_players[1];
}

void Game::set_faceup_card(const Card &new_faceup_card) {
    faceup_card = new_faceup_card;
}

bool Game::check_game_status() {
    // This works since it will return 0 (false) if there are zero cards, else true
    return cards.get_n_cards();
}

void Game::print_game_status() {
    cout << endl << "Card on top of stockpile: Rank: " << faceup_card.get_string_rank() << ", Suit: " << faceup_card.get_string_suit() << endl;
    cout << "Cards left in deck: " << cards.get_n_cards() << endl << endl;
    if(player_turn == 0) {
        // Assuming human player is players[0]
        Hand player_hand = players[0].get_hand();
        cout << "Your hand:" << endl;
        player_hand.print_hand();
    }

}

void Game::flip_top_card() {
    Card* deck = cards.get_cards();
    // Find first valid card in deck
    for(int i = 0; i < DECK_SIZE; i++) {
        if(deck[i].is_valid_card()) {
            faceup_card = deck[i];
            deck[i].reset_card();
            break;
        }
    }
}

void Game::deal_cards() {
    Hand &human_hand = players[0].get_hand();
    cards.deal_card(human_hand, 7);
    Hand &computer_hand = players[1].get_hand();
    cards.deal_card(computer_hand, 7);
}

// void Game::start_turn() {
//     cout <<
// }

// void Game::end_turn() {

// }