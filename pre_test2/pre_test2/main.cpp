//
//  main.cpp
//  pre_test2
//
//  Created by 김준영 on 2023/06/14.
//

#include <iostream>
#define V 9
#define INF 9999

using namespace std;

bool *visited = new bool[V];
int *d = new int[V];

int getSmallestNode(){
    int min_value = INF;
    int index = 0;
    
    for(int i=0; i<V; i++){
        if(d[i] < min_value && !visited[i]){
            min_value = d[i];
            index = i;
        }
    }
    
    return index;
}

void dijkstra(int graph[V][V], int start){
    d[start] = 0;
    visited[start] = true;
    
    for(int i=0; i<V; i++){
        if(graph[start][i] != 0){
            d[i] = graph[start][i];
        }
    }
    
    for(int i=0; i<V-1; i++){
        int now = getSmallestNode();
        visited[now] = true;
        
        for(int j=0; j<V; j++){
            if(graph[now][j] != 0){
                int cost = d[now] + graph[now][j];
                if(cost < d[j]){
                    d[j] = cost;
                }
            }
        }
    }
}

int main() {
    for(int i=0; i<V; i++){
        d[i] = INF;
        visited[i] = false;
    }
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);
    
    for(int i=0; i<V; i++){
        cout << "vertex : " << i  << " Distance from Source : " << d[i] << endl;
    }

    return 0;
}
