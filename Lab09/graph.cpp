#include "graph.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

graph::graph(int numEdge)
{
    this->numEdge = numEdge;

    
    adj = new int*[numEdge];
    for (int i = 0; i < numEdge; i++) 
    {
        adj[i] = new int[numEdge];
        for (int j = 0; j < numEdge; j++)
            adj[i][j] = 0;
    }
}
graph::~graph()
{
    free(adj);
}

void graph::addEdge(int i, int j)
{
    adj[i][j] = 1;
}

void graph::removeEdge(int i, int j)
{
    adj[i][j] = 0;
}

bool graph::hasEdge(int i, int j)
{
    if (adj[i][j] == 1){
      cout << "\nFOUND" <<endl;
      return true;
    } 
    cout<< "\ntry again Dufus" <<endl;
    return false;
}

vector<int> graph::outEdges()
{
  vector<int> out;
  int previ = -1;
  for (int i = 0; i <= numEdge-1 ; i++){
    for (int j = 0 ; j <= numEdge-1 ; j++){
      if (adj[i][j] == 1 && previ != i){
        previ = i;
        out.push_back(i);
      }
    }
  }
  return out;
}

vector<int> graph::inEdges()
{
  vector<int> out;
  int prevj = -1;
  for (int j = 0; j <= numEdge-1 ; j++){
    for (int i = 0 ; i <= numEdge-1 ; i++){
      if (adj[i][j] == 1  && prevj != j){
        prevj = j;
        out.push_back(j);
      }
    }
  }
  return out;
}

bool graph::PrintOutMatrix()
{
    for(int a = 0; a < numEdge; a++){
        for(int b = 0; b < numEdge; b++){
            cout << adj[a][b] << " ";
        }
    cout << endl;
    } 
    return true;
}