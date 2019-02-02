#include <iostream>
#include "deck.h"

enum class Guess {higher, lower};

Guess playStrategy(int card) {
  Guess guess;
  if (card < 7) {
    guess = Guess::higher;
  }
  else {
    guess = Guess::lower;
  }
  return guess;
}

int playGame() {

  Deck deck;
  deck.shuffle();

  int round = 0;
  int prevCard = deck.pop();
  while (deck.getSize() > 0) {
    Guess guess = playStrategy(prevCard);
    int card = deck.pop();

    if ((card > prevCard) && (guess == Guess::lower)) {
      break;
    } else if ((card < prevCard) && (guess == Guess::higher)) {
      break;
    }

    prevCard = card;
    round++;
  }
  return round;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
      std::cerr << "Missing command line arguments: <pdf> <runs>" << std::endl;
      return 1;
  }
  int pdf = atoi(argv[1]);
  int runs = atoi(argv[2]);

  srand(time(NULL));
  int sum = 0;
  int count = 0;
  for (int i = 0; i < runs; i++) {
    int score = playGame();
    if (score >= pdf) {
      sum++;
    }
    count++;
  }
  std::cout << sum / (double)count << std::endl;
  return 0;
}
