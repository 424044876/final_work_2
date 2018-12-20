//
// Created by fang on 2018/12/18.
//

#ifndef FINAL_WORK_2_KMP_H
#define FINAL_WORK_2_KMP_H


#include <string>
using namespace std;

void get_next(string str, int *next){
    int len = str.size();
    next[0] = -1;
    int key = -1;
    for (int q = 1; q < len; q++){
        while (key > -1 && str[key + 1] != str[q]){
            key = next[key];
        }
        if (str[key + 1] == str[q]){
            key = key + 1;
        }
        next[q] = key;
    }
}



int KMP(string str, string sub_str){
    int m_len = str.size();
    int sub_len = sub_str.size();
    int *next = new int[sub_len];
    get_next(sub_str, next);
    int key = -1;
    for (int i = 0; i < m_len; i++){
        while (key >-1&& sub_str[key + 1] != str[i])
            key = next[key];
        if (sub_str[key + 1] == str[i])
            key = key + 1;
        if (key == sub_len-1) {
            return i-sub_len+1;
        }
    }
    return -1;
}


#endif //FINAL_WORK_2_KMP_H
