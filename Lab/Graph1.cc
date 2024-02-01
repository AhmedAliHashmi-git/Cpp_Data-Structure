#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph {
    static const int n = 5; // Number of nodes in the graph
    bool matrix[n][n];      // 2D static array of fixed size for ease

public:
    Graph() {
        // initialize all the values of the matrix to false
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = false;
            }
        }
    }

    void addEdge(int source, int destination, bool bi) {
        // here bool bi means bidirectional or not
        // if true so node 1 should be connected to node 2 and also vice versa
        matrix[destination][source] = true;
        if (bi) {
            matrix[source][destination] = true;
        }
    }

    void removeEdge(int source, int destination, bool bi) {
        matrix[destination][source] = false;
        if (bi) {
            matrix[source][destination] = false;
        }
    }

    void DFS(int start) {
        // here you can use the built-in stack from stack library.
        bool visit[n];
        for(int i = 0 ; i < n ; i++){
            visit[i] = false;
        }
        stack<int> s;
        s.push(start);
        while(!s.empty()){
            int current = s.top();
            s.pop();
            if(!visit[current]){
                cout<<current<<" ";
                visit[current] = true;
            }
            for(int i = 0 ; i < n ; i++){
                if(!visit[i]){
                   s.push(i);
                }
            }
        }
    }

    void BFS() {
        bool visit[n];
        for(int i = 0 ; i < n ; i++){
                visit[i] = false;
        }
        queue<int> q;
        q.push(1);
        while(!q.empty()){
          int current = q.front();
          q.pop();
          if(!visit[current]){
            cout<<current<<" ";
            visit[current] = true;
          }

          for(int i = 0 ; i < n ; i++){
            if(!visit[i]){
                q.push(i);
            }
          }
        }
        cout<<endl;


    }

    void print() {
        for (int i = 0; i < n; ++i) {
            cout << i << ": ";
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    // simple make a graph containing 5 nodes, connect some edges yourself
    // call the print, dfs, and bfs function
    Graph myGraph;

    // Connect some edges
    myGraph.addEdge(0, 1, true);
    myGraph.addEdge(1, 2, true);
    myGraph.addEdge(2, 3, true);
    myGraph.addEdge(3, 4, true);

    // Print the graph
    myGraph.print();
    myGraph.removeEdge(3 ,4 , false);
    myGraph.print();
    myGraph.BFS();
    myGraph.DFS(1);

    return 0;
}
