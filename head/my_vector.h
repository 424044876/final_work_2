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
        len = n;
        a = new T[n];
    }

    Vector(int n, T m){
        len = n;
        a = new T[n];
        for (int i = 0; i < n; ++i) {
            a[i]=m;
        }
    }

    ~Vector(){}

    int size(){
        return len;
    }

    void resize(int n){
        len = n;
        a = new T[n];
    }

    void resize(int n, T m){
        len = n;
        a = new T[n];
        for (int i = 0; i < n; ++i) {
            a[i]=m;
        }
    }

    void dele(int sub){
        T *b = new T[len-1];
        len--;
        for (int i = 0, j = 0; i < len; ++i, ++j) {
            if(j==sub){
                j++;
            }
            b[i]=a[j];
        }
        delete []a;
        a = b;
    }

    void insert(int sub, T target){
        T *b = new T[len+1];
        len++;
        for (int i = 0, j = 0; i < len; ++i, ++j) {
            if(i == sub){
                b[i]=target;
                j--;
                continue;
            }
            b[i]=a[j];
        }
        delete []a;
        a = b;
    }

    T& operator[](int n){
        return a[n];
    }

    Vector& operator=(const Vector target){
        len=target.len;
        this->a = new T[target.len];
        for (int i = 0; i < target.len; ++i) {
            this->a[i]=target.a[i];
        }
        return *this;
    }

};


#endif //FINAL_WORK_2_MY_VECTOR_H
