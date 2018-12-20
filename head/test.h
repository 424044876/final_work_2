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

void test_my_vector(){
    Vector <int> v(10);
    for (int i = 0; i < v.size(); ++i) {
        v[i]=i;
    }
    v.dele(2);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    v.insert(2, 2);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    Vector <int> v2;
    v2 = v;
    v[2]=100;
    for (int j = 0; j < v2.size(); ++j) {
        cout<<v2[j]<<' ';
    }
    cout<<endl;
}

void test_add_place(){
    Graph g;
    g.load_graph_from_file();
    Node tmp("学研中心");
    tmp.set_repo("自我介绍");
    g.add_place(tmp);
    g.repr_graph();
}


void test_save(){
    Graph g;
    g.load_graph_from_file();
    g.save_graph();
}

void test_delete(){
    string pl = "主楼";
    Graph g;
    g.load_graph_from_file();
    g.delete_place(pl);
    g.repr_graph();
}

void test_mini_tree(){
    Graph g;
    g.load_graph_from_file();
    g.mini_tree();
}

void test_DFS(){
    Graph g;
    g.load_graph_from_file();
    g.get_all_path("南门", "二教");
}


#endif //FINAL_WORK_2_TEST_H
