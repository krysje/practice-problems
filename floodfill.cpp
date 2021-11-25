#include <bits/stdc++.h>
using namespace std;

int R, C;

void printMat(char mat[][50]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl; 
}

void floodfill(char mat[][50], int i, int j, char ch, char color){

    if(i < 0 || j < 0|| i >= R || j >= C || mat[i][j] != ch)
        return;
        

    mat[i][j] = color;
    
    floodfill(mat, i+1, j, ch, color);
    floodfill(mat, i-1, j, ch, color);
    floodfill(mat, i, j+1, ch, color);
    floodfill(mat, i, j-1, ch, color);
    
}



int main(){

    char mat[50][50];
    cin>>R>>C;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin>>mat[i][j];
        }
    } 

    printMat(mat);

    floodfill(mat, 8, 13, '.', 'R');

    printMat(mat);

}