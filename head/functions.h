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
    string hint3 = "的相关信息为：";
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
    cout<<hint3<<endl;
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

void func2_1_1(Graph &g){
    string hint1 = "输入要修改的景点名称：";
    string hint2 = "输入新的信息：";
    string hint3 = "修改成功";
    string hint4 = "输入r返回首页";
    string hint5 = "没有该地点";
    string hint6 = "当前信息：";
    g.show_places();
    cout<<endl;
    cout<<hint1<<endl;
    string name, new_repo;
    cin>>name;
    if(g.hush_find(name)==-1){
        cout<<hint5<<endl;
        cout<<hint4<<endl;
        cin>>name;
        return;
    }
    cout<<hint6<<endl;
    cout<<g[name].get_repo()<<endl;
    cout<<hint2<<endl;
    cin>>new_repo;
    g.renew_repo(name, new_repo);
    cout<<hint3<<endl
    <<hint4<<endl;
    cin>>name;
}

void func2_1_2(Graph &g){
    string hint1 = "输入要增加的景点名称：";
    string hint2 = "输入要增加的景点信息：";
    string hint3 = "增加成功";
    string hint4 = "输入r返回首页";
    g.show_places();
    cout<<endl;
    string name, repo;
    cout<<hint1<<endl;
    cin>>name;
    cout<<hint2<<endl;
    cin>>repo;
    Node new_place(name, repo);
    g.add_place(new_place);
    cout<<hint3<<endl;
    cout<<hint4<<endl;
    string tmp;
    cin>>tmp;
}

void func2_1_3(Graph &g){
    g.show_places();
    cout<<endl;
    string hint1 = "输入要增加路径的起点：";
    string hint2 = "输入要增加路径的终点：";
    string hint3 = "输入要增加的路径的距离：";
    string hint4 = "添加成功";
    string hint5 = "输入r返回首页";
    string hint6 = "添加失败，没有该地点，请先添加地点";
    string road_beg,road_end;
    int road_length;
    cout<<hint1<<endl;
    cin>>road_beg;
    cout<<hint2<<endl;
    cin>>road_end;
    cout<<hint3;
    cin>>road_length;
    if(g.hush_find(road_beg)==-1||g.hush_find(road_end)==-1){
        cout<<hint6<<endl;
        cout<<hint5<<endl;
        cin>>road_beg;
        return;
    }
    g.add_road(road_beg, road_end, road_length);
    cout<<hint4<<endl;
    cout<<hint5;
}


void func2_1_4(Graph &g){
    g.show_places();
    cout<<endl;
    string hint1 = "输入要删除的地点：";
    string hint2 = "没有该地点";
    string hint3 = "输入r返回首页";
    string hint4 = "删除成功";
    string pla;
    cin>>pla;
    if(g.hush_find(pla)==-1){
        cout<<hint2<<endl;
        cout<<hint3<<endl;
        cin>>pla;
        return;
    }
    g.delete_place(pla);
    g.show_places();
    cout<<endl;
    cout<<hint4<<endl;
    cout<<hint3<<endl;
    cin>>pla;
}

void func2_1_5(Graph &g){
    g.show_places();
    cout<<endl;
    string hint1 = "输入要删除路径的起点：";
    string hint2 = "输入要删除路径的终点：";
    string hint3 = "删除成功";
    string hint4 = "输入r返回首页";
    string hint5 = "删除失败，没有该地点";
    string road_beg,road_end;
    cout<<hint1<<endl;
    cin>>road_beg;
    cout<<hint2<<endl;
    cin>>road_end;
    if(g.hush_find(road_beg)==-1||g.hush_find(road_end)==-1){
        cout<<hint5<<endl;
        cout<<hint4<<endl;
        cin>>road_beg;
        return;
    }
    g.add_road(road_beg, road_end, 1e7);
    cout<<hint3<<endl;
    cout<<hint4<<endl;
    cin>>road_beg;
}




#endif //FINAL_WORK_2_FUNCTIONS_H
