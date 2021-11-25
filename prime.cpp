#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x <= 1)
        return false;

    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0)
            return false;
    }
        return true;
}

void cardinal(int x){
    vector<int> st;
    int k = x;
    
    while(x > 0){
        st.push_back(x % 10);
        x = x/10;
    }

    int i = 1;
    int ans = 0;

    while(st.size() != 0){
        int base = st.back();
        st.pop_back();
        ans += pow(base, i);
        i++;
    }

    if(ans == k)
      cout<<k<<" ";

}


int main(){
    int l, r;

    cin>>l>>r;

    for(int i = l; i <= r; i++){
        if(isPrime(i) == true)
            cout<<i<<" ";
        else
            continue;
    }

    cout<<endl;

      for(int i = 1; i<= 100; i++)
        cardinal(i);


        return 0;
}
