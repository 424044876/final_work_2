//
// Created by fang on 2018/12/18.
//

#ifndef FINAL_WORK_2_FUNCTIONS_H
#define FINAL_WORK_2_FUNCTIONS_H

#include <string>
#include <iostream>
#include "Graph.h"
#include "kmp.h"
using namespace std;

void func1_1_1(Graph &g){
    string hint1 = "本系统提供一下景点：";
    string hint2 = "请输入景点名称：";
    string hint3 = "的相关信息为";
    string hint4 = "输入r返回首页";
    string hint5 = "查询失败";
    cout<<hint1<<endl;
    g.show_places();
    cout<<endl;
    string tar,tmp;
    cout<<hint2;
    cin>>tar;
    if(g.hush_find(tar)==-1){
        cout<<hint5<<endl;
        cout<<hint4<<endl;
        cin>>tmp;
        return;
    }
    string rer = g[tar].get_repo();
    cout<<tar;
    cout<<hint3;
    cout<<rer<<endl;
    cout<<hint4<<endl;
    cin>>tmp;
}

void func1_1_2(Graph &g){
    string hint1 = "输入待查询景点功能：";
    string hint2 = "具备此功能的景点：";
    string hint3 = "输入r返回首页";
    string tar,tmp;
    cout<<hint1<<endl;
    cin>>tar;
    cout<<hint2<<endl;
    for (int i = 1; i < g.get_places_num()+1; ++i) {
        Node n = g.get_place(i);
        if(KMP(n.get_repo(), tar)==-1){
            continue;
        } else{
            cout<<n.get_name()<<endl;
        }
    }
    cout<<endl;
    cout<<hint3<<endl;
    cin>>tmp;
}

void func1_2_1(Graph &g){
    string hint1 = "输入起点：";
    string hint2 = "输入终点：";
    string hint3 = "没有该地点";
    string hint4 = "输入r返回首页";
    string hint5 = "最短路线为：";
    string hint6 = "最短距离为：";
    string beg,end,tmp;
    g.show_places();
    cout<<endl;
    cout<<hint1<<endl;
    cin>>beg;
    cout<<hint2<<endl;
    cin>>end;
    int b_s = g.hush_find(beg);
    int e_s = g.hush_find(end);
    if(b_s==-1||e_s==-1){
        cout<<hint3<<endl;
        cout<<hint4<<endl;
        cin>>tmp;
        return;
    }
    g.renew_ans(b_s);
    for (int i = 1; i < g.get_places_num()+1; ++i) {
        int node_num=g.ans[i].node_num;
        if(g.ans[i].path[node_num]==e_s){
            cout<<hint5<<endl;
            for (int j = 0; j < node_num; ++j) {
                int p_sub = g.ans[i].path[j];
                cout<<g.get_place(p_sub).get_name();
                cout<<" -> ";
            }
            cout<<end<<endl;
            cout<<hint6<<' '<<g.ans[i].length<<endl;
            continue;
        }
    }
    cout<<hint4<<endl;
    cin>>tmp;
}

#endif //FINAL_WORK_2_FUNCTIONS_H
