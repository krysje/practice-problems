#include <bits/stdc++.h>
using namespace std;

vector<int> spirallytraverse(vector<vector<int>> matrix, int r, int c){
    int cf = 0, cl = c-1;
    int rf = 0, rl = r-1;

    int i = cf;
    int j = rf;

    vector<int> ans;

    while(i <= cl){
        ans.push_back(matrix[rf][i]);
        i++;
    }
    rf++;
    j = rf;

    while(j <= rl){
        ans.push_back(matrix[j][cl]);
        j++;
    }

    cl--;
    i = cl;

    while(i >= cf){
        ans.push_back(matrix[rl][i]);
        i--;
    }
    rl--;
    j = rl;

    while(j >= rf){
        ans.push_back(matrix[cf][j]);
        j--;
    }



    return ans;
}

int main(){

    int R = 4, C = 4;
    vector<int> res;

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15,16}};

    res = spirallytraverse(matrix, R, C);

    for(auto x : res)
        cout<<x<<" ";


    return 0;

}