//
// Created by fang on 2018/12/20.
//

#ifndef FINAL_WORK_2_MY_LIST_H
#define FINAL_WORK_2_MY_LIST_H

#include <iostream>
using namespace std;

template <class T>
class List{
private:
    T data;
    List * next;
    List * tail=NULL;
    List * head=NULL;
public:
    List() :next(NULL)
    {
        head = tail = this;
    }
    List(T new_node) :data(new_node), next(NULL)
    {}

    void append(T &node){
        tail->next = new List(node);
        tail = tail->next;
    };

    List* begin(){
        return this->next;
    }

    List *end(){
        return tail;
    }

    bool empty(){
        return head==tail;
    }

    List * get_next(){
        return next;
    }

    T& get_data(){
        return data;
    }
};



#endif //FINAL_WORK_2_MY_LIST_H
