/*
Suppose there are n cities connected with each other via particular road. Each road
has a length w. Exactly in one city m there is a tiger. Mayor of other cities want to
capture that tiger. Mayor who comes first in m city will capture the tiger. Your task
is to design an algorithm that finds which city mayor will capture the tiger first.
You are given number of city n, number of road r, length of each road w and the
location of the city m that holds the tiger as input. Input will be given in following
format:
n
r
u v w
Here, u v w denotes the road between city u and v, length of that road is w. See
sample input and output for better understanding.
Sample input Sample output
n: 4
r: 4
0 1 7
2 3 5
0 3 10
2 1 1
m: 2

Mayor in city 1 will capture
first.

*/
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
 void print (int n, int src, int dis[] ){
    int min, ind;
    min = 200;
    for(int i= 0;i<n;i++){
        if ((dis[i]<min)&&( i!= src)){
            min = dis[i];
            ind =i;
            }
    }
    printf("\n Mayor in City %d Will Captures First\n",ind);
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
    int edge ;

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
    int src = 2 ;
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
    print(n,src,dis);
    return 0 ;
}
