#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

class Graph{
    int V;
    list <int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    int DFS(int s, int counter, vector<vector<int>>& edges1, vector<vector<int>>& edges2);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
int auxiliar(vector<vector<int>> edges1)

int Graph::DFS(int w, int counter, vector<vector<int>>& edges1, vector<vector<int>>& edges2){

    vector<int> father(V, -1);
    vector<bool> visited(V, false);
    stack<int> stack;
    stack.push(w);
    int aux = 0, depth = 0, s;

    while (!stack.empty()){
        s = stack.top();
        stack.pop();
        aux ++;
        visited[s] = true;

        if((edges1[s].size() == 1 && !stack.empty()))
            depth +=1;

        for(int j = 0; j < int(edges1[s].size()); j++){
            stack.push(edges1[s][j]);
            father[edges1[s][j]] = s;
        }


        if (edges1[s].empty()){

            if (aux > counter){
                counter = aux;
            }

            for(int i = 0; i < (depth + 1); i++)
                aux--;
            depth = 0;
        }
    }
    return counter;
}

void processInput(Graph g, int numberNodes, int numberEdges, vector<vector<int>>& edges1, vector<vector<int>>& edges2){

    int a, b;

    edges1.reserve(numberEdges);
    edges2.reserve(numberEdges);

    for(int i = 0; i < numberNodes; i++){
        edges1.insert(edges1.begin() + i, vector<int>());
        edges2.insert(edges2.begin() + i, vector<int>());
    }
    for(int i = 0; i < numberEdges; i++){
        if(!scanf("%d %d", &a, &b)){
            cout << "Erro" << endl;
        }
        g.addEdge(a - 1, b - 1);
        edges1[a-1].push_back(b-1);
        edges2[b-1].push_back(a);
    }
}

int FindFirstOutput(vector< vector<int>>& edges2, vector<int>& InicialNodes){
    int counter = 0, i;
    for(i = 0; i < int(edges2.size()); i++){
        if(edges2[i].empty()){
            InicialNodes.push_back(i+1);
            counter++;
        }
    }
    return counter;
}

int FindSecondOutput(Graph g,vector<vector<int>>& edges2, vector<vector<int>>& edges1, vector<int>& InicialNodes, int numberNodes){
    int i, counter = 0, largest = 0;
    for (i = 0; i < numberNodes; i++){
        if (edges2[i].empty()){
            counter = g.DFS(i, counter, edges1, edges2);
        }
        if (counter > largest){
            largest = counter;
        }
        counter = 0;
    }
    return largest;
}

int main(){

    int numberNodes, numberEdges, firstOutput, secondOutput;
    vector <vector <int>> edges1, edges2;
    vector<int> InicialNodes;

    if(!scanf("%d %d", &numberNodes, &numberEdges)){
        cout << "Erro" << endl;

    }

    Graph g(numberNodes);
    processInput(g, numberNodes, numberEdges, edges1, edges2);

    firstOutput = FindFirstOutput(edges2, InicialNodes);

    secondOutput = FindSecondOutput(g, edges2, edges1, InicialNodes, numberNodes);

    cout << firstOutput<< " " << secondOutput << endl;

    return 0;
}
