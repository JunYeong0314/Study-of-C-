#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int priority(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

int main(){
    string input, ans = "";
    Stack<char> s;
    char c;
    
    cin >> input;
    
    for(int i=0; i<input.length(); i++){
        c = input[i];
        
        if(c >= 'A' && c <= 'Z'){
            ans += c;
            continue;
        }
        if(s.IsEmpty() || c == '('){
            s.Push(c);
            continue;
        }
        if(c == ')'){
            while(s.Top() != '('){
                ans += s.Top();
                s.Pop();
            }
            s.Pop();
            continue;
        }
        if(priority(s.Top()) < priority(c)){
            s.Push(c);
        }else{
            while(!s.IsEmpty() && priority(s.Top()) >= priority(c)){
                ans += s.Top();
                s.Pop();
            }
            s.Push(c);
        }
    }
    
    while(!s.IsEmpty()){
        ans += s.Top();
        s.Pop();
    }
    
    cout << ans << endl;
    
    return 0;
}
