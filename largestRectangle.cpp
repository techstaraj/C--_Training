/*
    Q. Largest Rectangle in A Histogram
        |
        |            ___
        |           |   |
        |        ___|   |    ___
        |       |   |   |___|   |
        |___    |   |   |   |   |
        |   |___|   |   |   |   |
________|___|___|___|___|___|___|______________
        |
        |
    Given an array , each element represents the height to the histogram's bar and the width of each bar is 1 , find the area of largest rectangle in the histogram.
*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int getMaxArea(vector<int> a){
    int n = a.size(),ans = 0,i = 0;
    deque<int> dq;
    a.push_back(0);
    while(i<n){
        while(!dq.empty() && a[dq.front()] > a[i]){
            int t = dq.front();
            int h = a[t];
            dq.pop_front();
            if(dq.empty()) ans = max(ans,h*i);
            else{
                int len = i-dq.front()-1;
                ans = max(ans,h*len);
            }
        }
        dq.push_front(i);
        i++;
    }
    return ans;
}

int main(){
    vector<int> v = {2,1,5,6,2,3};
    cout<<getMaxArea(v)<<endl;

    return 0;
}