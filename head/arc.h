//
// Created by fang on 2018/12/19.
//

#ifndef FINAL_WORK_2_ARC_H
#define FINAL_WORK_2_ARC_H


#include <string>

using namespace std;

class Arc{
private:
    int a_k;
    int b_k;
    string a;
    string b;
    int arc_length;
public:
    Arc(){}
    ~Arc(){}
    Arc(string s1, string s2, int n1, int n2, int l){
        a_k = n1;
        b_k = n2;
        a = s1;
        b = s2;
        arc_length = l;
    }
    int get_ak(){
        return a_k;
    }

    int get_bk(){
        return b_k;
    }

    string get_a(){
        return a;
    }

    string get_b(){
        return b;
    }

    int get_length(){
        return arc_length;
    }

    void set_all(string s1, string s2, int n1, int n2, int l){
        a_k = n1;
        b_k = n2;
        a = s1;
        b = s2;
        arc_length = l;
    }

    void set_ak(int n){
        a_k = n;
    }

    void set_bk(int n){
        b_k = n;
    }

    void set_a(string n){
        a = n;
    }

    void set_b(string n){
        b = n;
    }

    void set_length(int l){
        arc_length = l;
    }

    bool operator<(Arc arc_2){
        return this->arc_length<arc_2.arc_length;
    }

    bool operator>(Arc arc_2){
        return this->arc_length>arc_2.arc_length;
    }



    Arc& operator=(Arc another){
        a_k = another.a_k;
        b_k = another.b_k;
        a = another.a;
        b = another.b;
        arc_length = another.arc_length;
        return *this;
    }
};


#endif //FINAL_WORK_2_ARC_H
