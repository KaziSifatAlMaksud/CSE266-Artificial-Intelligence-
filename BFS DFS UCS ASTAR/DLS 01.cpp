
#include<stdio.h>

#include<vector>

using namespace std ;

vector<int>adj[100] ;
bool flag;
bool DLS(int u, int z,int l){

    if(l = -1){
        return false;
    }
    if(u == z){
        return true;

    }
    else{
        for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i] ;
           flag = DLS(v,z,l-1);
           if(flag){
                break;
           }
        }
    }
    }
int main()

{

    int n, edge, i, j, u, v ;
    scanf("%d %d", &n , &edge);
    for(i = 0 ; i < edge ; i++){
        scanf("%d %d", &u, &v) ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    int source, dst,l ;
    printf("Source: ") ;
    scanf("%d", &source) ;
    printf("Destination: ") ;
    scanf("%d", &dst) ;
    printf("level: ");
    scanf("%d",&l);
    DLS(source,dst,l) ;
    if(flag){
        printf("possible");
    }
    else{
        printf("Not possible");
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
