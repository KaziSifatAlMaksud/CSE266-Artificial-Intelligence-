/* DFL destination Found Or Not*/

#include<stdio.h>
#include<vector>

using namespace std ;
bool flag;
int col[100];

vector<int>adj[100] ;

bool DFS(int u, int z){
    col[u] = 1 ;
    if(u == z){
        printf("Not found");
        return true;

    }

    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i] ;
        if(col[v] == 0){
           flag = DFS(v,z);
           if(flag){
                return flag;
           }
        }
    }

    col[u] = 2 ;

}


int main()

{

    int n, edge, i, j, u, v ;

    scanf("%d %d", &n , &edge) ;

    for(i = 0 ; i < edge ; i++){

        scanf("%d %d", &u, &v) ;

        adj[u].push_back(v) ;

        adj[v].push_back(u) ;

    }

    for(i = 0 ; i < n ; i++){

        col[i] = 0 ;

    }


    int source, dst ;

    printf("Source: ") ;

    scanf("%d", &source) ;

    printf("Destination: ") ;

    scanf("%d", &dst) ;

    DFS(source,dst) ;
    if(flag){
        printf("Destination Found");

    }
    else{
        printf("Not Found");
    }
}

/*

4 6

0 1
0 2
1 2
2 0
2 3
3 3


*/
