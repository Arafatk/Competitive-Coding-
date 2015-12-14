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

/*  This is The bfs of a graph and it can be used up to find the distances in an unweighted 
    graph in O(n) and it is cool. And here we have the distance in d
*/
list<int> *adj,q;int d[1000];
void bfs(int vertex)
{
    q.push_back(vertex);d[vertex]=0;
    while(!q.empty())
    {
        int l=q.front();q.pop_front();
        printf("%d->",l);     
        foreach(i,adj[l])
        {if(d[*i]==INF){d[*i]=d[l]+1;q.push_back(*i);}}}}
int main()
{
	int vertices,edges,p,q;
	cin >> vertices >> edges;
	adj = new list<int>[vertices+1];
	forall(i,0,vertices+1)d[i]=INF;
	forall(i,0,edges){cin >> p >> q;adj[p].pb(q);adj[q].pb(p);};
	bfs(1);
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
12 14
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