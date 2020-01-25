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

Game::Game(const Deck &init_cards, const Player (&init_players)[2]) {
    cards = init_cards;
    players[0] = init_players[0];
    players[1] = init_players[1];
}

Game::~Game() {
    cout << "Game destroyed" << endl;
};

Deck Game::get_cards() {
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
    // Assuming human player is players[0]
    Hand player_hand = players[0].get_hand();
    Card *human_cards = player_hand.get_cards();
    cout << "Your hand:" << endl;
    player_hand.print_hand();
    cout << endl << "Card on top of stockpile: " << "Rank: " << faceup_card.get_rank() << " Suit: " << faceup_card.get_suit() << endl;
    cout << "Cards left in deck: " << cards.get_n_cards() << endl;
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