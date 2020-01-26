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

Card& Game::get_faceup_card() {
    return faceup_card;
}

int Game::get_player_turn() {
    return player_turn;
}

void Game::set_cards(const Deck &new_cards) {
    cards = new_cards;
}

void Game::set_players(const Player (&new_players)[2]) {
    players[0] = new_players[0];
    players[1] = new_players[1];
}

void Game::set_faceup_card(Card &new_faceup_card) {
    faceup_card.set_rank(new_faceup_card.get_rank());
    faceup_card.set_suit(new_faceup_card.get_suit());
}

void Game::reset_faceup_card() {
    for(int i = 0; i < DECK_SIZE; i++) {
        if(cards.get_cards()[i].is_valid_card())
            set_faceup_card(cards.get_cards()[i]);
    }
}

bool Game::game_over() {
    // This works since it will return 0 (false) if there are zero cards, else true
    return !cards.get_n_cards();
}

void Game::print_game_status() {
    cout << endl << "Cards left in deck: " << cards.get_n_cards() << endl;
    cout << "Card on top of stockpile: Rank: " << faceup_card.get_string_rank() << ", Suit: " << faceup_card.get_string_suit() << endl;
    if(player_turn == 0) {
        // Assuming human player is players[0]
        Hand &player_hand = players[0].get_hand();
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
    cout << "Dealt 7 cards to human" << endl;
    Hand &computer_hand = players[1].get_hand();
    cards.deal_card(computer_hand, 7);
    cout << "Dealt 7 cards to computer" << endl;
}

void Game::start_turn() {
    string card_string = "";
    int card_num = 0;
    // If player has no cards that match faceup one, draw a card
    if(!players[player_turn].check_hand(faceup_card.get_rank(), faceup_card.get_suit())) {
        string player = (player_turn == 0 ? "you" : "computer");
        cout << "No possible cards in hand, " << player << " draw one card." << endl << endl;
        Hand &hand = players[player_turn].get_hand();
        cards.deal_card(hand, 1);
        reset_faceup_card();
    } else {
        if(player_turn == 0)
            card_num = get_card_num();
        else
            card_num = get_random_card_num();
        place_card(card_num);
    }
    end_turn();
}

int Game::get_card_num() {
    string card_string = "";
    int card_num = 0;
    while(true) {
        cout << "Enter the number for the card you want to place: ";
        getline(cin, card_string);
        card_num = atoi(card_string.c_str()) - 1;
        // If card does not match faceup card or if number given is out of range, ask again
        if(!card_is_valid(card_num))
            cout << "Invalid card number. Please enter a card with either rank " << faceup_card.get_string_rank() << " or suit " << faceup_card.get_string_suit() << endl;
        else
            break;
    }
    return card_num;
}

int Game::get_random_card_num() {
    int card_num = 0;
    while(true) {
        if(card_is_valid(card_num))
            return card_num;
        card_num++;
    }
}

bool Game::card_is_valid(int card_num) {
    Hand &hand = players[player_turn].get_hand();
    if(card_num < 0 || card_num > (hand.get_n_cards() - 1))
        return false;
    int rank = faceup_card.get_rank();
    int suit = faceup_card.get_suit();
    int card_rank = hand.get_rank(card_num);
    int card_suit = hand.get_suit(card_num);
    if(rank == card_rank || suit == card_suit)
        return true;
    else
        return false;
}

void Game::end_turn() {
    if(player_turn == 0)
        player_turn = 1;
    else
        player_turn = 0;
}

void Game::place_card(int card_num) {
    Hand &hand = players[player_turn].get_hand();
    Card *&cards = hand.get_cards();

    int rank = cards[card_num].get_rank();
    int suit = cards[card_num].get_suit();
    string player = (player_turn == 0 ? "You" : "Computer");
    cout << player << " placed card with rank " << cards[card_num].get_string_rank() << " and suit " << cards[card_num].get_string_suit() << endl;
    hand.remove_card(rank, suit);
    faceup_card.set_rank(rank);
    faceup_card.set_suit(suit);

}