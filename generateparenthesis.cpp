#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<string> ans, string curr, int open, int close, int max){
    
    if(curr.length() == max * 2){
        ans.push_back(curr);
    }

    if(open < close){
        curr.append("(");

        backtrack(ans, curr, open+1, close, max);

        curr.pop_back();
    }

    if(close < open){
        curr.append(")");

        backtrack(ans, curr, open, close+1, max);
        
        curr.pop_back();
    }

    

}

int main(){

    vector<string> ans;
    string curr;

    backtrack(ans, curr, 0, 0, 3);
    
    for(auto x : ans)
        cout<<x<<endl;
        

    return 0;
}