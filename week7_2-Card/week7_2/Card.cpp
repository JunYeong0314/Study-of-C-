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

int Card::priorityCard(){
    int priority = 0;
    
    if(suit == 'S'){
        priority = 52 - rank;
    }else if(suit == 'D'){
        priority = 39 - rank;
    }else if(suit == 'H'){
        priority = 26 - rank;
    }else{
        priority = 13 - rank;
    }
    return priority;
}

char Card::getSuit() const{
    return suit;
}

int Card::getRank() const{
    return rank;
}

