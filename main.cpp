#include <iostream>
#include <fstream>

#include "head/Graph.h"
#include "head/work.h"
#include "head/test.h"


using namespace std;

int main() {
    Graph g;
    g.load_graph_from_file();
    work(g);
    return 0;
}