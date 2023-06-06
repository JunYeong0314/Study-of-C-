#include <iostream>
#include <vector>
#define INF 9999999

using namespace std;

/*
 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
 노드의 개수는 최대 100,000개라고 가정
 */
int n, m, start;
vector<pair<int, int>> graph[100001]; // 각 노드에 연결되어있는 노드에 대한 정보를 담는 배열
bool visited[100001]; // 방문여부 배열
int d[100001]; // 최단 거리 테이블 만들기

int getSmallestNode(){
    int min_value = INF;
    int index = 0;
    
    for(int i=1; i<=n; i++){
        if(d[i] < min_value && !visited[i]){
            min_value = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start){
    d[start] = 0;
    visited[start] = true;
    
    for(int j=0; j<graph[start].size(); j++){
        int adjindex = graph[start][j].first;
        d[adjindex] = graph[start][j].second;
    }
    
    for(int i=0; i<n-1; i++){
        int now = getSmallestNode();
        visited[now] = true;
        
        for(int j=0; j<graph[now].size(); j++){
            int cost = d[now] + graph[now][j].second;
            if(cost < d[graph[now][j].first]){
                d[graph[now][j].first] = cost;
            }
        }
    }
}

int main() {
    cin >> n >> m >> start;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c; // a번 노드에서 b번 노드에서 가는비용이 c
        graph[a].push_back({b, c});
    }
    
    fill_n(d, 100001, INF);
    dijkstra(start);
    
    for(int i=1; i<=n; i++){
        if(d[i] == INF){
            cout << "INFINITY" << endl;
        }
        else{
            cout << d[i] << endl;
        }
    }
    return 0;
}
   
