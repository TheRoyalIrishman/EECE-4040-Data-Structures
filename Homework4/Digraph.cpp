#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <list>
#include <unordered_set>
#include <fstream>

using namespace std;

// WARNING: This is O(n), not O(1) like it is for a vector/array
template<class T>
T& elementAt(list<T>& lList, int index) {
    int i = 0;
    for (T& element : lList) {
        if (i == index) {
            return element;
        }
        ++i;
    }
    throw out_of_range("index out of range");
}

bool hasElement(const list<int>& searchList, int value) {
    for (int element : searchList) {
        if (element == value) {
            return true;
        }
    }
    return false;
}

class Digraph {
    private:
        using node = pair<int, list<int>>;
        vector<node> m_graph;

        // returns -1 if not found
        int indexOf(int node) const {
            for (int i = 0; i < m_graph.size(); ++i) {
                if (m_graph[i].first == node) {
                    return i;
                }
            }
            return -1;
        }

        // determine whether the given node is part of a cycle
        bool hasCycle(int start, unordered_set<int>& visited) const {
            int index = indexOf(start);
            if (index == -1) {
                return false;
            }

            visited.insert(start);
            for (int next : m_graph[index].second) {
                if (visited.find(next) != visited.end()) {
                    return true;
                }
                if (hasCycle(next, visited)) {
                    return true;
                }
            }
            return false;
        }

        bool hasCycle(int start) const {
            unordered_set<int> visited;
            return hasCycle(start, visited);
        }

        void helperFunction(
            list<bool>& mark,
            list<int>& topologicalList,
            int& counter,
            int startNode
        ) const {
            int index = indexOf(startNode);
            if (index == -1) {
                // maybe throw?
                throw out_of_range("index does not exist");
            }
            list<int> adjacencyList = m_graph[index].second;

            for (bool& element : mark) {
                element = true;

                for (node w : m_graph) {
                    if (hasElement(adjacencyList, w.first) && !elementAt(mark, w.first)) {
                        helperFunction(mark, topologicalList, w.first, counter);
                    }
                }
                elementAt(topologicalList, counter) = startNode;
            }
        }

    public:
        // true if it succeeds, false if it fails
        bool addEdge(int first, int second) {
            // find or add the first node
            int index = indexOf(first);
            if (index == -1) {
                index = m_graph.size();
                m_graph.emplace_back(first, list<int>());
            }

            // add the second node if it doesn't exist
            if (indexOf(second) == -1) {
                m_graph.emplace_back(second, list<int>());
            }

            m_graph[index].second.push_front(second);

            // ensure there's no cycle
            if (hasCycle(first)) {
                // oops
                m_graph[index].second.pop_front();
                return false;
            }
            return true;
        }
        void removeEdge(int first, int second) {
            int index = indexOf(first);
            if (index == -1) {
                // Nothing to do. The node doesn't exist, so the edge can't.
                return;
            }
            m_graph[index].second.remove(second);
        }

        list<int> topologicalSort() const {
            // gives us a list with `m_graph.size()` zeros
            list<int> topologicalList(m_graph.size(), 0);
            list<bool> mark(m_graph.size(), false);

            int counter = m_graph.size() - 1;

            int i = 0;
            for (bool& element : mark) {
                if (!elementAt(mark, element)) {
                    helperFunction(mark, topologicalList, i, counter);
                }
                ++i;
            }

            return topologicalList;
        }
};

int main() {
    bool Stay_Alive = true;
    Digraph * New_Digraph = new Digraph();
    string StringTask1;
    string StringTask2;
    string StringTask3;
    string StringTask4;
    string StringTask5;
    string StringTask6;
    string StringTask7;
    string StringTask8;
    cout << "Please Enter 8 tasks" << endl;
    cin >> StringTask1;
    cin >> StringTask2;
    cin >> StringTask3;
    cin >> StringTask4;
    cin >> StringTask5;
    cin >> StringTask6;
    cin >> StringTask7;
    cin >> StringTask8;
    string array[8] = {StringTask1, StringTask2, StringTask3, StringTask4, StringTask5, StringTask6, StringTask7, StringTask8};
    int Option;
    while (Stay_Alive) {
        // Ask for user input
        cout << "Please Enter Number of Option \n1. Add\n2. Remove\n3. Quit" << endl;
        cin >> Option;
        // Based on user input, do the desired function
        switch (Option) {
            case 1:{
                int FirstTask;
                int SecondTask;
                cout << "Please input the first task, then the second task" << endl;
                cin >> FirstTask;
                cin >> SecondTask;
                New_Digraph->addEdge(FirstTask, SecondTask);
                New_Digraph->topologicalSort();
                break;
            }
            case 2:{
                int FirstTask;
                int SecondTask;
                cout << "Please input the first task, then the second task" << endl;
                cin >> FirstTask;
                cin >> SecondTask;
                New_Digraph->removeEdge(FirstTask, SecondTask);
                New_Digraph->topologicalSort();
                break;
            }
            case 3: {
                ofstream outputFile("HW4textFile.txt");
                outputFile << New_Digraph;
                outputFile.close();
                Stay_Alive = false;
                break;
            }
        }
    }
}
