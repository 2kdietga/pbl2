#include"service.h"
#include"room.h"
#include<iostream>

service::service(type t, double gia,int month,int year,int x,int y) 
        : kieu(t),gia(gia),thang(month),nam(year), socu(x), somoi(y){
            switch (t) {
                case type::dien: name="dien";   break;
                case type::nuoc: name="nuoc";   break;
                case type::wifi: name="wifi";   break;
                case type::rac: name="rac";  break;
            }
        tongbill();
}

service::~service() {}

void service::setso(int x, int y){
    this->socu=x;
    this->somoi=y;
}

void service::setgia(double g){
    this->gia=g;
}

void service::setdate(int m,int y){
    this->thang=m;
    this->nam=y;
}

void service::setpay(bool b){
    this->pay=b;
}

void service::tongbill(){
    if(kieu== type::dien || kieu== type::nuoc){
        int count=somoi-socu;
        tong=count*gia;
    }
    else{
        tong=gia;
    }
}

double service::gettongbill()const{
    return tong;
}

int service::getnam(){
    return nam;
}
int service::getthang(){
    return thang;
}

bool service::ispay()const{
    return pay;
}

void service::addroom(room *r){
    ph.push_back(r);
    // r->addservice(this);
}

void service::showroom() const {
    cout<<"Service: "<<name<<" (Month: "<<thang<<", Year: "<<nam<<") is used in rooms:"<< endl;
    for (int i=0;i<ph.getsize();i++) {
        cout<<"- Room "<<ph[i]->getma()<<endl;
    }
}

