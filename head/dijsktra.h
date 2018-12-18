//
// Created by fang on 2018/12/18.
//

#ifndef FINAL_WORK_2_DIJSKTRA_H
#define FINAL_WORK_2_DIJSKTRA_H


#include "my_vector.h"

using namespace std;

typedef struct dNode{
    bool flag = true;
    int path[200];
    int node_num=0;
    int length=0;
}dNode;


void Dijsktra(Vector<Vector<int>> mat, Vector<dNode> &ans, int tar){
    //init
    int v=mat.size()-1;
    dNode cur[v+1];
    cur[tar].flag= false;
    for (int i = 1; i <= v; ++i) {
        cur[i].length=mat[tar][i];
        cur[i].path[0]=tar;
        cur[i].node_num=0;
        if(mat[tar][i]!=1e6){
            cur[i].path[1]=i;
            cur[i].node_num++;
        }
    }
    ans[0].length=1e6;
    for (int i = 1; i < v; ++i) {
        //select
        dNode min=ans[0];
        int minpos=-1;
        for (int j = 1; j <= v; ++j) {
            if(!cur[j].flag){
                continue;
            }
            if(cur[j].length<min.length){
                min=cur[j];
                minpos=j;
            }
        }
        ans[i]=min;
        cur[minpos].flag = false;
        //renew
        for (int j = 1; j <= v; ++j) {
            if(!cur[j].flag){
                continue;
            }
            int point=ans[i].path[ans[i].node_num];
            if(cur[j].length>ans[i].length+mat[point][j]){
                cur[j]=ans[i];
                cur[j].length+=mat[point][j];
                cur[j].node_num++;
                cur[j].path[cur[j].node_num]=j;
            }
        }
    }
}




#endif //FINAL_WORK_2_DIJSKTRA_H
