//
//  List.hpp
//  LinkedList
//
//  Created by 김준영 on 2023/06/09.
//

#ifndef List_hpp
#define List_hpp
#include <iostream>
#include <string>

using namespace std;

class List{
public:
    struct Lecture{
        string name;
        int number;
        Lecture* next;
        Lecture* prev;
        
        Lecture(string name, int number) : name(name), number(number), next(nullptr), prev(nullptr){}
    };
    List();
    void addLecture(string name, int number);
    void deleteLecture(int number);
    void displayLecture();
    void reverse();
    Lecture* searchLecture(int number);
    
private:
    Lecture* head;
};

#endif /* List_hpp */
