#ifndef user_h
#define user_h

#include<string>
using namespace std;

class room;

class user{
    private:
        string ten;
        string cccd;
        string sdt;
        string ngay;
        room *ph;
    public:
        user();
        user(const string&,const string&,const string&,const string&);
        ~user();
        void infor();
        void getname();
        void setphong(room *);
        string getphong()const;
        friend istream &operator >> (istream&, user*);
        //friend ostream &operator <<(ostream &, const user &);
};


#endif