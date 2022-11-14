#include <string>
#include <vector>
#include <iostream>
using namespace std;

class graph
{
    public:
        graph(int numEdge);
        ~graph();

        void addEdge(int i, int j);
        void removeEdge(int i, int j);
        bool hasEdge(int i, int j);
        vector<int> outEdges();
        vector<int> inEdges();
        bool PrintOutMatrix();

    protected:
        int** adj;
        int numEdge;




};