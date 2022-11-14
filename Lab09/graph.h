#include <string>
#include <vector>
#include <iostream>
using namespace std;

class graph
{
    public:
        graph();
        ~graph();

        void addEdge(int i, int j);
        void removeEdge(int i, int j);
        bool hasEdge();
        int outEdges();
        int inEdges();
        string PrintOutMatrix();

    private:
        vector<int> adj;




};