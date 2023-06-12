#include <iostream>
#include <vector>
#define INF 9999999

using namespace std;

int n, m, start;
vector<pair<int, int>> graph[100001];
vector<bool> visited;
vector<int> d;

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
    
    visited.resize(n+1, false);
    d.resize(n+1, INF);
    
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
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
