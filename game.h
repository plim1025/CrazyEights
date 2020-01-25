#ifndef GAME_H
#define GAME_H

#include "card.h"

class Game {
  private:
    Deck cards;
    Card faceup_card;
    Player players[2];
  public:
    Game();
    Game(Deck init_cards, Player init_players[2]);
    ~Game();
    Deck get_cards();
    Player* get_players();
    Card get_faceup_card();
    void set_cards(Deck new_cards);
    void set_players(Player new_players[2]);
    void set_faceup_card(Card new_faceup_card);
    bool check_game_status();
    void print_game_status();
    void flip_top_card();
};

#endif