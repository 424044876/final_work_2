//
// Created by fang on 2018/12/19.
//

#ifndef FINAL_WORK_2_DFS_ALL_PATH_H
#define FINAL_WORK_2_DFS_ALL_PATH_H



#include "my_vector.h"

string DFS_ans;
Vector<int> DFS_visited(100, 0);
Vector<string> DFS_anses(100);
int DFS_ans_num = 0;
void dfs(Vector<Vector<int>> mat,int v_num , int b, int end){
    DFS_visited[b]=1;
    for (int i = 1; i < v_num+1; ++i) {
        if(mat[b][i]!=1e7&&DFS_visited[i]==0){
            if(i==end){
                DFS_anses[DFS_ans_num]=DFS_ans;
                DFS_anses[DFS_ans_num].push_back(i+'0');
//                cout<<DFS_anses[DFS_ans_num]<<endl;
                DFS_ans_num++;
            } else{
                mat[b][i] = 1e7; //escape circle
                mat[b][i] = 1e7;
                DFS_ans.push_back('0'+i);
                dfs(mat, v_num, i, end);
                mat[b][i] = 1;
                mat[i][b] = 1;
                DFS_ans.pop_back();
                DFS_visited[i]=0;
            }
        }
    }
}



#endif //FINAL_WORK_2_DFS_ALL_PATH_H
