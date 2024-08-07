#include<iostream>
using namespace std;

struct information{
    int data;
};
struct node;
typedef node* nstr; 
/*指向node结点的指针*/

struct node /*链表结点的结构*/
{
    information value;
    nstr pre, next;
    int getinf(){
        return this -> value.data ;
    }
    void setinf(int x){
        this -> value.data = x ;
    } 
    
};
struct link1/*链表结构*/
{
    nstr head, end;
    int length;
    int init(int l = 0){
        this -> head = new node;
        this -> end = new node;
        
    }
};
