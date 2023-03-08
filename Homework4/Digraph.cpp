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

        // returns -1 if not found
        int indexOf(int node) {
            for (int i = 0; i < m_graph.size(); ++i) {
                if (m_graph[i].first == node) {
                    return i;
                }
            }
            return -1;
        }

    public:
        // true if it succeeds, false if it fails
        bool addEdge(int first, int second);
        void removeEdge(int first, int second);
        list<int> topologicalSort() const;
};
