#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class Digraph {
    private:
        using node = pair<int, list<int>>;
        vector<node> m_graph;

    public:
        // true if it succeeds, false if it fails
        bool addEdge(int first, int second);
        void removeEdge(int first, int second);
        list<int> topologicalSort() const;
};
