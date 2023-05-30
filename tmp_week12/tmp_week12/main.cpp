#include<iostream>
#include<list>
#include<queue>
#include<stack>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int V);

    void addEdge(int v, int w);

    void BFS(int s);

    void DFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for(int i=0; i<V; i++){
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;
    q.push(s);
    
    while(!q.empty()){
        s = q.front();
        cout << s << " ";
        q.pop();
        
        for(auto i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    delete[] visited;
}

void Graph::DFS(int s) {
    bool *visited = new bool[V];
    for(int i=0; i<V; i++){
        visited[i] = false;
    }
    visited[s] = true;
    
    stack<int> stack;
    stack.push(s);
    
    while(!stack.empty()){
        int v = stack.top();
        stack.pop();
        cout << v << " ";
        
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                stack.push(*i);
            }
        }
    }
    
    delete[] visited;
}

int main() {
    // TODO : 노드 수를 기반으로 그래프를 생성하고, 각 노드 사이에 원하는 간선(edge)를 추가
    // TODO : 구현한 DFS와 BFS를 실행하여 검증
    int V = 5;
    Graph g(V);
    
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(1, 0);
    g.addEdge(3, 0);
    
    cout << "DFS from vertex 2: ";
    g.DFS(2);
    cout << endl;
    cout << "BFS from vertex 2: ";
    g.BFS(2);
    
/*
DFS from vertex 2: 2 4 1 0
BFS from vertex 2: 2 1 4 0
*/

    return 0;
}
