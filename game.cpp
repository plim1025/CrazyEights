#include <iostream>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"
#define DECK_SIZE 52

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
Game::Game() {
    cards = Deck();
    cards.fill_cards();
    cards.shuffle_cards();
    flip_top_card();
    players[0] = Player(Hand(), "You");
    players[1] = Player(Hand(), "Computer");
    player_turn = 0;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
Game::Game(const Deck &init_cards, const Player (&init_players)[2]) {
    cards = init_cards;
    players[0] = init_players[0];
    players[1] = init_players[1];
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
Game::~Game() {
    cout << "Game over" << endl;
};

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
Deck& Game::get_cards() {
    return cards;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
Player* Game::get_players() {
    return players;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
Card& Game::get_faceup_card() {
    return faceup_card;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
int Game::get_player_turn() {
    return player_turn;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::set_cards(const Deck &new_cards) {
    cards = new_cards;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::set_players(const Player (&new_players)[2]) {
    players[0] = new_players[0];
    players[1] = new_players[1];
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::set_faceup_card(Card &new_faceup_card) {
    faceup_card.set_rank(new_faceup_card.get_rank());
    faceup_card.set_suit(new_faceup_card.get_suit());
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
bool Game::game_over() {
    int deck_cards_left = cards.get_n_cards();
    int player0_cards = players[0].get_hand().get_n_cards();
    int player1_cards = players[1].get_hand().get_n_cards();
    if(deck_cards_left == 0) {
        if(player1_cards > player0_cards)
            cout << "You win :D" << endl;
        else if(player1_cards < player0_cards)
            cout << "You lose D:" << endl;
        else
            cout << "Tie game 0_0" << endl;
        return true;
    } else if (player0_cards == 0) {
        cout << "You win :D" << endl;
        return true;
    } else if (player1_cards == 0) {
        cout << "You lose D:" << endl;
        return true;
    } else
        return false;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::print_game_status() {
    cout << endl << "Cards left in deck: " << cards.get_n_cards() << endl;
    string faceup_rank = "";
    if(faceup_card.get_rank() == -1)
        faceup_rank = "any";
    else
        faceup_rank = faceup_card.get_string_rank();
    cout << "Card on top of stockpile: Rank: " << faceup_rank << ", Suit: " << faceup_card.get_string_suit() << endl;
    if(player_turn == 0) {
        // Assuming human player is players[0]
        Hand &player_hand = players[0].get_hand();
        player_hand.print_hand();
    } else if (player_turn == 1) {
        cout << endl <<"Computer has " << players[1].get_hand().get_n_cards() << " cards left" << endl;
    }
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
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

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::deal_cards() {
    Hand &human_hand = players[0].get_hand();
    cards.deal_card(human_hand, 7);
    cout << endl << "Dealt 7 cards to human" << endl;
    Hand &computer_hand = players[1].get_hand();
    cards.deal_card(computer_hand, 7);
    cout << "Dealt 7 cards to computer" << endl;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::start_turn() {
    string card_string = "";
    int card_num = 0;
    // If player has no cards that match faceup one, draw a card
    if(!players[player_turn].check_hand(faceup_card.get_rank(), faceup_card.get_suit())) {
        string player = (player_turn == 0 ? "you" : "computer");
        cout << "No possible cards in hand, " << player << " draw one card." << endl;
        Hand &hand = players[player_turn].get_hand();
        cards.deal_card(hand, 1);
    } else {
        if(player_turn == 0)
            card_num = get_card_num();
        else
            card_num = get_random_card_num();
        place_card(card_num);
    }
    end_turn();
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
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

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
int Game::get_random_card_num() {
    int card_num = 0;
    while(true) {
        if(card_is_valid(card_num))
            return card_num;
        card_num++;
    }
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
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

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::end_turn() {
    if(player_turn == 0)
        player_turn = 1;
    else
        player_turn = 0;
}

/*
 ** Function: Card
 ** Description: Constructor for card
 ** Parameters: n/a
 ** Pre-conditions: n/a
 ** Post-conditions: set rank and suit to zero
*/
void Game::place_card(int card_num) {
    Hand &hand = players[player_turn].get_hand();
    Card *&cards = hand.get_cards();
    int rank = cards[card_num].get_rank();
    int suit = cards[card_num].get_suit();
    string player = (player_turn == 0 ? "You" : "Computer");
    cout << player << " placed card with Rank " << cards[card_num].get_string_rank() << " and Suit " << cards[card_num].get_string_suit() << endl;
    faceup_card.set_rank(rank);
    faceup_card.set_suit(suit);
    hand.remove_card(rank, suit);
    if(rank == 8) {
        int next_suit = players[player_turn].ask_suit();
        faceup_card.set_rank(-1);
        faceup_card.set_suit(next_suit);
    }
}
