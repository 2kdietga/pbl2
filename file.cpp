#include "file.hpp"
#include <fstream>
#include <iostream>

using namespace std;

template<typename T>
vector<T*> rfile(const string& f) {
    vector<T*> data;
    ifstream file(f);
    if (!file.is_open()) {
        cout << "Khong mo duoc file " << f << "!!!" << endl;
        return data;
    }

    while (!file.eof()) {
        T* temp = new T();
        file >> temp; 
        data.push_back(temp);
    }
    file.close();
    return data;
}

template<typename T>
void wfile(const string& f, const vector<T*>& data){
    ofstream file(f);
    if (!file.is_open()) {
        cout<<"Không mở được file "<<f<<"!!!"<<endl;
        return;
    }
    for (int i=0;i<data.getsize();i++) {
        file<<data[i]->getall()<<endl;
    }

    file.close();
}


template vector<room*> rfile<room>(const string&);
template void wfile<room>(const string&,const vector<room*>&);
