#include<stdio.h>
#include<queue>
using namespace std;
 queue<int>Q;

 int grid[100][100], col[100][100];
struct state{
    int x,y;
    double dirt;
} temp;

void BFS(){
    while (!Q.empty()){
        temp = Q.front();
        Q.pop();
        int i = temp.x;
        int j = temp.y;

    if(grid[i][j-1] == 0 && col[i][j-1] == 0){
        col[i][j-1] = 1;
        temp.x = i;
        temp.y = j-1;
        Q.push(temp);
        c++;

    }
       if(grid[i][j-1] == 0 && col[i][j-1] == 0){
        col[i][j-1] = 1;
        temp.x = i;
        temp.y = j-1;
        Q.push(temp);
        c++;

    }

    }
}

int main(){
    int h,l
    printf("area of the room: ");
    scanf("%d %d",&h,&l);
    for(int i=0;i<h;i++){
            for(int j=0;j<l;i++){
                grid[i][j] = 0;
                col[i][j] = 0;
            }

    }



}
