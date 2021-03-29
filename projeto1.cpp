/* GROUP: 50
 * NAME: Bernardo Castico ist196845
 * NAME: Hugo Rita ist196870
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void processInput(int numberNodes, int numberEdges, vector<vector<int>>& edges1, vector<vector<int>>& edges2){

    int a, b;

    edges1.reserve(numberEdges);
    edges2.reserve(numberEdges);

    for(int i = 0; i < numberNodes; i++){
        edges1.insert(edges1.begin() + i, vector<int>());
        edges2.insert(edges2.begin() + i, vector<int>());
    }
    for(int i = 0; i < numberEdges; i++){
        scanf("%d %d", &a, &b);
        
        edges1[a-1].push_back(b);
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

int FindSecondOutput(vector<vector<int>>& edges2, vector<int>& InicialNodes){
    /*FazerDFS 2 vezes*/
}

int main(){

    int numberNodes, numberEdges, firstOutput, secondOutput;
    vector <vector <int>> edges1, edges2;
    vector<int> InicialNodes;

    scanf("%d %d", &numberNodes, &numberEdges);

    processInput(numberNodes, numberEdges, edges1, edges2);

    firstOutput = FindFirstOutput(edges2, InicialNodes);

    secondOutput = FindSecondOutput(edges1, InicialNodes);

    cout << firstOutput<< " " << secondOutput << endl;

    return 0;
}