//
// Created by fang on 2018/12/17.
//

#ifndef FINAL_WORK_2_TEST_H
#define FINAL_WORK_2_TEST_H

#include "my_vector.h"
#include <iostream>
#include "binary_search.h"

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

#endif //FINAL_WORK_2_TEST_H
