//
// Created by fang on 2018/12/16.
//


/*
 *
 * I use class Graph to represent school
 * The 1-D Vector 'places' is used to represent places of school
 * and the 2-D Vector 'matrix' is an adjacency matrix to represent distance between each place
 *
*/

#ifndef FINAL_WORK_2_GRAPH_H
#define FINAL_WORK_2_GRAPH_H


#include <fstream>
#include <string>
#include <iostream>

#include "my_vector.h"
#include "Node.h"
#include "HushList.h"
#include "quick_sort.h"
#include "string_to_hush.h"
#include "dijsktra.h"
#include "arc.h"
#include "kruskal.h"
#include "DFS_all_path.h"

using namespace std;

class Graph {
private:
    Vector<Node> places;
    Vector<Vector<int>> matrix;
    HushList<Node> hush_list;
    int places_num;
    int road_num;
public:
    Graph(){}
    ~Graph(){}

    int get_places_num(){
        return places_num;
    }

    Node& get_place(int i){
        if(i<1||i>places_num){
            return places[0];
        }
        return places[i];
    }

    void set_key(){                             //key begin from 1
        for (int i = 0; i < places_num+1; ++i) {
            places[i].set_key(i);
        }
    }

    void build_hush_list(){
        set_key();
        hush_list.clear();
        for (int i = 1; i < places_num+1; ++i) {
            int hush_key = string_hush(places[i].get_name());
            hush_list[hush_key].append(places[i]);
        }
    }

    int hush_find(string name){
        int key = string_hush(name);
        if(hush_list[key].empty()){
            return -1;
        }
        for (List<Node> *i = hush_list[key].get_next(); i != NULL ; i=i->get_next()) {
            if(i->get_data().get_name()==name){
                return (*i).get_data().get_key();
            }
        }
        return -1;
    }

    Node& operator[](string name){
        int index = hush_find(name);
        return places[index];
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
        Vector<int> tmp(p+1, 1e7);
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
            matrix[na][nb]=distance;
            matrix[nb][na]=distance;
        }
        fin.close();
    }

    Vector<dNode> ans;
    void renew_ans(int tar){
        ans.resize(places_num+1);
        Dijsktra(matrix, ans, tar);
    }

    void show_places(){
        for (int i = 0+1; i < places_num+1; ++i) {
            cout<<places[i].get_name();
            if(i%4==0){
                cout<<endl;
            } else{
                cout<<'\t';
            }
        }
    }

    void add_place(Node &p){
        places_num++;
        p.set_key(places_num);
        places.insert(places_num, p);
        Vector<int> tmp(places_num+1, 1e7);
        Vector<Vector<int>> new_matrix(places_num+1, tmp);
        for (int i = 0; i < places_num-1; ++i) {
            for (int j = 0; j < places_num-1; ++j) {
                new_matrix[i][j] = matrix[i][j];
            }
        }
        matrix.resize(places_num, tmp);
        for (int i = 0; i < places_num-1; ++i) {
            for (int j = 0; j < places_num-1; ++j) {
                matrix[i][j] = new_matrix[i][j];
            }
        }
        int hush_key = string_hush(places[places_num].get_name());
        hush_list[hush_key].append(places[places_num]);
    }

    void add_road(string road_beg, string road_end, int road_length){
        int k1 = hush_find(road_beg);
        int k2 = hush_find(road_end);
        matrix[k1][k2] = road_length;
        matrix[k2][k1] = road_length;
    }

    void delete_place(string place){
        int k = hush_find(place);
        places.dele(k);
        for (int i = 0; i < places_num+1; ++i) {
            matrix[i].dele(k);
        }
        matrix.dele(k);
        places_num--;
        road_num=0;
        for (int i = 0; i < places_num+1; ++i) {
            for (int j = 0; j < places_num+1; ++j) {
                if(matrix[i][j]!=1e7){
                    road_num++;
                }
            }
        }
        road_num/=2;
        set_key();

        //hush delete
    }

    void get_arcs(Vector<Arc> &answer){
        answer.resize(road_num+1);
        int p=1;
        for (int i = 1; i < places_num+1; ++i) {
            for (int j = 1; j < places_num+1; ++j) {
                if(i<j&&matrix[i][j] < 1e7){
                    string name_i = places[i].get_name();
                    string name_j = places[j].get_name();
                    answer[p].set_all(name_i, name_j, i, j, matrix[i][j]);
                    p++;
                }
            }
        }
    }

    void renew_repo(string name, string new_repo){
        int key = hush_find(name);
        places[key].set_repo(new_repo);
    }

    void delete_road(string a, string b){
        int a_k = hush_find(a);
        int b_k = hush_find(b);
        road_num--;
        matrix[a_k][b_k] = 1e7;
        matrix[b_k][a_k] = 1e7;
    }

    void save_graph(string file_path="/Users/fang/Desktop/c++/final_work_2/in.txt"){
        fstream file_out;
        file_out.open(file_path, ios::out| ios::in| ios::trunc);
        file_out<<places_num<<' '<<road_num<<endl;
        for (int i = 1; i < places_num+1; ++i) {
            file_out<<places[i].get_name()<<' '<<places[i].get_repo()<<endl;
        }
        Vector <Arc> ans;
        get_arcs(ans);
        for (int i = 1; i < road_num; ++i) {
            file_out<<ans[i].get_a()<<' '<<ans[i].get_b()<<' '<<ans[i].get_length()<<endl;
        }
        file_out<<ans[road_num].get_a()<<' '<<ans[road_num].get_b()<<' '<<ans[road_num].get_length();
        file_out.close();
    }

    void mini_tree(){
        Vector <Arc> ans;
        get_arcs(ans);
        Vector <Arc> final;
        int length = Kruskal(places_num, ans, final);
        for (int i = 0; i < places_num-1; ++i) {
            cout<<final[i].get_a()<<" -- "<<final[i].get_b()<<endl;
        }
        cout<<"最短距离为："<<length<<endl;
    }

    void print_path_from_string(string s){
        for (int i = 0; i < s.size(); ++i) {
            cout<<places[s[i]-'0'].get_name()<<' ';
        }
        cout<<endl;
    }

    int get_all_path(string sbeg, string send){
        int beg = hush_find(sbeg);
        int end = hush_find(send);
        if(beg==-1||end==-1){
            return 0;
        }
        DFS_ans="";
        DFS_ans.push_back(beg+'0');
        DFS_ans_num = 0;
        DFS_anses.resize(100);
        DFS_visited.resize(100, 0);
        Vector<Vector<int>> tmp = matrix;
        dfs(tmp, places_num, beg, end);
        for (int i = 0; i < DFS_ans_num; ++i) {
            print_path_from_string(DFS_anses[i]);
        }
        return 1;
    }

    void repr_graph(){
        cout<<places_num<<' '<<road_num<<endl;
        for (int i = 1; i < places_num+1; ++i) {
            cout<<places[i].get_name()<<" "<<places[i].get_repo()<<' '<<places[i].get_key()<<endl;
        }
        Vector<Vector<int>> tmp = matrix;
        for (int i = 1; i<places_num+1; ++i){
            for (int j = 1; j < places_num+1; ++j) {
                if(tmp[i][j]==1e7){
                    cout<<"∞\t";
                    continue;
                }
                cout<<tmp[i][j]<<'\t';
            }
            cout<<endl;
        }
    }


};


#endif //FINAL_WORK_2_GRAPH_H
