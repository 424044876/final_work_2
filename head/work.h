//
// Created by fang on 2018/12/18.
//

#ifndef FINAL_WORK_2_WORK_H
#define FINAL_WORK_2_WORK_H


#include <string>

#include "Graph.h"
#include "functions.h"
#include "ui.h"

void work(Graph &g){
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
                int s12 = sub1_2();
                if(s12 == 1){
                    system("clear");
                    sub1_2_1();
                    func1_2_1(g);
                }
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


#endif //FINAL_WORK_2_WORK_H
