#ifndef DECK_H
#define DECK_H
#include <vector>

class Deck {
  private:
    const int nCards = 13;
    const int nSuits = 4;
    const int totalCards = nCards * nSuits;
    std::vector<int> cards;
  
  public:
    Deck();
    void shuffle();
    int pop();
    int getCard(int i) {return cards[i];}
    int getNumCards() {return totalCards;}
    size_t getSize() {return cards.size();}
};

#endif
