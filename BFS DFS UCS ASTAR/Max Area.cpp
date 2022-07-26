/*
2. You are given a 2D matrix as input.
Each cell is filled by either 0 or any positive integer.
0 indicates block state and positive value means size of that cell.
You have to find maximum consecutive area of the matrix.
Note: a particular cell in 4-way connected: up-down, right-left
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;

    struct state{
        int x,y;
        int dirt;
    }temp;
    int c = 0,maximum=0;
int grid[100][100], col[100][100];
queue<state>Q;
void BFS(){
    printf(".");
    while (!Q.empty()){
       temp = Q.front();
        int i = temp.x;
        int j = temp.y;
        Q.pop();

    if(grid[i][j-1] >= 1 && col[i][j-1] == 0){
        col[i][j-1] = 1;
        temp.x = i;
        temp.y = j-1;
        c = c+ grid[i][j-1];
        Q.push(temp);



    }
       if(grid[i][j+1] >= 1 && col[i][j+1] == 0){
        col[i][j+1] = 1;
        temp.x = i;
        temp.y = j+1;
        c = c+ grid[i][j+1];
        Q.push(temp);


    }
    if(grid[i-1][j] >= 1 && col[i-1][j] == 0){
        col[i-1][j] = 1;
        temp.x = i-1;
        temp.y = j;
        c = c+ grid[i-1][j];
        Q.push(temp);


    }
    if(grid[i+1][j] >= 1 && col[i+1][j] == 0){
        col[i+1][j] = 1;
        temp.x = i+1;
        temp.y = j;
        c = c+ grid[i+1][j];
        Q.push(temp);


    }

    }

    if(maximum<c){
        maximum = c;
    }

    c =0;
}

int main(){
    int h,l,number;
    printf("enter the area: ");
    scanf("%d %d",&h,&l);
    for(int i=0;i<h;i++){
        for(int j=0;j<l;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<l;j++){
            col[i][j]= 0;
        }
    }


    for(int i=0;i<h;i++){
        for(int j=0;j<l;j++){
            if(grid[i][j]>=1&& col[i][j]==0){

               temp.x = i;
               temp.y = j;
               //c = grid[i][j];

               Q.push(temp);
               BFS();

            }
        }

    }
     printf("\nMaximum Consecutive area is:  %d\n",maximum);
    //printf("Total dart: %d",counts);


}

/*
test case:

4 4

10 20 0 0
10 50 0 0
0 0 0 0
50 20 60 70
*/
