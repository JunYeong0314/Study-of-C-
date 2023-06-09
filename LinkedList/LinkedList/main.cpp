//
//  main.cpp
//  LinkedList
//
//  Created by 김준영 on 2023/06/09.
//

#include <iostream>
#include "List.hpp"

int main() {
    List myList;
    myList.addLecture("Data Structures", 101);
    myList.addLecture("Algorithms", 102);
    myList.addLecture("Operating Systems", 201);
    myList.addLecture("Computer Networks", 202);
    
    cout << "initial List :" << endl;
    myList.displayLecture();
    
    myList.deleteLecture(102);
    
    cout << "After removing Lecture 102: " << endl;
    myList.displayLecture();
    
    return 0;
}
