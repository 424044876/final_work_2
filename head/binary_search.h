//
// Created by fang on 2018/12/17.
//

#ifndef FINAL_WORK_2_BINARY_SEARCH_H
#define FINAL_WORK_2_BINARY_SEARCH_H


#include "my_vector.h"

using namespace std;

template <class T>
int my_binary_search(Vector<T> &array, T tar,int beg, int end){    //[]  beg and end is subscripts but [)
    while (beg<end){
        int mid=(beg+end)/2;
        if(array[mid]==tar){
            return mid;
        } else if(tar<array[mid]){
            end=mid-1;
        } else{
            beg=mid+1;
        }
    }
    return -1;
}


#endif //FINAL_WORK_2_BINARY_SEARCH_H
