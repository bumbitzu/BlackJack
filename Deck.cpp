#include "Deck.h"
Deck::Deck() 
{
    currentCard_ = 0;
    for (int suit = Card::HEARTS; suit <= Card::CLUBS; ++suit) 
    {
        for (int rank = Card::TWO; rank <= Card::ACE; ++rank) 
        {
            deck_.push_back(Card(static_cast<Card::Suit>(suit),
                static_cast<Card::Rank>(rank)));
        }
    }
}

void Deck::shuffle() 
{
    currentCard_ = 0;
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(deck_.begin(), deck_.end());
}

Card Deck::dealCard()
{
    if (moreCards()) 
    {
        return deck_[currentCard_++];
    }
    else 
    {
        // throw an exception or return a default card
    }
}

bool Deck::moreCards() const 
{
    return currentCard_ < deck_.size();
}
