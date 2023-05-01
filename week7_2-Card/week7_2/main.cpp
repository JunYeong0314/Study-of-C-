#include <iostream>
#include <vector>
#include "Card.hpp"
#include "deck.hpp"
#include <random>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    Deck d;
    Deck selectedCard;
    
    for(int i=1; i<14; i++){
        d.push_front(Card('C', i));
    }
    for(int i=1; i<14; i++){
        d.push_front(Card('D', i));
    }
    for(int i=1; i<14; i++){
        d.push_front(Card('H', i));
    }
    for(int i=1; i<14; i++){
        d.push_front(Card('S', i));
    }
    
    random_device r;
    mt19937 gen(r());
    d.random(gen);
    
    int n=0;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        uniform_int_distribution<int> dis(0, d.size()-1);
        
        Card c = d.pop_front();
        cout << "선택된 카드 " << i << " : " << c.getSuit() << c.getRank() << endl;
        
        if(i == 1){
            selectedCard.push_front(c);
            selectedCard.printDeck();
        }
        else if(i == 2){
            if(c.priorityCard() > selectedCard.frontPriority()){
                selectedCard.push_front(c);
                selectedCard.printDeck();
            }else{
                selectedCard.push_back(c);
                selectedCard.printDeck();
            }
        }
        else{
            selectedCard.printDeck();
            if(c.priorityCard() > selectedCard.frontPriority() && c.priorityCard() > selectedCard.rearPriority()){
                selectedCard.push_front(c);
                selectedCard.printDeck();
            }
            else if(c.priorityCard() < selectedCard.frontPriority() && c.priorityCard() < selectedCard.rearPriority()){
                selectedCard.push_back(c);
                selectedCard.printDeck();
            }
            else{
                while(true){
                    if(c.priorityCard() > selectedCard.frontPriority() && c.priorityCard() < selectedCard.rearPriority()){
                        
                        break;
                    }
                    Card tmp = selectedCard.pop_front();
                    selectedCard.push_back(tmp);
                    selectedCard.printDeck();
                }
                int disFront = abs(c.priorityCard()-selectedCard.frontPriority());
                int disRear = abs(c.priorityCard()-selectedCard.rearPriority());
                  
                if(c.priorityCard() < selectedCard.frontPriority() && c.priorityCard() < selectedCard.rearPriority()){
                    selectedCard.push_back(c);
                    selectedCard.printDeck();
                }
                else if(disFront > disRear){
                    selectedCard.push_front(c);
                    selectedCard.printDeck();
                    selectedCard.sortDeck();
                }else if(disFront < disRear){
                    selectedCard.push_back(c);
                    selectedCard.printDeck();
                    selectedCard.sortDeck();
                }else{
                    selectedCard.push_front(c);
                    selectedCard.printDeck();
                    selectedCard.sortDeck();
                }
            }
            
        }
        
    }
    return 0;
}
