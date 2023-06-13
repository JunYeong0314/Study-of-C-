#include <iostream>
#include <limits.h>
#define V 9
#define INF 9999// 네트워크에 존재하는 노드는 9개라고 가정함

using namespace std;

/*
다음의 스텝을 따라 다익스트라 알고리즘을 구현하시오:

1. 9개의 노드가 존재하는 양방향 그래프를 생성
2. 출발 노드를 0으로 설정
3. 출발 노드를 기준으로 그래프의 모든 노드의 가중치를 무한대로 초기화
4. 현재 방문하고 있는 노드를 기준으로 아직 방문하지 않은 인접 노드를 확인.
5. 현재 노드를 통해 갈 수 있는 거리와 현재 인접 노드가 가진 거리를 비교하여, 현재 노드를 통해 가는 것이 더 짧은 경우 인접 노드의 가중치를 갱신.
6. 방문하지 않은 노드 중에서 가장 최단 거리가 짧은 노드를 선택. 선택된 노드를 방문 처리하고, 위의 과정을 반복.
*/
bool *visited = new bool[V];
int *d = new int[V];

int getSmallestNode(){
    int min_value = INF;
    int index = 0;
    
    for(int i=0; i<9; i++){
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
    
    for(int j=0; j<V; j++){
        if(graph[start][j] != 0){
            d[j] = graph[start][j];
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
        visited[i] = false;
        d[i] = INF;
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
    
/*
Vertex   Distance from Source
0                0
1                4
2                12
3                19
4                21
5                11
6                9
7                8
8                14
*/
}
