#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 10000
template<typename Type>
class Heap{
    private:
        int  size;
        Type data[MAXN+1];
        void siftdown( int pos );
        
    public:
        Heap();
        void push( Type key );
        Type pop();
        void make_heap();
        bool empty();
        void clear();
        int  get_size();
};

template<typename Type>
Heap<Type>::Heap(){
    size= 0; }  

template<typename Type>
int Heap<Type>::get_size(){
    return size; }

template<typename Type>
bool Heap<Type>::empty(){
    return size== 0;}

template<typename Type>
void Heap<Type>::clear(){
    size= 0; }

template<typename Type>
void Heap<Type>::siftdown( int pos ){
    while( pos<<1<= size ){
        int t= pos<<1; 
        if( (pos<<1)+ 1<= size && data[(pos<<1)+1]<data[t] ) t= (pos<<1)+ 1;
        if( data[t]< data[pos] ){
            Type tmp= data[t]; data[t]= data[pos]; data[pos]= tmp;
            pos= t; }
        else break;
    }
}

template<typename Type>
void Heap<Type>::push( Type key ){
    data[++size]= key;
    int pos= size;
    while( pos> 1 ){
        if( data[pos>>1]> data[pos] ){
            Type tmp= data[pos]; 
            data[pos]= data[pos>>1]; data[pos>>1]= tmp;
            pos>>= 1; }
        else break;
    }
}

template<typename Type>
Type Heap<Type>::pop(){
    Type tmp= data[1]; data[1]= data[size];
    data[size]= tmp; size--;
    siftdown(1); return data[size+1];
}

