// This file reads the DATA folder and generates the graph objects for each tsp problem.
// The distance functions is inbuilt in the Graph.cpp file

#include <iostream>
#include <limits>
#include <unistd.h>
#include <assert.h>

#include <stdlib.h>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>

#include "Graph.cpp"


using namespace std;

#define MAX_PRIORITY numeric_limits<int>::max()

// Create a new graph object based on the information from the file
Graph* parseEdges(string filename) {
    
    Graph *g = NULL;
    int numNodes;
    string type;
    string line;
    ifstream f (filename.c_str());
    getline(f, line);
    getline(f, line);
    f >> line;
    f >> numNodes;		// read num of nodes

    getline(f, line);
    f >> line;
    f >> type;			// read coord type
    getline(f, line);
    getline(f, line);
    getline(f, line);		// ignore all other lines
    if (f.is_open()) {
        g = new Graph(numNodes, type);
        
        int counter = 0;
        while ( counter < numNodes) {
            float x, y;
	    int node;
            f >> node;             // read node
            f >> x;                // read x-coord
            f >> y;                // read y-coord
            g->addNode(node, x, y);
            
            counter++;
        }
        f.close();
        
    }
    else
        cout << "Could not open file \"" << filename << "\"" << endl;
    
    return g;
}

int main(int argc, char *argv[]){

    	string path = "DATA/";
	Graph *g = parseEdges(path+"berlin52.tsp");
	g->makeEdges();
	g->print();
	return 0;
}

