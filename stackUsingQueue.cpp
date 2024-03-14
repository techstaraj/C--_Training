/* Page 73 C++ Notes 1, Creating Functions for Stack using Queue(Making Push is Costly)*/
#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> qu1;
    queue<int> qu2;
    public:
    void push(int x){
        if(qu1.empty()){
            qu1.push(x);
            return;
        }
        qu2.push(x);
        while(!qu1.empty()){
            qu2.push(qu1.front());
            qu1.pop();
        }
        while(!qu2.empty()){
            qu1.push(qu2.front());
            qu2.pop();
        }
    }

    void pop(){
        if(qu1.empty()){
            cout<<"Stack is Empty"<<endl;
            return;
        } 
        qu1.pop();
    }

    int Top(){
        if(qu1.empty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        } 
        return qu1.front();
    }

    bool empty(){
        return qu1.empty();
    }
};

int main(){
    Stack St;
    St.push(1);
    St.push(2);
    St.push(3);
    St.push(4);
    cout<<St.Top()<<endl;
    St.pop();
    cout<<St.Top()<<endl;
    St.pop();
    cout<<St.Top()<<endl;
    St.pop();
    cout<<St.Top()<<endl;
    St.pop();
    cout<<St.Top()<<endl;
    St.pop();
    cout<<St.empty()<<endl;



    return 0;
}