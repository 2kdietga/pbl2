#include"room.h"
#include"user.h"
#include"service.h"

room::room() {}

room::room( const string &s1,const string &s2,const string &s3,int s4,const string &s5)
        :  ma(s1),ten(s2),loai(s3),gia(s4),trangthai(s5){}

room::~room() {}

void room::adduser(user *u){
    if((loai=="Phong don" && us.getsize()==1) || (loai=="Phong doi" && us.getsize()==2)){
        cout<<"Phong da du nguoi!";
        return;
    }
    this->us.push_back(u);
    u->setphong(this);
}

void room::addservice(service *s){
    this->se.push_back(s);
    s->addroom(this);
}


string room::getma()const{
    return ma;
}
string room::getten()const{
    return ten;
}
string room::getloai()const{
    return loai;
}
string room::gettrangthai()const{
    return trangthai;
}
string room::getall()const{
    string temp=ma+","+ten+","+loai+","+to_string(gia)+","+trangthai;
    return temp;
}
int room::getgia(){
    return gia;
}

void room::infor(){
    cout<<"Ma phong: "<<ma<<" ,Ten phong: "<<ten<<" ,Loai phong: "
        <<loai<<" ,Gia: "<<gia<<" ,Trang thai: "<<trangthai;
    if(trangthai=="Da thue"){
        cout<<endl<<"Thong tin cac chu phong: "<<endl;
        for(int i=0;i<us.getsize();i++){
            us[i]->getname();
        }
    }
    cout<<endl;
}

// istream &operator >>(istream &is, room &p){
//     cout<<"Ma phong:"; getline(is,p.ma);
//     cout<<"Ten phong:"; getline(is,p.ten);
//     cout<<"Loai phong:"; getline(is,p.loai);
//     cout<<"Gia:"; is>>p.gia; fflush(stdin);
//     cout<<"Trang thai:"; getline(is,p.trangthai);
//     return is;
// }

istream& operator>>(istream& is, room* &r){
    getline(is,r->ma,',');         
    getline(is,r->ten,',');
    getline(is,r->loai,',');        
    is>>r->gia;                     
    is.ignore();                    
    getline(is,r->trangthai);        
    return is;
}


ostream& operator <<(ostream &os,const room*& r){
    os<<r->ma<<","<<r->ten<<","<<r->loai<<","<<r->gia<<","<<r->trangthai;
    return os;
}