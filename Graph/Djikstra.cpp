#include <bits/stdc++.h>
using namespace std;

#define INF                         (int)1e9
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
// with bitcount be careful with data types

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// comparision Guys 
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define abs(a)                       ( (a) > (0) ? (a) : (-a))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat

// The bit standard guys
#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n)        asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define higbit(x)                   (1 << ( int) log2(x) )

// The vectors and pairs
typedef vector<int> vi;
typedef vector<vi> vvi;
#define ft                 first
#define sd                 second

// the data types
#define ll long long
#define st string

class ii{public:int v,d;ii(int x, int y){v=x,d=y;}};
class compare {public:bool operator()(ii& x, ii& y){return x.d > y.d;}};  

/*This is djikstras algorithm and in this their is a need to repeatedly change distree to
  infinity*/

vvi adj,dist;int distree[10001];vi row; 

void adjdjikstra(int vertex)
{
    distree[vertex]=0;
    priority_queue<ii,vector<ii>, compare > Q;
    Q.push(ii(vertex,distree[vertex]));
    while(!Q.empty())
    {
        ii top=Q.top();Q.pop();int v = top.v, ds = top.d;
          if(ds <= distree[v])
             {
   int len=adj[v].size();
                 vector<int>::iterator i,j;j=dist[v].begin();
          foreach(i,adj[v])                  
         {if(distree[*i]>distree[v]+*j){distree[*i]=distree[v]+*j;
         Q.push(ii(*i,distree[*i]));}    
            j++;}}}}
int main()
{
    int vertices,edges,p,q,r;
	cin >> vertices >> edges;
	forall(i,0,vertices+1){adj.pb(row);dist.pb(row);distree[i]=INF;}
    forall(i,0,edges)
    {cin >> p >> q >> r;
     adj[p].pb(q);adj[q].pb(p);  
     dist[p].push_back(r);dist[q].push_back(r);};
     adjdjikstra(1);
     forall(i,1,vertices+1)cout << i << " -> " << distree[i] << "\n";      
}




/*
Sample Input 1
12 13
1 2 3
2 3 2
3 4 4
1 4 1 
2 6 7
6 7 5 
6 5 8
5 7 1
4 12 3
12 8 6
8 9 11
12 11 3
11 10 5
*/