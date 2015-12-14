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
vvi adj;
int visited[100000],indegree[1000];
queue<int> intermediate,answer;
void toposort(int start)
{
  intermediate.push(start);

    while(!intermediate.empty() && visited[intermediate.front()]==0)
    { 
      int vertex=intermediate.front();intermediate.pop();
      visited[vertex]=1;
      answer.push(vertex);
      visited[vertex]=1;
          foreach(i,adj[vertex]){indegree[(*i)]--;
          if(indegree[(*i)]==0)intermediate.push((*i));}
        
      }}
int main()
{
    int vertices,edges,p,q,r;
    cin >> vertices >> edges;adj.resize(vertices+1);
    forall(i,0,edges)
    {cin >> p >> q ;adj[p].pb(q); };

    forall(i,0,vertices+1)
    foreach(v,adj[i])indegree[(*v)]++;// raising indegree rightly
    forall(i,1,vertices+1)if(indegree[i]==0)toposort(i);
    while(!answer.empty()){int vertex=answer.front();answer.pop();
     cout << vertex <<"\n";
     }
}




/*
Sample Input 1
6 6
1 2
1 4
2 3
3 4
3 5
4 5
*/