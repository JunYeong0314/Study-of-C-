#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(){
    int n = 0;
    
    cout << "사각형의 개수 입력 : ";
    cin >> n;
    
    Rectangle *r = new Rectangle[n];
    
    for(int i=0; i<n; i++){
        int x,y,w,h;
        cout << i+1 << "번 사각형" << endl;
        cout << "좌표 x :";
        cin >> x;
        cout << "좌표 y :";
        cin >> y;
        cout << "가로:";
        cin >> w;
        cout << "세로:";
        cin >> h;
        
        r[i] = Rectangle(x,y,w,h,i);
    }
    
    int max_index = 0;
    for(int i=1; i<n; i++){
        if(r[max_index].GetArea() < r[i].GetArea()) max_index = i;
    }
    for(int i=0; i<n; i++){
        cout << r[i] << endl;
    }
    cout << max_index+1 << "번 사각형이 가장 크고, 그 넓이는 " << r[max_index].GetArea() << "이다.";
}
