//
// Created by fang on 2018/12/21.
//

#ifndef FINAL_WORK_2_HUSH_PASSWORD_H
#define FINAL_WORK_2_HUSH_PASSWORD_H

long hush_password(string psw){
    int key[6] = {11, 107, 1009, 2609, 21313, 213407};
    int  w = 1;
    long sec=0;
    for (int i = 0; i < 6; ++i) {
        sec+=psw[i]*key[i];
    }
    return sec;
}




#endif //FINAL_WORK_2_HUSH_PASSWORD_H
