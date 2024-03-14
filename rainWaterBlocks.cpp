#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int waterBlockTrapped(vector<int> v){
    int s = v.size() , ans = 0, i = 0;
    stack<int> st;
    while(i<s){
        while(!st.empty() && v[st.top()] < v[i]){
            int h = v[st.top()];
            int t = i - st.top();
            st.pop();
            if(st.empty()) break;
            ans += (min(v[st.top()],v[i]) - h)*t;
        }
        st.push(i);
        i++;
    }

    return ans;
}

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<waterBlockTrapped(v)<<endl;

    return 0;
}