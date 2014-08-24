/* Open addressing hash implementation */
#include <iostream>
#include <string>
#include <functional>

using namespace std;

template<typename T>
class OpenAddrHash {
    public:
        OpenAddrHash();
        OpenAddrHash(int size);
        ~OpenAddrHash();
        int Insert(T item);
        int LookUp(T item);
        int DeleteItem(T item);

        enum SlotStatus { NIL = 0, DELETED};
  
    private:
        int size_;
        T *table_;
}; 

template<typename T>
OpenAddrHash<T>::OpenAddrHash()
{
    table_ = new T[16];
    size_ = 16;
    for(int i=0; i<size_; i++)
        table_[i] = NIL;
}

template<typename T>
OpenAddrHash<T>::OpenAddrHash(int size)
{
    table_ = new T[size];
    size_ = size;
    for(int i=0; i<size_; i++)
        table_[i] = NIL;
}

template<typename T>
OpenAddrHash<T>::~OpenAddrHash()
{
    delete table_;
}

template<typename T>
int OpenAddrHash<T>::Insert(T item)
{
    hash<T> hash_func;
    int i = hash_func(item) % size_;
    int count = 0;
    while(table_[i] != NIL)
    {
        if(count == size_)
            return -1;
        i = (1 + i) % size_;
        count++;
    }  
    table_[i] = item;
    return i;
}

template<typename T>
int OpenAddrHash<T>::LookUp(T item)
{   
    hash<T> hash_func;
    int i =  hash_func(item) % size_;
    int count = 0;
    while(table_[i] != NIL && table_[i] != item)
    {
        if(count >= size_)
            return -1;
        i = (1 + i) % size_;
        count++;
    }
    if(table_[i] == item && count < size_) 
        return i;
    else 
        return -1;
}

template<typename T>
int OpenAddrHash<T>::DeleteItem(T item)
{
    int i = LookUp(item);
    if(i == -1)
        return -1;
    table_[i] = DELETED;
}

int main(int argc, char** argv)
{
    OpenAddrHash<int> *int_hash = new OpenAddrHash<int>();
    int_hash->Insert(35);
    int_hash->Insert(17);
    int_hash->Insert(15);
    int_hash->Insert(25);

    int i = int_hash->LookUp(15);
    if(i == -1)
        cout << "\n Key 15 not found in table\n";
    else
        cout << "\n Key 15 found at : " << i <<"\n";

    i = int_hash->LookUp(85);
    if(i == -1)
        cout << "\n Key 85 not found in table\n";
    else
        cout << "\n Key 85 found at : " << i <<"\n";
    
    
    int_hash->Insert(55);
    int_hash->Insert(75);

    i = int_hash->LookUp(75);
    if(i == -1)
        cout << "\n Key 75 not found in table\n";
    else
        cout << "\n Key 75 found at : " << i <<"\n";
        
    int_hash->Insert(35);
    int_hash->Insert(35);
}
