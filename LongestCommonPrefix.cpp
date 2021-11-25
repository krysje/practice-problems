// xx Krysje xx

// “Fake people have an image to maintain. Real people just don’t care.” - Hachiman Hikigaya

#include <bits/stdc++.h> 
using namespace std;

#define ll long long int
#define ld long double

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

// <3 Senjougahara Hitagi <3

//short hand for usual tokens
#define pb push_back
#define pp pop_back
#define fi first
#define se second

int reverse(int x){
	int rev = 0;
	
        while(x!=0){
	        int pop = x % 10;
	        x /= 10;
	        rev = 10 * rev + pop;	
        }
	return rev;
}

string longestCommonPrefix(vector<string> &strs){

        if(strs.size() == 0)
            return "";

        string prefix = strs[0];

        for(int i = 1; i < strs.size(); i++){
            int j = 0;

            while(j < strs[i].size() && strs[i][j] == prefix[j])
                j++;
            
            prefix = prefix.substr(0, j);
        }

        if(prefix.size() == 0)
        return "";

        return prefix;

}

signed main() {

    int n;
    cin>>n;

    vector<string> words(n);
    for0(i, n)
        cin>>words[i];

    cout << longestCommonPrefix(words) << endl;


}
