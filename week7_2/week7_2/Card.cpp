//
//  Card.cpp
//  week7_2
//
//  Created by 김준영 on 2023/04/22.
//

#include "Card.hpp"
#include <iostream>
#include <cmath>

Card::Card(char s, int r){
    rank = r;
    suit = s;
}

char Card::getSuit() const{
    return suit;
}

int Card::getRank() const{
    return rank;
}

