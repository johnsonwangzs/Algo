#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MAX_N 2005
#define TYPE_LENGTH 7
#define MAX_W 65535

int typeDistance[MAX_N][MAX_N];
char truckTypes[MAX_N][TYPE_LENGTH];

int calDist(char *p, char *q);
int Prim(int AdjMat[][MAX_N], int n);

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> truckTypes[i];
        }
        // calculate the distance between every two truck types
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                typeDistance[i][j] = calDist(truckTypes[i], truckTypes[j]);
            }
        }
        // the type distance describes the weight of edge, as same as the adjacency matrix
        // using Prim method to generate a MST in the 'graph', where the nodes in it are truck types.
        printf("The highest possible quality is 1/%d.\n", Prim(typeDistance, n));
        cin >> n;
    }
}

int calDist(char *p, char *q) {
    int dist = 0;
    for (int i = 0; i < TYPE_LENGTH; i++) {
        if (p[i] != q[i]) {
            dist ++;
        }
    }
    return dist;
}

int Prim(int adjMat[][MAX_N], int n) {
    /*  
        Divide the nodeset to two subset: definite nodeset and indefinite nodeset.
        The definite nodeset contains nodes which will definitely appear in the MST.
        The indefinite nodeset contains nodes, the edge between those nodes and the 
        nodes in the definite set have not been determined. 
    */
    int nodeWeight[MAX_N];  // record min edge weight from each node to the definite nodeset
    int linkNode[MAX_N];  // for each node, record the related node according to edge in array minNodeWeight
    int totalEdgeWeight = 0;  // the total edge weight of the generated MST
    // start by putting the index=0 node in the definite nodeset
    linkNode[0] = -1;  // -1 means that a node is already put in the definite nodeset
    for (int i = 1; i < n; i++) {  // initialize nodes in the indefinite nodeset
        nodeWeight[i] = adjMat[0][i];
        linkNode[i] = 0;
    }
    /*  
        In n-1 round loop, all of the n-1 edges can be add to the MST.
        That means, in every loop, a single node will be moved from 
        the indefinite nodeset to the definite nodeset.
    */
    for (int i = 1; i < n; i++) {
        int minNodeWeight = MAX_W, tmpNodeId = 0;
        // Consider every node, find the minimum nodeWeight.
        for (int j = 1; j < n; j++) {
            if (linkNode[j] != -1) {
                if (minNodeWeight > nodeWeight[j]) {
                    minNodeWeight = nodeWeight[j];
                    tmpNodeId = j;
                }
            }
        }
        // Select the chosen node, move it to the definite nodeset
        linkNode[tmpNodeId] = -1;
        totalEdgeWeight += minNodeWeight;
        /*
            For each node in the indefinite nodeset, 
            update their recorders after a node is moved to the definite nodeset.
        */
        for (int j = 1; j < n; j++) {
            if (linkNode[j] != -1) {
                if (nodeWeight[j] > adjMat[tmpNodeId][j]) {
                    nodeWeight[j] = adjMat[tmpNodeId][j];
                    linkNode[j] = tmpNodeId;
                }
            }
        }
    }
    return totalEdgeWeight;
}