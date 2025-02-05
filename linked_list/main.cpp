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
    nstr prev, next;
    int getinf(){
        return this -> value.data ;
    }
    void setinf(int x){
        this -> value.data = x ;
    } 
    
};
//链表有首尾结点指针，结点有前后指针
struct link1/*链表结构head,node1,node2, ..., nodelength, end*/
{
    nstr head, end;
    int length;
    int init(int l = 0){
        this -> head = new node; //head node
        this -> end = new node;  //end node
        nstr p, r;
        p = this -> head;  //present node
        for(int i = 1; i<=l; i++){
            r = new node;
            p -> next = r;
            r -> prev = p;
            p = r;
        }
        p -> next = this->end;
        this -> end -> prev = p;
        this -> length = l;
    }

    //length function
    int get_length(){
        nstr p = this -> head;
        int t = 0;
        while(p->next != this->end){
            p = p->next;
            t++;
        }
        this->length = t;
        return t;
    }

    //real index（将负数index转正）index = 1-length
    //1对应-length ， length对应-1
    int real_index(int x){
        if(x<0) return this->get_length() + x + 1;
        else return x;
    }

    //set
    void set(int x, int y){
        x = this->real_index(x);
        nstr p = this->head ;
        for(int i = 0; i<x; i++){
            p = p -> next;
        }
        p -> setinf(y);
    }

    //get
    int get(int x){
        x = this->real_index(x);
        nstr p = this->head ;
        for(int i = 0; i<x; i++){
            p = p -> next;
        }
        return p -> getinf();
    }

    //new nail node在尾部增加l个节点
    void new_nail_node(int l = 1){
        nstr p, r;
        p = this -> end -> prev;
        for(int i=0; i<l; i++){
            r = new node;
            r = p -> next;
            r -> prev = p;
            p = p -> next;
        }
        p -> next = this -> end;
        this -> end -> prev = p;
        this -> length += l;
    } 

    //delete node from nail
    void dele_nail_node(int l = 1){
        nstr r, end_node;
        end_node = this -> end;
        r = this -> end ->prev;
        for(int i = 0; i<l; i++){
            r = r->prev;
            delete r->next;
        }
        r->next = end_node;
        end_node -> prev = r;
        this->length -= l;
    }

    //delete all node(except begin and end node)
    void clean_items(){
        int t = this -> get_length();
        dele_nail_node(t);
        this -> length = 0;
    }

    iter get_iter(int x){
        x = this -> real_index(x);
        nstr p = this->head;
        for(int i = 0; i<x; i++)
        {
            p = p -> next;
        }
        iter r;
        r.nd = p;
        return r;
    }

    iter iter_real_head()
    {
        return this->get_iter(0);
    }
    iter iter_head()
    {
        return this->get_iter(1);
    }
    iter iter_end()
    {
        return this->get_iter(-1);
    }
    iter iter_real_end()
    {
        return ++this->get_iter(-1);
    }
};

struct iter{
    nstr nd;
    iter operator++(){
        if(this -> nd -> next == NULL) return *this;
        this->nd = this->nd->next;
        return *this;
    }
//后置递增运算符 int存在的意义是区别于前置运算符
    iter operator++(int){
        if(this -> nd -> next == NULL) return *this;
        iter i = *this;
        this->nd = this->nd->next;
        return i;
    }
    iter operator--(){
        if(this -> nd -> prev = NULL) return *this;
        this -> nd = this->nd->prev;
        return *this;
    }
    iter operator--(int)
	{
		if(this->nd->prev == NULL) return *this;
		iter i = *this;
		this->nd = this->nd->prev;
		return i;
    }
    iter operator+(int l){
        iter it = *this;
        for(int i=1; i<=l; i++) it++;
        return it;
    }
    iter operator-(int l){
        iter it = *this;
        for(int i=1; i<=l; i++) it--;
        return it;
    }
    bool operator==(const iter other){
        return this -> nd == other.nd;
    }
    bool operator!=(const iter other){
        return this -> nd != other.nd;
    }
    iter real_head(){
        //前提：前面重构的符号--，如果prev是NULL则返回自己
        iter p = *this;
        iter r = p--;
        while(p.nd!=r.nd) r--, p--;
        return p;
    }
    iter real_end(){
        iter p =*this;
        iter r = p++;
        while(p.nd!=r.nd) r++, p++;
        return p;
    }
    iter head(){
        //返回的是有数据的第一个节点
        return ++this->real_head(); 
    }
    iter end(){
        return --this->real_end();
    }


    nstr get(){
        return this->nd;
    }
    friend ostream& operator<<(ostream& os, iter self){
        os << self.get()->getinf();
        return os;
    }
    
};