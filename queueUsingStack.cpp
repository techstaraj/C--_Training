/* Page 72 C++ Notes 1, Creating Functions for Queue using single stack*/
#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> st;
    public:

    void push(int x){
        st.push(x);
    }

    int pop(){
        if(st.empty()){
            cout<<"No element in queue."<<endl;
            return -1;
        }
        int top = st.top();
        st.pop();
        if(st.empty()) return top;
        int ans = pop();
        st.push(top);

        return ans;
    }

    bool empty(){
        return st.empty();
    }

};


int main(){
    Queue Qu;
    Qu.push(4);
    Qu.push(2);
    Qu.push(3);
    Qu.push(1);
    cout<<Qu.pop()<<endl;
    cout<<Qu.pop()<<endl;
    cout<<Qu.pop()<<endl;
    cout<<Qu.pop()<<endl;
    cout<<Qu.pop()<<endl;
    cout<<Qu.empty()<<endl;

    return 0;
}