#include <iostream>
#include <fstream>
#include <cstdlib>

#include "head/Graph.h"
#include "head/test.h"
#include "head/HushList.h"
#include "head/my_vector.h"
#include "head/ui.h"
#include "head/functions.h"

using namespace std;

int main() {

    Graph g;
    g.load_graph_from_file();


    while (1){
        system("clear");
        int n=main_ui();

        if(n==1){
            system("clear");
            int s1 = sub_1();
            if(s1 == 1){
                system("clear");
                int s11=sub_1_1();
                if(s11==1){
                    system("clear");
                    sub1_1_1();
                    func1_1_1(g);
                } else if(s11==2){
                    system("clear");
                    sub1_1_2();
                    func1_1_2(g);
                } else{
                    continue;
                }
            }
            else if(s1 == 2){
                system("clear");
                sub1_2();
            } else{
                continue;
            }
        }

        else if(n==2){
            system("clear");
            int s2 = sub_2();
        }

        else{
            break;
        }
    }
}