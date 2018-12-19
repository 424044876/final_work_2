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

    Node(string n, string r){
        name = n;
        repo = r;
    }

    void add_repo(string t){
        repo+=t;
    }


    void set_key(int k){
        key = k;
    }

    void set_name(string n){
        name = n;
    }

    void set_repo(string n){
        repo = n;
    }
    int get_key(){
        return key;
    }

    string get_name(){
        return name;
    }

    string& get_repo(){
        return repo;
    }

    Node& operator=(Node &another_node){
        key = another_node.key;
        name = another_node.name;
        repo = another_node.repo;
        return *this;
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
