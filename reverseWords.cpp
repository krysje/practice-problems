#include <bits/stdc++.h>
using namespace std;

string reverseWords(string S){

    int l = S.length();
    string ans = "";
    S.insert(0, "\n");
    int i = l;

    while(S[i] != '\n'){

        if(S[i] == '.'){
            ans += S.substr(i+1);
            ans.append(".");
            S.erase(i);
        }
          i--;
    }

    ans.append(S.substr(1));
    return ans;
}

int main(){

    string s;   cin>>s;

    string ans = reverseWords(s);

    cout<<ans<<endl;
    return 0;
}