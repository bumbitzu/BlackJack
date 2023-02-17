#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;
void print_your_cards(vector<Card> cards)
{
	cout << "You -> ";
	for (int i = 0; i < cards.size(); i++)
	{
		cout << cards[i].show() << ", ";
	}
	cout << endl;
}
void print_dealer_cards(vector<Card> cards)
{
	cout << "Dealer -> ";
	for (int i = 0; i < cards.size(); i++)
	{
		cout << cards[i].show()<<", ";
	}
	cout << endl;
}
void print_player_win(vector<Card> your_cards, int Player_val, vector<Card> dealer_cards, int Dealer_val)
{
	cout << "====================================================\n";
	print_your_cards(your_cards);
	cout << "You = " << Player_val << endl;
	cout << endl;
	print_dealer_cards(dealer_cards);
	cout << "Dealer = " << Dealer_val << endl << endl;
	cout << "+ + + + + + +\n";
	cout << "+ You  Win! +\n";
	cout << "+ + + + + + +\n\n";
	cout << "Press any key to continue\n";
	cout << "====================================================\n";
}
void print_dealer_win(vector<Card> your_cards, int Player_val, vector<Card> dealer_cards, int Dealer_val)
{
	cout << "====================================================\n";
	print_your_cards(your_cards);
	cout << "You = " << Player_val << endl;
	cout << endl;
	print_dealer_cards(dealer_cards);
	cout << "Dealer = " << Dealer_val << endl << endl;
	cout << "+ + + + + + + + +\n";
	cout << "+ Dealer  Wins! +\n";
	cout << "+ + + + + + + + +\n\n";
	cout << "Press any key to continue\n";
	cout << "====================================================\n";
}
int main()
{
	Start:
	cout << "Welcome to BlackJack\n====================\nPress 1 to Start\nPress 0 to Exit\n";
	char c;
	c =_getch();
	if (c == '1')
	{
		
		system("cls");
		cout << "Controls:\nQ - Place Bet \"10$\" \nW - Hit\nE - Stop\nPress any key to Start\n";
		c = _getch();
		system("cls");
		int i = 0;
		int credit = 1000;
		int inbet = 0;
		bool stop = false;
		int Player_val = 0;
		int Dealer_val = 0;
		bool lost = 0;
		vector<Card> dealer_cards;
		vector<Card> your_cards;

		do
		{
			system("cls");
			cout <<"Credit:"<< credit <<'$'<<endl<<"==============";
			cout << "\nQ - Place Bet \"10$\" \nW - Hit\nE - Stop\nR - Exit\n";
			cout << "================\n";
			cout << "Chance to Win: 0$\n";
			cout << "================\n";
			c = _getch();
			while(c == 'q')
			{
				system("cls");
				dealer_cards.clear();
				your_cards.clear();
				credit -= 10;
				inbet += (10 * 2);
				cout << "Credit:" << credit << '$' << endl << "==============";
				cout << "\nQ - Place Bet \"10$\" \nW - Hit\nE - Stop\nR - Exit\n";
				cout << "================\n";
				cout << "Chance to Win:"<<inbet<<"$\n";
				cout << "================\n";
				c = _getch();
				while (credit <= 0)
				{
					c = _getch();
					if (c == 'w')
						break;
				}
			}
			if(inbet!=0)
			{
				int Player_Ace = 0;
				int Dealer_Ace = 0;
				while (c == 'w')
				{
					Deck deck;
					deck.shuffle();
					Card card;
					card = deck.dealCard();
					your_cards.push_back(card);
					if (card.get_value()==11)
					{
						Player_Ace++;
					}
					Player_val += card.get_value();
					if (Player_Ace)
					{
						if (Player_val > 21)
						{
							Player_val -= 10;
							Player_Ace--;
						}
					}
					cout << "You -> ";
					cout << card.show() << endl;
					cout << "You = " << Player_val << endl;
					Sleep(1000);
					card = deck.dealCard();
					dealer_cards.push_back(card);
					if (card.get_value() == 11)
					{
						Dealer_Ace++;
					}
					Dealer_val += card.get_value();
					if (Dealer_Ace)
					{
						if (Dealer_val > 21)
						{
							Dealer_val -= 10;
							Dealer_Ace--;
						}
					}
					if (Player_val > 21)
					{
						lost = true;
						system("cls");
						print_dealer_win(your_cards, Player_val, dealer_cards, Dealer_val);
						c = _getch();
						inbet = 0;
						Dealer_val = 0;
						Player_val = 0;
						break;
					}
					if (Player_val == 21)
					{
						system("cls");
						print_player_win(your_cards, Player_val, dealer_cards, Dealer_val);
						c = _getch();
						credit += inbet;
						inbet = 0;
						Dealer_val = 0;
						Player_val = 0;
						break;
					}
					if (Dealer_val == 21)
					{
						lost = true;
						system("cls");
						print_dealer_win(your_cards, Player_val, dealer_cards, Dealer_val);
						inbet = 0;
						Dealer_val = 0;
						Player_val = 0;
						break;
					}
					c = _getch();
					if (c == 'r')
					{
						stop = true;
						break;
					}
					if (c == 'e')
					{
						if (Player_val == Dealer_val)
						{
							system("cls");
							cout << "====================================================\n";
							print_your_cards(your_cards);
							cout << "You = " << Player_val << endl;
							cout << endl;
							print_dealer_cards(dealer_cards);
							cout << "Dealer = " << Dealer_val << endl << endl;
							cout << "= = = = =\n";
							cout << "= Draw! =\n";
							cout << "= = = = =\n\n";
							cout << "Press any key to continue\n";
							cout << "====================================================\n";
							c = _getch();
							credit += (inbet/2);
							inbet = 0;
							Dealer_val = 0;
							Player_val = 0;
							break;
						}
						if (Player_val > Dealer_val )
						{
							if(Player_val <21)
							{
								system("cls");
								print_player_win(your_cards, Player_val, dealer_cards, Dealer_val);
								c = _getch();
								credit += inbet;
								inbet = 0;
								Dealer_val = 0;
								Player_val = 0;
								break;
							}
							if (Dealer_val > 21)
							{
								system("cls");
								print_player_win(your_cards, Player_val, dealer_cards, Dealer_val);
								c = _getch();
								credit += inbet;
								inbet = 0;
								Dealer_val = 0;
								Player_val = 0;
								break;
							}
						}
						if (Player_val < Dealer_val)
						{
							if (Dealer_val <= 21)
							{
								system("cls");
								print_dealer_win(your_cards, Player_val, dealer_cards, Dealer_val);
								c = _getch();
								inbet = 0;
								Dealer_val = 0;
								Player_val = 0;
								break;
							}								
							if (Dealer_val > 21)
							{
								system("cls");
								print_player_win(your_cards, Player_val, dealer_cards, Dealer_val);
								c = _getch();
								credit += inbet;
								inbet = 0;
								Dealer_val = 0;
								Player_val = 0;
								break;
							}							
						}
					}
					while(c != 'w')
					{
						c = _getch();
					}
					if (!deck.moreCards())
						break;
				}
			}
			if (!credit)
			{
				system("cls");
				cout << "======================\nNo More credit!\nPress any key to exit!\n======================\n";
				c =_getch();
				break;
			}			
			if (stop)
			{
				break;
			}
		} while (true);
	}
	else if (c == '0')
		return 0;
	else
	{
		system("cls");
		goto Start;
	}
	return 0;
}