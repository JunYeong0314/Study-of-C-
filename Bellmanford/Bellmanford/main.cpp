//
//  main.cpp
//  Bellmanford
//
//  Created by 김준영 on 2023/06/05.
//

#include <iostream>
#include <vector>
#define INF 9999999

using namespace std;

vector<pair<int, int>> Edge[10001];
int n, m, start;
int dist[10001];
bool visited[10001];

void Bellman(){
    dist[start] = 0;
    
    
    for(int i=1; i<= n-1; i++){
        for(int j=0; j<Edge[start].size(); j++){
            
        }
    }
    
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
