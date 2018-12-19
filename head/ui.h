//
// Created by fang on 2018/12/18.
//

#ifndef FINAL_WORK_2_UI_H
#define FINAL_WORK_2_UI_H

#include <string>
#include <iostream>

using namespace std;

int main_ui(){
    string title = "******北林自助导游及信息服务系统******";
    string main_t = "---------------主界面--------------";
    string fun1 = "1. 前台服务";
    string fun2 = "2. 后台服务";
    string fun3 = "3. 网线布线助手";
    string ret = "0. 退出";

    cout<<title<<endl
        <<main_t<<endl
        <<fun1<<endl
        <<fun2<<endl
        <<fun3<<endl
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


int sub2(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "--------------后台服务--------------";
    string hint1 = "请输入六位密码（以回车结束）";
    string hint2 = "连续三次错误,输入r返回";
    string hint3 =  "输入r返回";
    string password = "123456";

    cout<<title<<endl
    <<sub_t<<endl
    <<hint1<<endl;
    int flag = 0;
    for (int i = 0; i < 3; ++i) {
        string tmp;
        cin>>tmp;
        if(tmp==password){
            flag = 1;
            break;
        }
    }
    if(flag){
        return 1;
    } else{
        cout<<hint2<<endl
        <<hint3<<endl;
        string tmp;
        cin>>tmp;
    }
    return 0;
}



int sub2_1(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "--------------后台服务--------------";
    string hint1 = "1. 修改一个已有的景点的相关信息";
    string hint2 = "2. 增加一个新景点及其相关信息";
    string hint3 = "3. 增加一条新的路径";
    string hint4 = "4. 删除一个景点及其相关信息";
    string hint5 = "5. 删除一条路径";
    string hint6 = "0. 返回";
    cout<<title<<endl
    <<sub_t<<endl
    <<hint1<<endl
    <<hint2<<endl
    <<hint3<<endl
    <<hint4<<endl
    <<hint5<<endl
    <<hint6<<endl;
    int n;
    cin>>n;
    return n;
}

void sub2_1_1(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "-----修改一个已有的景点的相关信息------";
    cout<<title<<endl
    <<sub_t<<endl;
}


void sub2_1_2(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "------增加一个新景点及其相关信息------";
    cout<<title<<endl
    <<sub_t<<endl;
};

void sub2_1_3(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "----------增加一条新的路径-----------";
    cout<<title<<endl
        <<sub_t<<endl;
};


void sub2_1_4(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "-------删除一个景点及其相关信息-------";
    cout<<title<<endl
        <<sub_t<<endl;
};

void sub2_1_5(){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "------------删除一条路径------------";
    cout<<title<<endl
        <<sub_t<<endl;
};

void sub3(Graph &g){
    string title = "******北林自助导游及信息服务系统******";
    string sub_t = "------------网线布线助手------------";
    string hint = "输入r返回首页";
    g.mini_tree();
    cout<<hint<<endl;
    string tmp;
    cin>>tmp;
}


#endif //FINAL_WORK_2_UI_H
