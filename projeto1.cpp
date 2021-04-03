#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

class Graph{
    int V;
public:
    Graph(int V);
    int DFS(int s, vector<vector<int>>& edges1);
};

Graph::Graph(int V) {
    this->V = V;
}


int Graph::DFS(int w, vector<vector<int>>& edges1){

    vector<int> father(V, -1);
    vector<int> color(V, WHITE);
    vector<int> nodesDown(V, 1);
    stack<int> stack;
    stack.push(w);
    int s;

    while (!stack.empty()){
        s = stack.top();

        if(color[s] == WHITE){

            color[s] = GREY;

            for(int j = 0; j < int(edges1[s].size()); j++){
                stack.push(edges1[s][j]);
                father[edges1[s][j]] = s;
            }
        }
        else if(color[s] == GREY){
            color[s] = BLACK;
            if(father[s] != -1)
                if(nodesDown[father[s]] < 1 + nodesDown[s])
                    nodesDown[father[s]] = 1 + nodesDown[s];

            stack.pop();
        }

        else{
            if(nodesDown[father[s]] < 1 + nodesDown[s]){
                nodesDown[father[s]] = 1 + nodesDown[s];
            }
            stack.pop();
        }

    }
    return nodesDown[w];
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
    int i, counter = 1, largest = 0;
    for (i = 0; i < numberNodes; i++){
        if (edges2[i].empty() && !edges1[i].empty()){
            counter = g.DFS(i, edges1);
        }
        if (counter > largest){
            largest = counter;
        }
        counter = 1;
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
