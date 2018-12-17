//
// Created by fang on 2018/12/16.
//

#ifndef FINAL_WORK_2_QUICK_SORT_H
#define FINAL_WORK_2_QUICK_SORT_H


#include <vector>
#include <string>

using namespace std;

template <typename T>
int classify(vector<T> &array, int beg, int end){         //[]  beg and end is subscripts but [)
    if(beg==end){
        return beg;
    }
    T t=array[beg];
    while (beg!=end){
        while (beg!=end){
            if(array[end]<t){
                array[beg]=array[end];
                break;
            }
            end--;
        }
        while (beg!=end){
            if(array[beg]>t){
                array[end]=array[beg];
                break;
            }
            beg++;
        }
    }
    array[end]=t;
    return end;
}



template <typename T>
void quick_sort(vector<T> &array, int beg, int end){    //[]
    if(beg>=end){
        return;
    }
    int min=classify(array, beg, end);
    quick_sort(array, beg, min);
    quick_sort(array, min+1, end);
}


#endif //FINAL_WORK_2_QUICK_SORT_H
