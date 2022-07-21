#include<stdio.h>
#include<vector>

using namespace std ;
struct node
{
    int nd, weight ;
}temp;

struct myqueue
{
    int name, key ;
    bool flag ;
}Q[100];

vector<node> g[100] ;
int n ;
int dis[100], par[100] ;
int print_shortest_path(int src,int dest){
    if(src == dest){
        printf("%d", src);
        return 1;
    }
    int ok;
    if(par[dest] != -1){
        ok = print_shortest_path(src, par[dest]);
    }
    else{
        return -1;
    }
    if(ok != -1){
        printf("-> %d", dest);
    }
    else{
        return -1;
    }
    return 1;
}
int pop()
{
    int min = 1000000 ;
    int index ;
    for(int i = 0 ; i < n ; i++)
    {
        if(Q[i].key < min && Q[i].flag == true){
            min = Q[i].key ;
            index = i ;
        }
    }
    Q[index].flag = false ;
    return Q[index].name ;
}
bool isEmpty(){
    for(int i = 0 ; i < n ; i++){
        if(Q[i].flag)
		return false ;
    }
    return true ;
}
void Dijkstra(){
    while(!isEmpty()){
        int u = pop() ;
       // printf("u : %d\n", u) ;
        for(int i = 0 ; i < g[u].size() ; i++){
            node t = g[u][i] ;
            int v = t.nd ;
            int w = t.weight ;
          //  printf("v : %d w: %d\n", v, w) ;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w ;
                par[v] = u ;
                Q[v].key = dis[v] ;
            }
        }
    }

}
int main()
{

    int u, v, w, i ;
    int edge ,des;

    scanf("%d %d", &n, &edge) ;
    for(i = 0 ; i < edge ; i++)
    {
        scanf("%d %d %d", &u, &v, &w) ;
        temp.nd = v ;
        temp.weight = w ;
        g[u].push_back(temp) ;
        temp.nd = u ;
        g[v].push_back(temp) ;
    }
    for(i = 0 ; i < n ; i++)
    {
        dis[i] = 99999 ;
        par[i] = -1 ;
    }
    int src = 0 ;
    scanf("Destination: %d",&des);
    dis[src] = 0 ;
    for(i = 0 ; i < n ; i++){
        Q[i].name = i ;
        Q[i].key = dis[i] ;
        Q[i].flag = true ;
    }
    Dijkstra() ;
    for(i = 0 ; i < n ; i++){
        printf("%d ", dis[i]) ;

    }
    for(int i=0;i<n;i++){
        if(i != src){
            printf("\n\nshortest path from %d to %d : ",src,i);
            int found = print_shortest_path(src,i);
            if (found != -1){
                printf("\n");
            }
            else{
                printf("No possible path\n");
            }
        }
    }
    return 0 ;
}