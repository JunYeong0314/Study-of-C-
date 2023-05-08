//
//  main.cpp
//  week9_2
//
//  Created by 김준영 on 2023/05/08.
//

#include <iostream>
#include "CList.hpp"
#include <vector>

using namespace std;

int main(){
    int total;
    cin >> total;
    
    vector<HeadNode<int>*> lists(total);
    CList<int> list;
    
    for(int i=0; i<total; i++){
        HeadNode<int>* L;
        L = list.createList();
        
        int n, data;
        cin >> n;
        
        for(int i=0; i<n; i++){
            cin >> data;
            list.addNode(L, data);
        }
        
        lists[i] = L;
    }
    
    int i=1;
    for(auto L : lists){
        cout << "case " << i++ << endl;
        L = list.reverse(L);
        list.printList(L);
    }
}
