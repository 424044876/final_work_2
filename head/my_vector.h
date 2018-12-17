//
// Created by fang on 2018/12/17.
//

#ifndef FINAL_WORK_2_MY_VECTOR_H
#define FINAL_WORK_2_MY_VECTOR_H



template <class T>
class Vector{
private:
    T * a=NULL;
    int len=0;
public:
    Vector(){}
    Vector(int n){
        a = new T[n];
    }

    ~Vector(){
        delete []a;
    }

    int size(){
        return len;
    }

    T& operator[](int n){
        return a[n];
    }

    Vector& operator=(const Vector target){
        this->a = new T[target.size()];
        for (int i = 0; i < target.size(); ++i) {
            this->a[i]=target[i];
        }
        return *this;
    }

};

#endif //FINAL_WORK_2_MY_VECTOR_H
