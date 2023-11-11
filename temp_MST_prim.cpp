//
// 最小生成树 = Prim方法
//
#include <iostream>
#include <cstdio>

using namespace std;

#define MAX_N 1000  // the maximum number of nodes in the graph
#define MAX_W 65535  // the maximum value of edge weight

int G[MAX_N][MAX_N];
void Prim(int adjMat[][MAX_N], int n);

int main() {
    // input a matrix, specifying the weight between each two nodes in a graph
    int n;
    cout << "Input number of nodes in the graph: ";
    cin >> n;
    cout << "Input the adjacency matrix (each element means the weight between two nodes):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    // the Prim method to generate a MST
    Prim(G, n);
    return 0;
}

void Prim(int adjMat[][MAX_N], int n) {
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
        In n-1 round loop, all the n-1 edges can be added to the MST.
        That means, in every loop, a single node will be moved from
        the indefinite nodeset to the definite nodeset.
    */
    for (int i = 1; i < n; i++) {
        int minNodeWeight = MAX_W, tmpNodeId = 0;
        // Consider every node, find the minimum nodeWeight.
        for (int j = 1; j < n; j++) {
            if (linkNode[j] != -1) {
                if (minNodeWeight > nodeWeight[j] && nodeWeight[j] != -1) {
                    minNodeWeight = nodeWeight[j];
                    tmpNodeId = j;
                }
            }
        }
        // Select the chosen node, move it to the definite nodeset
        printf("Node id=%d is added to the definite nodeset, ", tmpNodeId);
        printf("and the edge added to MST is G(%d, %d)=%d.\n", linkNode[tmpNodeId], tmpNodeId, nodeWeight[tmpNodeId]);
        linkNode[tmpNodeId] = -1;
        totalEdgeWeight += minNodeWeight;
        /*
            For each node in the indefinite nodeset,
            update their recorders after a node is moved to the definite nodeset.
        */
        for (int j = 1; j < n; j++) {
            if (linkNode[j] != -1) {
                if ((nodeWeight[j] > adjMat[tmpNodeId][j] or nodeWeight[j] == -1) && adjMat[tmpNodeId][j] != -1) {
                    nodeWeight[j] = adjMat[tmpNodeId][j];
                    linkNode[j] = tmpNodeId;
                }
            }
            // printf("%d ", nodeWeight[j]);
        }
    }
    printf("The total edge weight of the generated MST is: %d\n", totalEdgeWeight);
}