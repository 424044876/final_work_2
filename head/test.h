//
// Created by fang on 2018/12/17.
//

#ifndef FINAL_WORK_2_TEST_H
#define FINAL_WORK_2_TEST_H

#include <iostream>
#include "my_vector.h"
#include "binary_search.h"
#include "Graph.h"
#include "dijsktra.h"
#include "functions.h"
using namespace std;

void test_binary_search(){
    Vector<int> a(10);
    for (int i = 0; i < 10; ++i) {
        a[i]=i;
    }
    cout<<my_binary_search(a, 4, 0, 9);
}

void testGraph(){
    Graph g;
    g.load_graph_from_file();
    g.repr_graph();
}

void test_dij(){
    Graph g;
    g.load_graph_from_file();
    g.renew_ans(2);
    cout<<g.ans[3].length<<endl;
}

#endif //FINAL_WORK_2_TEST_H
