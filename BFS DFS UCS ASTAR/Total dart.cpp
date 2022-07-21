/* how many time dart function work */
#include <fstream>
#include <iomanip>
#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;
    int c = 0;
    struct state{
        int x,y;
        int dirt;
    }temp;

int grid[100][100], col[100][100];
queue<state>Q;
void BFS(){
    while (!Q.empty()){
       temp = Q.front();
        int i = temp.x;
        int j = temp.y;
        Q.pop();

    if(grid[i][j-1] == 1 && col[i][j-1] == 0){


        col[i][j-1] = 1;
        temp.x = i;
        temp.y = j-1;
        Q.push(temp);
        c++;


    }
       if(grid[i][j+1] == 1 && col[i][j+1] == 0){


        col[i][j+1] = 1;
        temp.x = i;
        temp.y = j+1;
        Q.push(temp);
        c++;


    }
    if(grid[i-1][j] == 1 && col[i-1][j] == 0){


        col[i-1][j] = 1;
        temp.x = i-1;
        temp.y = j;
        Q.push(temp);
        c++;


    }
    if(grid[i+1][j] == 1 && col[i+1][j] == 0){


        col[i+1][j] = 1;
        temp.x = i+1;
        temp.y = j;
        Q.push(temp);
        c++;


    }

    }
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
            if(grid[i][j]==1&& col[i][j]==0){

               temp.x = i;
               temp.y = j;
               temp.dirt = grid[i][j];
               Q.push(temp);
               BFS();

            }
        }

    }
    printf("Total dart will be %d",c);

}
/*
 4 4

 0 0 1 1
 0 0 0 0
 1 1 0 0
 0 0 0 1
*/


