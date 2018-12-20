//
// Created by fang on 2018/12/20.
//

#ifndef FINAL_WORK_2_MY_LIST_H
#define FINAL_WORK_2_MY_LIST_H

#include <iostream>
using namespace std;

template <class T>
class List{
private:
    T data;
    List * next;
    static List * tail;
    static List * head;
public:
    List() :next(NULL)
    {
        head = tail = this;
    }
    List(T newnode) :data(newnode), next(NULL)
    {}
    void append(T node);
    bool insert(T node, T posnode);
    void deleteNode(T node);
    void delList();
    void dispList();
};

template <class T>
List<T> * List<T>::tail = NULL;
template <class T>
List<T> * List<T>::head = NULL;

template <class T>
void List<T>::append(T node)
{
    tail->next = new List(node);
    tail = tail->next;
}

template <class T>
bool List<T>::insert(T node, T posnode)
{
    for (auto i = head->next; i != NULL; i = i->next)
        if (i->data == posnode)       //’“µΩ¡À≤Â»ÎµƒŒª÷√
        {
            List * temp = new List(node);
            if (i->next == NULL)         //posnode «◊Ó∫Û“ª∏ˆΩ·µ„£¨¥À ±–Ë“™–ﬁ∏ƒtail
            {
                temp->next = NULL;
                i->next = tail = temp;
                return true;
            }
            else{                            //≤ª «◊Ó∫Û“ª∏ˆΩ·µ„£¨÷ª «÷–º‰Ω·µ„,≤ª–Ë“™–ﬁ∏ƒtail
                temp->next = i->next;
                i->next = temp;
                return true;
            }
        }
    return false;
}

template <class T>
void List<T>::deleteNode(T node)
{
    List * i = head->next, *pre = head;
    while (i != NULL)
    {
        if (i->data == node)
        {
            if (i->next == NULL)
            {
                pre->next = NULL;
                tail = pre;
                delete i;
                i = NULL;
            }
            else{
                pre->next = i->next;
                delete i;
                i = pre->next;
            }
        }
        else{
            pre = i;
            i = i->next;
        }
    }
}

template <class T>
void List<T>::delList()
{
    List * current = head->next;
    List * temp;
    while (current != NULL)
    {
        temp = current;
        head->next = current->next;
        current = current->next;
        delete temp;
    }
    tail = head;
    head->next = NULL;
}

template <class T>
void List<T>::dispList()
{
    for (List * temp = head->next; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}


#endif //FINAL_WORK_2_MY_LIST_H
