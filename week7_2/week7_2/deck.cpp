//
//  deck.cpp
//  week7_2
//
//  Created by 김준영 on 2023/04/22.
//

#include "deck.hpp"
#include <iostream>
#include "Card.hpp"

using namespace std;

void Deck::push_front(Card c){
    cards.insert(cards.begin(), c);
}

void Deck::push_back(Card c){
    cards.push_back(c);
}

Card Deck::pop_front(){
    Card c = cards.front();
    cards.erase(cards.begin());
    return c;
}

Card Deck::pop_back(){
    Card c = cards.back();
    cards.pop_back();
    return c;
}

int Deck::size() const{
    return cards.size();
}

bool Deck::IsEmpty() const{
    return cards.empty();
}

bool Deck::contains(const Card& c) const{
    return (find(cards.begin(), cards.end(), c) != cards.end());
}

void Deck::random(mt19937& g){
    shuffle(cards.begin(), cards.end(), g);
}
