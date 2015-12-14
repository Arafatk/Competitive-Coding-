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

vvi adj;int color[1000],h[1000],ft[1000],d[1000],par[1000],visited[1000],timer=0;vi row;    

/* A cut edge is an edge that when removed (the vertices stay in place) from a graph 
   creates more connected components than previously in the graph.
   A single vertex is also considered connected to itself and when removing cut edges
   you make sure you are not cutting out cycles
   
   
   first you find the height of every vertex in dfs which is the earliest reaching time
   to reach some place in the dfs tree you do this by a complete rdfs


*/
     
// color 0 white 1 grey 2 black
void rdfs(int vertex)
{
   h[vertex]=timer++;
   	vector<int>::iterator i;visited[vertex]=1;cout << vertex << "->";
    for(i = adj[vertex].begin(); i != adj[vertex].end(); ++i)if(!visited[*i])rdfs(*i);

}

/*  Now you start a new dfs and we have a cool variuable  d[vertex]
    d[v]=min(h[w] where there is at least vertex u in subtree of v 
    in the DFS tree where there is an edge between u and w)  
    
*/
void dfs(int vertex)
{
   
   
   d[vertex]=h[vertex];
   color[vertex]=1;
	vector<int>::iterator i;cout << vertex << "->";
    for(i = adj[vertex].begin(); i != adj[vertex].end(); ++i)
    {
       if(color[*i]==0)
       {
          par[*i]=vertex;dfs(*i);d[vertex]=miN(d[vertex],d[*i]);
          if(d[*i]>h[vertex]) cout << "We got the cut edge-> " << *i <<"  " <<vertex<<"\n";
   /*LEts just say that when the above condition holds true you know that every guy in 
     my subtree has the shotest from reachable height still greater than the height 
     of the vertex that is the parent of my parent so basically i can safely assume 
     that this is only becasue this edge between our guy and his parent is the only thing
     connecting us which also means that among us connected components this is our only 
     connection to the outside world*/       
     

     
     if(d[*i]>=h[vertex] && (vertex!=1 || adj[vertex].size()>1 ) && vertex!=1)
         cout << "This is a cut vertex ->" << vertex <<"\n";
         /* In DFS tree, a vertex u is parent of another vertex v, if v is discovered by u
     (obviously v is an adjacent of u in graph). In DFS tree, a vertex u is articulation 
     point or cut vertex if one of the following two conditions is true.
     1) u is root of DFS tree and it has at least two children.
     2) u is not root of DFS tree and it has a child v such that no vertex in subtree 
     rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
     In DFS traversal, we maintain a parent[] array where parent[u] stores parent of vertex u. 
       Among the above mentioned two cases, the first case is simple to detect. For every 
       vertex, count children. If currently visited vertex u
       is root (parent[u] is NIL) and has more than two children, print it.*/
          
       }
       else if(*i!=par[vertex])d[vertex]=miN(d[vertex],h[*i]);
      /*Lets just say that i happen to meet you again but you are not my dad 
       in whic case i lower my d to your height if needed why do i do this 
       becasue their could be a cycle which could ultimately make a connected 
       component 
       
       */ 
       
    }
    color[vertex]=2;
   
}

int main()
{
	int vertices,edges,p,q;
	cin >> vertices >> edges;forall(i,0,vertices+1)par[i]=-1;
	forall(i,0,vertices+1)adj.pb(row);
	forall(i,0,edges){cin >> p >> q;adj[p].pb(q);adj[q].pb(p);};h[1]=0;
	rdfs(1); cout << "\n\n";
	dfs(1);
}

/*
Sample Input 1
7 8
1 2
1 4
2 3
3 4
2 6
6 7
6 5
5 7  


Sample Input 2
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

Sample Input 3
12 14
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