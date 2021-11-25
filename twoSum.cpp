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


/* {
    string line;
	getline(cin, line);
	istringstream iss(line);
	vector<int> nums;
	int tmp;

	while (iss >> tmp) {
		nums.push_back(tmp);
		iss.ignore(1, ',');
	}
} */




vector<int> twoSum(vector<int>& nums, int target){

    unordered_map<int, int> mp;
    vector<int> out;

    for(int i = 0; i < nums.size(); i++){

        int rq = target - nums[i];

        auto it = mp.find(rq);

        if(it != mp.end() && it->second != i){
           out.push_back(it->second);
           out.push_back(i);
        }

        else    
            mp.emplace(nums[i], i);
    }

    return out;

}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string line;
	getline(cin, line);
	istringstream iss(line);
	vector<int> nums;
	int tmp;

	while (iss >> tmp) {
		nums.push_back(tmp);
		iss.ignore(1, ',');
	}
	
    int target; cin>>target;

    
    vector<int> ans = twoSum(nums, target);

    for(auto i : ans)
        cout<<i<<" ";


}