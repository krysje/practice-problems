// xx Krysje xx

// “Fake people have an image to maintain. Real people just don’t care.” - Hachiman Hikigaya

#include <bits/stdc++.h> 
using namespace std;

#define ll long long int
#define ld long double

// <3 Senjougahara Hitagi <3

//short hand for usual tokens
#define pb push_back
#define pp pop_back
#define fi first
#define se second

ll solve(int g, int c){
    ll num = c * c;
    ll den = 2 * g;
    
    return num/den;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		

	ll t;
	cin>>t;

	while(t--){

	int g, c;
    cin>>g>>c;

    cout << solve(g, c)<< "\n";

	}
}