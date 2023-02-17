#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card {
public:
    enum Suit 
    {
        HEARTS,
        DIAMONDS,
        SPADES,
        CLUBS,
        SUIT
    };
    enum Rank 
    {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
        RANK
    };
    Card();
    Card(Suit suit, Rank rank);
    Suit getSuit() const;
    Rank getRank() const;
    string show() const;
    int get_value() const;

private:
    Suit suit_;
    Rank rank_;
};

// Implementations


