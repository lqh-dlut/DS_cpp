#include<iostream>
using namespace std;

struct information{
    int data;
};
struct node;
typedef node* nstr; 
/*ָ��node����ָ��*/

struct node /*������Ľṹ*/
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
struct link1/*����ṹ*/
{
    nstr head, end;
    int length;
    int init(int l = 0){
        this -> head = new node;
        this -> end = new node;
        
    }
};
