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

/*This kruskal algorithm for the minimum spanning tree of a weighted 
  undirected connected graph only Its proof and algo is in the pdf
  
  The entire concept of mst is only for Undirected graphs
*/

int par[3000],edge[3000][3];
class iii
{public:int v,d,z; iii(int x, int y,int k){v=x,d=y;z=k;}};
class compare
{public:bool operator()(iii& x, iii& y){return x.z > y.z;}};


int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}

void merge(int x,int y){if((x = root(x)) == (y = root(y)))     return ;
if(par[y] < par[x])swap(x, y);par[x] += par[y];par[y] = x;}       

priority_queue<iii,vector<iii>, compare > Q;
int main()
{
    int vertices,edges,p,q,r,ans=0;
	cin >> vertices >> edges;
	forall(i,0,vertices)par[i]=-1;
    forall(i,0,edges)
    {cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
     Q.push(iii(edge[i][0] ,edge[i][1] ,edge[i][2]));};
     while(!Q.empty())
     {
         iii top=Q.top();Q.pop();
         int a=top.v,b=top.d;
         if(root(a)!=root(b)){merge(a,b);ans+=top.z;}}
     cout << ans;
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