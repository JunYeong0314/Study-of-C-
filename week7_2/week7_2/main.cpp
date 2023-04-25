#include <iostream>
#include <vector>
#include "Card.hpp"
#include "deck.hpp"
#include <random>
#include <algorithm>

using namespace std;

int main(){
    Deck d;
    
    for(int i=1; i<13; i++){
        d.push_front(Card('C', i));
    }
    for(int i=1; i<13; i++){
        d.push_front(Card('D', i));
    }
    for(int i=1; i<13; i++){
        d.push_front(Card('H', i));
    }
    for(int i=1; i<13; i++){
        d.push_front(Card('S', i));
    }
    
    random_device r;
    mt19937 gen(r());
    d.random(gen);
    vector<Card> s_cards; //selected card
    
    int n=0;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        uniform_int_distribution<int> dis(0, d.size()-1);
        Card c = d.pop_front();
        while (find(s_cards.begin(), s_cards.end(), c) != s_cards.end()) {
                   d.push_back(c);
                   c = d.pop_front();
               }
               s_cards.push_back(c);

        cout << "선택된 카드" << i << " : " << c.getSuit() << c.getRank() << endl;
        for(const auto& c : s_cards){
            cout << c.getSuit() << c.getRank() << " ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}
