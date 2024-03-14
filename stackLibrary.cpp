#include<bits/stdc++.h>
#include<stack>
using namespace std;

string reverseSentence(string s){
    stack<string> words;
    string word = "";
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' '){
            words.push(word);
            word = "";
            continue;
        }
        word += s[i];
        if(i == s.length() - 1){
            words.push(word);
            word = "";
        }
    }

    string newstr = "";
    while(!words.empty()){
        newstr += words.top() + " ";
        words.pop();
    }

    return newstr;
}

/* Reverse Stack*/
void insertBack(stack<int> &st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();
    insertBack(st,x);
    st.push(top);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertBack(st,top);
}

/* Display Stack */
void display(stack<int> &st){
    if(st.empty()){
        return;
    }

    int top = st.top();
    cout<<st.top()<<" ";
    st.pop();
    display(st);
    st.push(top);
}

int main(){

    /* Reverse a sentence word by word not letter.*/
    // string s = "Boy. Good A Is Omkar";
    // cout<<reverseSentence(s)<<endl;

    /* Reverse a Stack*/
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    display(st);
    cout<<endl;
    reverseStack(st);
    display(st);
    cout<<endl;
    
    


    return 0;

}