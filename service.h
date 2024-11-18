#ifndef service_h
#define service_h

#include<string>
#include"vector.h"
using namespace std;

class room;

enum class type{dien,nuoc,rac,wifi};

class service{
    private:
        vector<room*> ph;
        string name;
        int socu;
        int somoi;
        double tong;
        double gia;
        int thang;
        int nam;
        type kieu;
        bool pay;
    public:
        service(type , double,int,int,int=0,int=0);
        ~service();
        void setso(int,int);
        void setgia(double);
        void setdate(int, int);
        void setpay(bool );
        void tongbill(); 
        double gettongbill()const;
        string getname()const;
        int getthang();
        int getnam();     
        bool ispay()const;
        void addroom(room*);
        void showroom()const;
        friend istream &operator >>(istream &,service*);
        friend class room;
};


#endif