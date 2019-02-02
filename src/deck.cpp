#include <cstdlib>
#include "deck.h"

Deck::Deck() {
  for (int card=1; card<=nCards; card++) {
    for (int suit=1; suit<=nSuits; suit++) {
      cards.push_back(card);
    }
  }
}
    
void Deck::shuffle() {
  for (int i=0; i < totalCards; i++) {
    int r = rand() % totalCards;
    int temp = cards[i];
    cards[i] = cards[r];
    cards[r] = temp;
  }
}

int Deck::pop() {
  int card = cards.back();
  cards.pop_back();
  return card;
}
