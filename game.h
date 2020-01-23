#ifndef GAME_H
#define GAME_H

#include "card.h"

class Game {
  private:
    Deck cards;
    Player players[2];
  public:
    Game();
    Game(Deck init_cards, Player init_players[2]);
    ~Game();
    Deck get_cards();
    Player* get_players();
    void set_cards(Deck new_cards);
    void set_players(Player new_players[2]);
    bool check_game_status();
    void print_game_status();
};

#endif