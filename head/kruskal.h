//
// Created by fang on 2018/12/19.
//

#ifndef FINAL_WORK_2_KRUSKAL_H
#define FINAL_WORK_2_KRUSKAL_H


#include <iostream>

#include "my_vector.h"
#include "arc.h"
#include "quick_sort.h"


int Kruskal(int v_num, Vector<Arc> &arcs, Vector<Arc> &ans){
    ans.resize(v_num+1);
    Vector<int> tmp(v_num+10);
    int length=0;
    //init 
    for (int i = 1; i <v_num+1 ; ++i) {
        tmp[i]=i;
    }

    quick_sort(arcs, 1, arcs.size()-1);
    int j = 0;
    for (int i = 1; i < arcs.size(); ++i) {
        int a = arcs[i].get_ak();
        int b = arcs[i].get_bk();
        
        if(tmp[a]==tmp[b]){
            continue;
        } else{
            length += arcs[i].get_length();
            ans[j] = arcs[i];
            j++;
            int a_b_min = min(tmp[a], tmp[b]);
            int a_b_max = max(tmp[a], tmp[b]);

            for (int k = 1; k < v_num+1; ++k) {
                if(tmp[k]==a_b_min){
                    tmp[k]=a_b_max;
                }
            }
        }
    }
//    cout<<j<<endl;
    return length;
}



#endif //FINAL_WORK_2_KRUSKAL_H
