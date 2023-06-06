#ifndef graph_hpp
#define graph_hpp
#include <list>
#include <iostream>
#define INF = 99999

using namespace std;

struct Edge{
    int vertex;
    int adjvertex;
    int weight;
    
    Edge(int u, int v, int wt){
        vertex = u;
        adjvertex = v;
        weight = wt;
    }
};

class Mygraph{
public:
    int N;
    list<Edge>* graph;
    int* previous;
    Mygraph(list<Edge>* adj);
    int* shortestPath(int s);
};

#endif /* graph_hpp */
