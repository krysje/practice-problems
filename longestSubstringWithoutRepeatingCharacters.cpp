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

int lengthOfLongestSubstring(string s) {
    
        int n = s.length();
        set<char> set;

        int ans = 0, i = 0, j = 0;

        while (i < n && j < n) {
            if (set.find(s[j]) == set.end()){
                set.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else {   
                set.erase(s[i++]);
            }
        }
        return ans;
    }


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    string s;
    cin>>s;

    cout << lengthOfLongestSubstring(s) << endl; 

}