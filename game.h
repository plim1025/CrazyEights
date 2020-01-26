#ifndef GAME_H
#define GAME_H

#include "card.h"

class Game {
  private:
    Deck cards;
    Card faceup_card;
    Player players[2];
    int player_turn;
  public:
    Game();
    Game(const Deck &init_cards, const Player (&init_players)[2]);
    ~Game();
    Deck& get_cards();
    Player* get_players();
    Card& get_faceup_card();
    int get_player_turn();
    void set_cards(const Deck &new_cards);
    void set_players(const Player (&new_players)[2]);
    void set_faceup_card(Card &new_faceup_card);
    bool game_over();
    void print_game_status();
    void flip_top_card();
    void deal_cards();
    void start_turn();
    bool card_is_valid(int card_num);
    void end_turn();
    void place_card(int card_num);
    int get_card_num();
    int get_random_card_num();
};

#endif