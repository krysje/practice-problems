#include<bits/stdc++.h>
#define pb push_back
#define lli long long
#define MX 1000001
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		lli n;
		cin>>n;
		map<int, vector<string> > m;
		for(int i = 0; i<n; i++)
		{
			string temp;
			cin>>temp;
			m[temp[0]-'a'].pb(temp.substr(1));
		}

		for(auto k : m)
		{
			cout<<k.first<<endl;
			for(string s : k.second)
			{
				cout<<s<<" ";
			}
			cout<<endl;
		}


		lli ans = 0;
		for(int i = 0; i<26; i++)
		{
			map<string, int> temp;

			for(string s : m[i])
            {
                cout<<"string: "<<s<<endl;
				temp[s] = 1;
            }



			for(int j = i+1; j<26; j++)
			{
                 cout<<"i: "<<i;
                 cout<<" j: "<<j<<endl;

				lli ss = m[i].size();  cout<<"SS: "<<ss<<endl;
				lli kk = m[j].size(); cout<<"KK: "<<kk<<endl;

				for(string k : m[j])
				{
					if(temp[k] == 1)
						ss--, kk--;
				}
				ans += (ss * kk * 2LL);
                 cout<<"ANS: "<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}	
}