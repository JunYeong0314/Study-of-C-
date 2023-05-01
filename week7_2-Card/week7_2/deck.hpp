//
//  deck.hpp
//  week7_2
//
//  Created by 김준영 on 2023/04/22.
//

#ifndef deck_hpp
#define deck_hpp
#include <iostream>
#include <vector>
#include "Card.hpp"
#include <random>


using namespace std;

class Deck{
private:
    vector<Card> cards;
public:
    void push_front(Card c);
    void push_back(Card c);
    Card pop_front();
    Card pop_back();
    Card getFrontCard();
    Card getRearCard();
    char getFront_suit();
    int getFront_rank();
    char getRear_suit();
    int getRear_rank();
    int size() const;
    bool contains(const Card& c) const;
    bool IsEmpty() const;
    void random(mt19937& g);
    void printDeck();
    int frontPriority();
    int rearPriority();
    void sortDeck();
};

#endif /* deck_hpp */
