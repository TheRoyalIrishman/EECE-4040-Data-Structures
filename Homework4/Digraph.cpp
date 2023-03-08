#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

struct DAG_Node {

};

class Digraph {
    private:
        unordered_map<int, vector<int>> digraph; // DAG variable
    
    public:
        void userInterface();
};