//
// Created by fang on 2018/12/17.
//

#ifndef FINAL_WORK_2_STRING_TO_HUSH_H
#define FINAL_WORK_2_STRING_TO_HUSH_H

int hush(long n){
    return n%50;
}

int string_hush(string str){
    int len = min((int)str.size(), 20);
    long sum=0;
    for (int i = 0; i < len; ++i) {
        sum+=len;
    }
    return hush(len);
}

#endif //FINAL_WORK_2_STRING_TO_HUSH_H
