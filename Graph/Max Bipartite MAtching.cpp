#include <bits/stdc++.h>
using namespace std;

#define INF                         (int)1e9
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
// with bitcount be careful with data types

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define forbac(i,a,b)               for(int i=a;i>=b;i--)
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
/*This is a dfs based biparte matching algorithm As, you know, a bipartite matching is the maximum
matching if and only if there is no augmenting path (read correctnes of ford fulkerson).
so here is what really happens you connect both sides of the graph in the matching in adjaceny list form
like a graph(unconnected usually) now initialize everything as -1 for matching
and now from the first guy on the left you start and then join then then so on 
now suppose their comes a time when you want to match with someone who is already matched to someone else
 */

vvi adj;int mark[10001],match[10001];vi row;
bool dfs(int v){// v is in X, it reaturns true if and only if there is an augmenting path starting from v
    
	if(mark[v])
		return false;
	mark[v] = true;
	cout << v+1 <<"->";
	foreach(u,adj[v])
		if(match[*u] == -1 or dfs(match[*u])) // match[i] = the vertex i is matched with in the current matching, initially -1
			{match[v] = *u, match[*u] = v;cout << *u+1<<"..";return  true;}
/*so suppose you were to move to a guy who is alread matched to someone and then
 you run match you which does not return -1 so you run dfs match u
so it means this now suppose i am trying to connect with you but 
you are alread connected so i shift everything to my partner and 
him hey buddy is their anyway you could connect to someone else 
so that i could connect to him and he looks for all the possibilities
 before rejecting you and eventhis thing goes recursively your partne
 r asks his friends sometimes that buddy is theiranyone you could connect to
so that i could connect to him and this friends is how you start 
recursive dfs now when do we terminate 
this dfs we do it when we realize that we have reached the starting of another dfs 
and obviously their can be no more than one connection and lets say 
that he does find someone empty he can connect to he will connect 
to him and you will connect to whoever you want too.now the question 
comes as to why do we do this so that basically we are making a 
very long augmenting path but the path must be their */			
			
	return false;
}
int main()
{
    int vertices,edges,p,q,r,n;
	cin >> vertices >> edges;
	forall(i,0,vertices+1){adj.pb(row);mark[i]=-1;}
	forall(i,0,edges){cin >> p >> q;p--;q--;adj[p].pb(q);adj[q].pb(p);};
	n=vertices;memset(match, -1, sizeof match);
    while(true){
	memset(mark, false, sizeof mark);
	bool fnd = false;
	for(int i = 0;i < n;i ++) if(match[i] == -1 && !mark[i])
	{	fnd |= dfs(i);};
	cout <<"\n";
	  forall(i,0,vertices)cout << "" << i+1 << "->" << match[i]+1 <<"\n";
	  cout <<"\n\n\n";
	if(!fnd)
		break;}
	forall(i,0,vertices)cout << "I am " << i+1 << " and i am matched too " << match[i]+1 <<"\n";
	
}
/*
Sample input 1
10 7
1 7
1 8
1 9
2 6
2 7
3 7
4 8



*/

