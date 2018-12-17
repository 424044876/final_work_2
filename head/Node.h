//
// Created by fang on 2018/12/16.
//

/*
 *
 * I use class Node to represent a place in school
 * The key is the subscript on the graph
 *
*/


#ifndef FINAL_WORK_2_NODE_H
#define FINAL_WORK_2_NODE_H

#include <string>
#include <vector>

using namespace std;

class Node {
private:
    int key = 0;
    string name = "";
    string repo = "";
public:
    Node(){}
    ~Node(){}

    Node(string n){
        name = n;
    }

    void add_repo(string t){
        repo+=t;
    }


    void set_key(int k){
        key = k;
    }

    int get_key(){
        return key;
    }

    void set_name(string n){
        name = n;
    }

    string get_name(){
        return name;
    }

    string& get_repo(){
        return repo;
    }

    bool operator<(const Node b){
        return name<b.name;
    }

    bool operator<=(const Node b){
        return name<=b.name;
    }

    bool operator>(const Node b){
        return name>b.name;
    }

    bool operator>=(const Node b){
        return name>=b.name;
    }

    bool operator==(const Node b){
        return name==b.name;
    }
};


#endif //FINAL_WORK_2_NODE_H
