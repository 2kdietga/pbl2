#ifndef room_h
#define room_h

#include"vector.h"
#include<string>
using namespace std;

class user;
class service;

class room{
    private:
        vector<user*> us;
        vector<service*> se; 
        string ma;
        string ten;
        string loai;
        int gia;
        string trangthai;
    public:
        room();
        room(const string&,const string&,const string&, int ,const string&);
        ~room();
        string getma() const;
        string getten() const;
        string getloai() const;
        string gettrangthai() const;
        string getall()const ;
        int getgia();
        void addservice(service*);
        void adduser(user*);
        void infor();
        friend istream& operator >>(istream &,room* &);
        friend ostream& operator <<(ostream &,const room*&);
};


#endif