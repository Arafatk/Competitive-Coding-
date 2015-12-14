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
typedef pair<int,int> ii;
#define ft                 first
#define sd                 second

// the data types
#define ll long long
#define st string

/* This is the Euler tour of a graph  Euler tour of a connected, directed 
graph G = (V, E) is a cycle that traverses each edge of graph G exactly once,
although it may visit a vertex more than once. In the first part of this section
we show that G has an Euler tour if and only if in-degrees of every
vertex is equal to out-degree vertex.
and obviously (the graph must be connected).

The algorithms we have used works if and only if the graph we have does have
and euler tour then this algorithm satisfies it
*/

int visited[1000],adj[1000][1000];vi row;          // the vector of vectors
vi E;

void dfs(int vertex,int vertices)
{   cout << vertex << "->";
    forall(i,0,vertices+2)
    if(adj[vertex][i]==1)
    {
    	adj[vertex][i]--;adj[i][vertex]--;
       dfs(i,vertices);
       
    }
    E.pb(vertex);
    
}
int main()
{
	int vertices,edges,p,q;
	cin >> vertices >> edges;
	forall(i,0,edges){cin >> p >> q;adj[q][p]=1;};cout << "\n";
	dfs(1,vertices);
	cout << "\n\n\n\n";
	foreach(i,E)cout << *i <<" -> ";
}

/*
Sample Input 1
1 0
0 2
2 1
0 3
3 4
4 0

*/