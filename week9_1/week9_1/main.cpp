#include "List.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <locale.h>

using namespace std;

int main(){
    List<string> list;
    HeadNode<string>* L;
    setlocale(LC_ALL, "ko_KR.UTF-8");
    
    L = list.createList();
    list.insertEnd(L, "도라산"); list.insertEnd(L, "임진강"); list.insertEnd(L, "운천");
    list.insertEnd(L, "문산"); list.insertEnd(L, "파주"); list.insertEnd(L, "월릉");
    list.insertEnd(L, "금촌"); list.insertEnd(L, "금릉"); list.insertEnd(L, "운정");
    list.insertEnd(L, "야당"); list.insertEnd(L, "탄현"); list.insertEnd(L, "일산");
    list.insertEnd(L, "풍산"); list.insertEnd(L, "백마"); list.insertEnd(L, "곡산");
    list.insertEnd(L, "대곡"); list.insertEnd(L, "능곡"); list.insertEnd(L, "행신");
    list.insertEnd(L, "강매"); list.insertEnd(L, "화전"); list.insertEnd(L, "수색");
    list.insertEnd(L, "디지털 미디어시티"); list.insertEnd(L, "가좌"); list.insertEnd(L, "홍대입구");
    list.insertEnd(L, "서강대"); list.insertEnd(L, "공덕"); list.insertEnd(L, "효창 공원앞");
    list.insertEnd(L, "용산"); list.insertEnd(L, "이촌"); list.insertEnd(L, "서빙고");
    list.insertEnd(L, "한남"); list.insertEnd(L, "옥수"); list.insertEnd(L, "응봉");
    list.insertEnd(L, "왕십리"); list.insertEnd(L, "청량리"); list.insertEnd(L, "회기");
    list.insertEnd(L, "중랑"); list.insertEnd(L, "상봉"); list.insertEnd(L, "망우");
    list.insertEnd(L, "양원"); list.insertEnd(L, "구리"); list.insertEnd(L, "도농");
    list.insertEnd(L, "양정"); list.insertEnd(L, "덕소"); list.insertEnd(L, "도심");
    list.insertEnd(L, "팔당"); list.insertEnd(L, "운길산"); list.insertEnd(L, "양수");
    list.insertEnd(L, "신원"); list.insertEnd(L, "국수"); list.insertEnd(L, "아신");
    list.insertEnd(L, "양평"); list.insertEnd(L, "오빈"); list.insertEnd(L, "양평");
    list.insertEnd(L, "원덕"); list.insertEnd(L, "용문"); list.insertEnd(L, "지평");
    
    int n;
    cin >> n;
    cin.ignore(); // 첫번째 입력 이후 버퍼에 남아있는 개행문자 무시
            
    vector<vector<string>> v(n);
    string in;
    
        
    for(int i=0; i<n; i++){
        getline(cin, in);
        stringstream ss(in);
        string a,b,c,d;
        ss >> a >> b >> c >> d;
        
        if(a == "MAKE"){
            if(d == ""){
                a = "MAKE2";
                v[i].push_back(a); // a : MAKE2
                v[i].push_back(b); // b : targetName
                v[i].push_back(c); // c : newName
            }
            else{
                v[i].push_back(a); // a : MAKE
                v[i].push_back(b); // b : beforeName
                v[i].push_back(c); // c : afterName
                v[i].push_back(d); // d : newName
            }
    
        }
        else if(a == "RENAME"){
            v[i].push_back(a); // a : RENAME
            v[i].push_back(b); // b : oriName
            v[i].push_back(c); // c : reName
        }
        else if(a == "CLOSE"){
            v[i].push_back(a); // a : CLOSE
            v[i].push_back(b); // b : delName
        }
    }
        
    for(int i=0; i<n; i++){
        if(v[i][0] == "MAKE"){
            list.insertThis(L, v[i][1], v[i][2], v[i][3]);
        }
        else if(v[i][0] == "MAKE2"){
            list.insertThisEnd(L, v[i][1], v[i][2]);
        }
        else if(v[i][0] == "RENAME"){
            list.renameList(L, v[i][1], v[i][2]);
        }
        else if(v[i][0] == "CLOSE"){
            list.deleteNode(L, v[i][1]);
        }
        else{
            cout << "입력 명령어가 잘못되었습니다" << endl;
        }
    }
    
    
    list.printList(L);
    
}
