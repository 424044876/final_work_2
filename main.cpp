#include <iostream>
#include <fstream>

#include "head/Graph.h"
#include "head/work.h"
#include "head/test.h"


using namespace std;

int main() {
    string file_path;
    while (1){
        cout<<"请输入map.txt的路径："<<endl;
        cin>>file_path;
        fstream fs(file_path);
        if(fs.is_open()){
            break;
        } else{
            cout<<"路径错误"<<endl;
        }
    }
    Graph g;
    g.load_graph_from_file(file_path);
    work(g);
    return 0;
}