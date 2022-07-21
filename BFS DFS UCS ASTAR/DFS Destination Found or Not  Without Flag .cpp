
#include<stdio.h>

#include<vector>



using namespace std ;

int col[100], d[100], par[100], f[100] ;

vector<int>adj[100] ;

int time = 0 ;


void DFS(int u, int z)

{
    col[u] = 1 ;

    for(int i = 0 ; i < adj[u].size() ; i++)

    {
        int v = adj[u][i] ;
        if(u == z){
            printf("destination is found");
            return;
        }

        else if(col[v] == 0){
            DFS(v,z) ;
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

        par[i] = -1 ;

        d[i] = 99999 ;

        f[i] = 99999 ;


    }


    int source, dst ;

    printf("Source: ") ;

    scanf("%d", &source) ;

    printf("Destination: ") ;

    scanf("%d", &dst) ;

    DFS(source,dst) ;

   /* if(col[dst] != 0) printf("Reachable\n") ;
    else printf("Not reachable\n") ;
    */
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
