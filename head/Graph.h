//
// Created by fang on 2018/12/16.
//


/*
 *
 * I use class Graph to represent school
 * The 1-D vector 'places' is used to represent places of school
 * and the 2-D vector 'matrix' is an adjacency matrix to represent distance between each place
 *
*/

#ifndef FINAL_WORK_2_GRAPH_H
#define FINAL_WORK_2_GRAPH_H

#include <vector>
#include <fstream>
#include <string>

#include "Node.h"
#include "HushList.h"
#include "quick_sort.h"
#include "string_to_hush.h"

using namespace std;

class Graph {
private:
    vector<Node> places;
    vector<vector<int>> matrix;
    HushList<Node> hush_list;
    int places_num;
    int road_num;
public:
    Graph(){}
    ~Graph(){}

    int get_num(){
        return places_num;
    }

    void set_num(int n){
        places_num = n;
    }

    void set_key(){
        for (int i = 0; i < places_num+1; ++i) {
            places[i].set_key(i);
        }
    }

    void build_hush_list(){
        set_key();

        for (int i = 1; i < places_num+1; ++i) {
            int hush_key = string_hush(places[i].get_name());
            hush_list[hush_key].push_back(places[i]);
        }
    }

    int hush_find(string name){
        int key = string_hush(name);
        if(hush_list[key].empty()){
            return -1;
        }
        for (auto i = hush_list[key].begin(); i != hush_list[key].end() ; ++i) {
            if((*i).get_name()==name){
                return (*i).get_key();
            }
        }
        return -1;
    }

    void load_graph_from_file(string path="/Users/fang/Desktop/c++/final_work_2/map.txt"){
        fstream fin(path);
        int p, r;
        fin>>p>>r;
        places_num = p;
        road_num = r;
        places.resize(places_num+1);                //begin from 1
        fin.seekg(0, ios::beg);
        string useless;
        getline(fin, useless);
        //
        //load each place
        for (int i = 1; i < p+1; ++i) {             //begin from 1
            string temp;
            fin>>temp;
            places[i].set_name(temp);
            fin>>temp;
            places[i].add_repo(temp);
        }

        //
        //sort places
        //quick_sort(places, 1, p);

        //
        //to initialize the adjacency matrix
        vector<int> tmp(p+1, 1e7);
        matrix.resize(p+1, tmp);
        //
        //load roads
        build_hush_list();
        for (int i = 1; i < r+1; ++i) {
            string a,b;
            int distance;
            fin>>a>>b>>distance;
            int na = hush_find(a);
            int nb = hush_find(b);
//            cout<<na<<' '<<nb<<endl;
            matrix[na][nb]=distance;
            matrix[nb][na]=distance;
        }
        fin.close();
    }

    void repr_graph(){
        cout<<places_num<<' '<<road_num<<endl;
        for (int i = 1; i < places_num+1; ++i) {
            cout<<places[i].get_name()<<" "<<places[i].get_repo()<<endl;
        }
        for (int i = 1; i<places_num+1; ++i){
            for (int j = 1; j < places_num+1; ++j) {
                cout<<matrix[i][j]<<' ';
            }
            cout<<endl;
        }
    }

};


#endif //FINAL_WORK_2_GRAPH_H
