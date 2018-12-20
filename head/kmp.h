//
// Created by fang on 2018/12/18.
//

#ifndef FINAL_WORK_2_KMP_H
#define FINAL_WORK_2_KMP_H


#include <string>
using namespace std;

void cal_next(string str, int *next){
    int len = str.size();
    next[0] = -1;
    int k = -1;
    for (int q = 1; q <= len-1; q++){
        while (k > -1 && str[k + 1] != str[q]){
            k = next[k];
        }
        if (str[k + 1] == str[q]){
            k = k + 1;
        }
        next[q] = k;
    }
}



int KMP(string str, string ptr){
    int slen = str.size();
    int plen = ptr.size();
    int *next = new int[plen];
    cal_next(ptr, next);
    int k = -1;
    for (int i = 0; i < slen; i++){
        while (k >-1&& ptr[k + 1] != str[i])
            k = next[k];
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1) {
            return i-plen+1;
        }
    }
    return -1;
}


#endif //FINAL_WORK_2_KMP_H
