//
// Created by fang on 2018/12/18.
//

#ifndef FINAL_WORK_2_UI_H
#define FINAL_WORK_2_UI_H

using namespace std;

int main_ui(){
    string title = "******北林自助导游及信息服务系统******";
    string main_t = "---------------主界面--------------";
    string fun1 = "1. 前台服务";
    string fun2 = "2. 后台服务";
    string ret = "0. 退出";

    cout<<title<<endl
        <<main_t<<endl
        <<fun1<<endl
        <<fun2<<endl
        <<ret<<endl;

    int n;
    cin>>n;
    return n;
}

int sub_1(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "--------------前台服务--------------";
    string fun1 = "1. 景点信息查询";
    string fun2 = "2. 问路查询";
    string ret =  "0. 返回";

    cout<<title<<endl
        <<sub_t<<endl
        <<fun1<<endl
        <<fun2<<endl
        <<ret<<endl;

    int n;
    cin>>n;
    return n;
}

int sub_1_1(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "----------根据景点名称查询-----------";
    string fun1 = "1. 根据名称查询景点";
    string fun2 = "2. 根据景点功能查询";
    string ret = "0. 返回";

    cout<<title<<endl
        <<sub_t<<endl
        <<fun1<<endl
        <<fun2<<endl
        <<ret<<endl;

    int n;
    cin>>n;
    return n;
}

void sub1_1_1(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "----------根据景点名称查询-----------";
    cout<<title<<endl
    <<sub_t<<endl;
}


void sub1_1_2(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "----------根据景点功能查询-----------";
    cout<<title<<endl
    <<sub_t<<endl;
}


int sub1_2(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "--------------问路查询--------------";
    string fun1 = "1. 查询最短路径";
    string fun2 = "2. 查询两点之间所有路径";
    string ret = "0. 返回";

    cout<<title<<endl
        <<sub_t<<endl
        <<fun1<<endl
        <<fun2<<endl
        <<ret<<endl;

    int n;
    cin>>n;
    return n;
}

void sub1_2_1(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "------------查询最短路径------------";
    cout<<title<<endl
        <<sub_t<<endl;
}


int sub_2(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "--------------后台服务---------------";
    string fun1 = "1. 根据景点名称查询";
    string fun2 = "2. 根据景点功能查询";
    string ret =  "0. 返回";

    cout<<title<<endl
        <<sub_t<<endl
        <<fun1<<endl
        <<fun2<<endl
        <<ret<<endl;

    int n;
    cin>>n;
    return n;
}




#endif //FINAL_WORK_2_UI_H
