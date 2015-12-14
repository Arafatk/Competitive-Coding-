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

/* In all graph algorithms its always better to use a vector of vectors than to use 
   an adjacency list because you can easily acces the elements  instead of going one
   by one and also always keep the things starting from vertex 1 instead of 0 as it
   only helps in doing one thing Confusing you.Keep very short and simple implementation
*/
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
vvi adj;int visited[1000];vi row;          // the vector of vectors
void dfs(int vertex)
{
	visited[vertex]=1;cout << vertex << "->";
    foreach(i,adj[vertex])if(!visited[*i])dfs(*i);
}
int main()
{
	int vertices,edges,p,q;
	cin >> vertices >> edges;
	forall(i,0,vertices+1)adj.pb(row);
	forall(i,0,edges){RI(p,q);adj[p].pb(q);adj[q].pb(p);};
	dfs(1);
}

/*
Sample Input 1

12 13
1 2
2 3
3 4
1 4
2 6
6 7
6 5
5 7
4 12
12 8
8 9
12 11 
11 10

Sample Input 2
12 15
3 
9 10
1 2
2 3
3 4
1 4
2 6
6 7
6 5
5 7
4 12
12 8
8 9
12 11 
11 10
*/