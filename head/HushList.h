//
// Created by fang on 2018/12/17.
//

#ifndef FINAL_WORK_2_HUSHLIST_H
#define FINAL_WORK_2_HUSHLIST_H

#include <string>
#include <list>

#include "my_vector.h"

using namespace std;


template <class T>
class HushList{
private:
    Vector<list<T>> hl;
public:
    HushList(){
        hl.resize(50);
    }
    ~HushList(){}

    list<T>& operator[](int n){
        return hl[n];
    }

};


#endif //FINAL_WORK_2_HUSHLIST_H
