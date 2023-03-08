#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
#include <list>

using namespace std;

struct DAG_Node {

};

class Digraph {
    private:
        unordered_map<int, vector<int>> digraph; // DAG variable
    
    public:
        // true if it succeeds, false if it fails
        bool addEdge(int first, int second);
        void removeEdge(int first, int second);
        list<int> topologicalSort() const;
};
