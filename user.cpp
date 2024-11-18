#include"user.h"
#include"room.h"

user::user():ph(nullptr) {}

user::user(const string &s1,const string &s2,const string &s3,const string &s4): 
                        ten(s1),cccd(s2),sdt(s3),ngay(s4),ph(nullptr) {}

user::~user() {}

void user::getname(){
    cout<<"Ten chu phong: "<<ten<<endl;
}

void user::infor(){
    cout<<"Ten: " <<ten<<", CCCD: "<<cccd
            <<", SDT: "<<sdt<<", Ngay thue: "<<ngay<<endl;;
}

void user::setphong(room *p){
    ph = p; 
}

string user::getphong()const{
    if (ph==nullptr) return "Khong so huu phong!";
    else {
        room *p=ph;
        return p->getma();
    }
}

istream &operator >>(istream &is, user *u){
    cout<<"Ho va ten:"; getline(is,u->ten);
    cout<<"CCCD:"; getline(is,u->cccd);
    cout<<"SDT:"; getline(is,u->sdt);
    cout<<"Ngay thue:"; getline(is,u->ngay); fflush(stdin);
    return is;
}

/*
ostream &operator <<(ostream &os, const user &u){
    
}
*/ 