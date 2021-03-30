/* GROUP: 50
 * NAME: Bernardo Castico ist196845
 * NAME: Hugo Rita ist196870
 */

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph{
    int V;
    list <int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    int DFS(int s, int counter, vector<vector<int>>& edges1);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}


int Graph::DFS(int s, int counter, vector<vector<int>>& edges1){

    vector<bool> visited(V, false);
    stack<int> stack;
    stack.push(s);
    int aux = 0, depth = 0;

    while (!stack.empty()){
        s = stack.top();
        stack.pop();
        aux ++;

        if(edges1[s].size() == 1)
            depth +=1;

        for(int j = 0; j < edges1[s].size(); j++){
            if (!visited[edges1[s][j]])
                stack.push(edges1[s][j]);
        }

        if (edges1[s].empty()){
            if (aux > counter)
                counter = aux;
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
        scanf("%d %d", &a, &b);
        g.addEdge(a - 1, b - 1);
        edges1[a-1].push_back(b-1);
        edges2[b-1].push_back(a);
    }

}

int FindFirstOutput(vector< vector<int>>& edges2, vector<int>& InicialNodes){
    int counter = 0, i;
    for(i = 0; i < edges2.size(); i++){
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
            counter = g.DFS(i, counter, edges1);
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

    scanf("%d %d", &numberNodes, &numberEdges);
    Graph g(numberNodes);
    processInput(g, numberNodes, numberEdges, edges1, edges2);

    firstOutput = FindFirstOutput(edges2, InicialNodes);

    secondOutput = FindSecondOutput(g, edges2, edges1, InicialNodes, numberNodes);

    cout << firstOutput<< " " << secondOutput << endl;

    return 0;
}
