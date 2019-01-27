#include <iostream>
#include <cstdlib>
#include <vector>

enum class Guess {higher, lower};

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
