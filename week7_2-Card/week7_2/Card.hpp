//
//  Card.hpp
//  week7_2
//
//  Created by 김준영 on 2023/04/22.
//

#ifndef Card_hpp
#define Card_hpp

class Card{
private:
    char suit;
    int rank;
public:
    Card(char s, int r);
    char getSuit() const;
    int getRank() const;
    friend bool operator==(const Card& c1, const Card& c2) {
            return (c1.suit == c2.suit && c1.rank == c2.rank);
    }
    int priorityCard();
};

#endif /* Card_hpp */
