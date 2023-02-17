#pragma once
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Card.h"

class Deck 
{
private:
    std::vector<Card> deck_;
    int currentCard_;
public:
    Deck();
    void shuffle();
    Card dealCard();
    bool moreCards() const;

};


