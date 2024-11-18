#pragma once
#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct node{
    T data;
    node *prev;
    node *next;
    node(const T &);
};

template<typename T>
class vector{
    private:
        node<T> *head;
        node<T> *tail;
        int size;
    public:
        vector();
        ~vector();
        void push_back(const T &);
        int getsize()const;
        T& operator [](int);
        const T& operator[](int) const;
        void update (int,const T &);
        template<typename U>
        friend istream &operator >>(istream &,vector<U> &);
        template<typename U>
        friend ostream &operator <<(ostream &,const vector<U>& );

};
#include"vector.tpp"
