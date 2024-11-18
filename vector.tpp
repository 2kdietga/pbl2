
template<typename T>
node<T>::node(const T &s): data(s),prev(nullptr),next(nullptr){}

template<typename T>
vector<T>::vector(): size(0),tail(nullptr),head(nullptr) {}

template<typename T>
vector<T>::~vector(){
    node<T> *temp= head;
    while(temp!=nullptr){
        head= temp->next;
        delete temp;
        temp=head;
    }
}

template<typename T>
int vector<T>::getsize()const{
    return size;
}

template<typename T>
void vector<T>::push_back(const T &s){
    node<T> *newnode=new node<T>(s);
    if(head==nullptr){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    size++;
}

template<typename T>
T& vector<T>::operator[](int index){
    if(index>=size || index<0){
        throw out_of_range("Index khong hop le");
    }
    node<T> *temp=head;
    for(int i=0;i<index;i++) temp=temp->next;
    return temp->data;
}


template<typename T>
const T& vector<T>::operator[](int index)const{
    if(index>=size || index<0){
        throw out_of_range("Index khong hop le");
    }
    node<T> *temp=head;
    for(int i=0;i<index;i++) temp=temp->next;
    return temp->data;
}

template<typename T>
void vector<T>::update(int index,const T &s){
    if(index>size || index<0){
        throw out_of_range("Index khong hop le");
    }
    node<T> *temp=head;
    for( int i=0;i<index;i++) temp=temp->next;
    temp->data=s;
}

template<typename T>
istream &operator >>(istream &is, vector<T> &v) {
    T s;
    getline(is,s);
    v.push_back(s);
    return is;
}

template<typename T>
ostream &operator <<(ostream &os,const vector<T> &v){
    node<T> *temp=v.head;
    os<<temp->data;
    return os;
}
