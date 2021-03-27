/* GROUP: 50
 * NAME: Bernardo Castico ist196845
 * NAME: Hugo Rita ist196870
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/*void inputReceiver(int *numberNodes, int *numberEdges, list <list <int>> *edges){
    FILE* inputf;
    if ((inputf = fopen("input","r")) == NULL){
        printf("Error: Cannot open file.\n");
        exit(EXIT_FAILURE);
    };

    scanf("%d %d", numberNodes, numberEdges)
}*/

void processInput(FILE *inputf, int *numberNodes, int *numberEdges, vector<vector<int>>& edges1, vector<vector<int>>& edges2){

    int a, b, i;

    fscanf(inpuf,"%d %d", numberNodes, numberEdges);

    edges1.reserve(numberEdges);
    edges2.reserve(numberEdges);

    for(int i = 0; i < numberNodes; i++){
        edges1.insert(edges1.begin() + i, vector<int>());
        edges2.insert(edges2.begin() + i, vector<int>());
    }
    for(int i = 0; i < numberEdges; i++){
        fscanf(inputf,"%d %d", &a, &b);
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

int main(int argc,char* argv[]){

    int *numberNodes, *numberEdges, firstOutput, secondOutput;
    vector <vector <int>> edges1, edges2;
    vector<int> InicialNodes;
    FILE* inputf;

    if ((inputf = fopen("input","r")) == nullptr){
        printf("Error: Cannot open file.\n");
        exit(EXIT_FAILURE);
    };

    processInput(inputf, numberNodes, numberEdges, edges1, edges2);

    firstOutput = FindFirstOutput(edges2, InicialNodes);

    secondOutput = FindSecondOutput(edges1, InicialNodes);

    cout("%d %d", firstOutput, secondOutput);

    return 0;
}