#include "Card.h"
Card::Card()
{
    suit_ = SUIT;
    rank_ = RANK;
}
Card::Card(Suit suit, Rank rank) : suit_(suit), rank_(rank) {}

Card::Suit Card::getSuit() const 
{ 
    return suit_; 
}
Card::Rank Card::getRank() const 
{ 
    return rank_; 
}

string Card::show() const 
{
    string suitString;
    switch (suit_) {
        case HEARTS:
            suitString = 259;
            break;
        case DIAMONDS:
            suitString = 260;
            break;
        case SPADES:
            suitString = 262;
            break;
        case CLUBS:
            suitString = 261;
            break;
    }

    string rankString;
    switch (rank_) {
        case TWO:
            rankString = "2";
            break;
        case THREE:
            rankString = "3";

            break;
        case FOUR:
            rankString = "4";
            break;
        case FIVE:
            rankString = "5";
            break;
        case SIX:
            rankString = "6";
            break;
        case SEVEN:
            rankString = "7";
            break;
        case EIGHT:
            rankString = "8";
            break;
        case NINE:
            rankString = "9";
            break;
        case TEN:
            rankString = "10";
            break;
        case JACK:
            rankString = "J";
            break;
        case QUEEN:
            rankString = "Q";
            break;
        case KING:
            rankString = "K";
            break;
        case ACE:
            rankString = "A";
            break;
    }

    return rankString + suitString;
}

int Card::get_value() const
{
    int value = 0;
    switch (rank_) 
    {
        case TWO:
            value = 2;
            break;
        case THREE:
            value = 3;
            break;
        case FOUR:
            value = 4;
            break;
        case FIVE:
            value = 5;
            break;
        case SIX:
            value = 6;
            break;
        case SEVEN:
            value = 7;
            break;
        case EIGHT:
            value = 8;
            break;
        case NINE:
            value = 9;
            break;
        case TEN:
            value = 10;
            break;
        case JACK:
            value = 10;
            break;
        case QUEEN:
            value = 10;
            break;
        case KING:
            value = 10;
            break;
        case ACE:
            value = 11;
            break;
    }
    return value;
}
