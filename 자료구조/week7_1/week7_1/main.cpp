#include "Queue.h"
#include <iostream>

using namespace std;

int main(){
    
    for(int i=0; i<2; i++){
        Queue<int> q(9);
        
        int x=0;
        for(int i=0; i<8; i++){
            cin >> x;
            q.Push(x);
        }
        
        int minus = 1, tmp = 0;
        while(true){
            if(minus == 6){
                minus = 1;
            }
            
            tmp = q.Front()-minus;
            minus++;
            if(tmp < 0 || tmp == 0){
                tmp = 0;
                q.Pop();
                q.Push(tmp);
                break;
            }
            q.Pop();
            q.Push(tmp);
        }
        
        cout << "#" << i+1 << " ";
        for(int i=0; i<8; i++){
            q.createPassword();
        }
        cout << endl;
    }
    
}
