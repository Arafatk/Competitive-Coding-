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

/* This is a double dfs implementation of Kosrajus algorithm which can be used 
   to find the strongly connected components and this guy basically tells you the number
   of elements in a strongly connected component because it uses disjoint set data 
   structure for counting the elements in a particular set and obviously it can 
   also tell you the root of any element in any SCC
   Each time we do a DFS in the reverse graph
   starting from some node, we only reach nodes in
   the same SCC or in ancestor SCCs.
   Since we process the SCCs in topological order,
   at each point the only unvisited nodes reachable
   are nodes in the same SCC.
   As proven earlier, the last nodes in each SCC will
   be returned in reverse topological order.
*/
stack<int> mystack;
vvi adj,adj2;int visited[1000],st[1000],par[1000],marked[1000],timer=0;vi row;
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}

void merge(int x,int y){
    if((x = root(x)) == (y = root(y)))     return ;
    if(par[y] < par[x])	swap(x, y);par[x] += par[y];par[y] = x;}
    

void dfs(int vertex)
{
   
	vector<int>::iterator i;visited[vertex]=1;cout << vertex << "->";
    for(i = adj[vertex].begin(); i != adj[vertex].end(); ++i)if(!visited[*i])dfs(*i);
    mystack.push(vertex);
}
void dfs2(int vertex)
{
    if (visited[vertex]==1)return;
	vector<int>::iterator i;visited[vertex]=1;cout << vertex << "->";
    for(i = adj2[vertex].begin(); i != adj2[vertex].end(); ++i)if(!visited[*i])
    {merge(vertex,*i);dfs2(*i);}}
    
int main()
{
	int vertices,edges,p,q,a,b,quer;
	cin >> vertices >> edges;
	forall(i,0,vertices+1){adj.pb(row);adj2.pb(row);}
	forall(i,0,vertices+1)par[i]=-1;
	forall(i,0,edges){cin >> p >> q;adj[p].pb(q); adj2[q].pb(p);};
	dfs(1);
	cout << "\n HEre starts our second dfs\n";
	forall(i,0,vertices+1)visited[i]=0;
	while(!mystack.empty()){cout <<  mystack.top() <<"\n";dfs2(mystack.top());mystack.pop();}
	cout << " So now Buddy enter your queris\n";
	cin >>quer;
	forall(i,0,quer){{cin >> a;b=root(a);b=-par[b];cout <<"i am b-> "<<  b <<"\n";};}
    
}



/*
Sample Input 1
9 11
1 2
2 4
4 3
3 1
4 5
5 6
6 7
7 5
6 8
8 9
9 8

6
1
5
7
8
3
4

*/