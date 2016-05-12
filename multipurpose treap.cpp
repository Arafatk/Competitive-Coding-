#include <bits/stdc++.h>
using namespace std;
#define INF                         (int)1e9
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
 
/* 
   const clock_t begin_time = clock();
   // do something
   cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
*/

/*
 Read from a file
 freopen("input.in","r",stdin);
 freopen("output.out","w",stdout);
*/   
void read(){};
template<typename T,typename... Args>
void read(T &a, Args&... args) {  cin>>a ; read(args...); }
void print(){cout <<"\n";};
template<typename T,typename... Args>
void print(T &a, Args&... args) {  cout << a << " "  ; print(args...); }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
 
 
 
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
 
vector<string> split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c)) v.emplace_back(x);
    return move(v);
}
 
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
    err(++it, args...);
}
 
 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// Useful container manipulation / traversal macros
#define fa(i, begin, end)           for (auto i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fe(v, c)                    for(auto v :c)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          emplace_back  // this will work almost always
#define fill(a,v)                    memset(a, v, sizeof a)
#define mp                          make_pair
// comparision Guys 
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define abs(a)                       ( (a) > (0) ? (a) : (-a))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat
#define sqr(x)                       ((x) * (x))
#define sqrt(x)                       sqrt(abs(x))
// The bit standard guys
#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define higbit(x)                   (1 << ( auto) log2(x) )
#define what_is(x) cerr << #x << " is " << x << endl;
 
// The vectors and pairs
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int>pa;
#define ft                 first
#define sd                 second
#define pq                 priority_queue
// the data types
#define ll unsigned long long
#define st string
#define ld long double


int n,query,value;
typedef struct node{
    int prior,size,visited,prefixMaxSum,suffixMaxSum,maxsum,val,sum,lazy,rmq;
    bool rev;
    struct node *l,*r;
}node;

typedef node* pnode;

pnode Treap,it,lef,righ;

int sz (pnode it) {return it? it-> size: 0;}
    
void upd_sz(pnode t){if(t) t->size = sz(t->l)+1+sz(t->r);}

void push (pnode it) {
    if (it && it-> rev==true) {
        it-> rev = false;
        swap (it-> l, it-> r);
        if (it-> l) it-> l-> rev ^= true;
        if (it-> r) it-> r-> rev ^= true;
    }
    if(!it || !it->lazy)return;
    it->val+=it->lazy;//operation of lazy
    it->sum+=it->lazy*sz(it);
    if(it->l)it->l->lazy+=it->lazy;//propagate lazy
    if(it->r)it->r->lazy+=it->lazy;
    it->lazy=0;it->prefixMaxSum=0;it->suffixMaxSum=0;it->maxsum=it->val;       
}

void reset(pnode t){
    if(t)
    {
      t->sum = t->val;//no need to reset lazy coz when we call this lazy would itself be propagated
      t->prefixMaxSum=0;
      t->suffixMaxSum=0;
      t->lazy=0;
      t->maxsum=t->val;
      t->rmq = t->val;
    }}
void combine(pnode& t,pnode l,pnode r){//combining two ranges of segtree
    if(!l || !r)return void(t = l?l:r);
    t->rmq=min(t->rmq,l->rmq);
    t->rmq=min(t->rmq,r->rmq);
    t->sum = l->sum + r->sum;
    t->prefixMaxSum=maX( l->prefixMaxSum, l->sum+ r->prefixMaxSum);
    t->suffixMaxSum=maX( r->suffixMaxSum, r->sum+ l->suffixMaxSum);
    t->maxsum=maX(t->prefixMaxSum,maX(t->suffixMaxSum,maX( l->maxsum,maX( r->maxsum,l->suffixMaxSum+ r->prefixMaxSum))));
}
void operation(pnode t){//operation of segtree
    if(!t)return;
    reset(t);//reset the value of current node assuming it now represents a single element of the array
    push(t->l);push(t->r);//imp:propagate lazy before combining t->l,t->r;
    combine(t,t->l,t);
    combine(t,t,t->r);
}
void merge (pnode & t, pnode l, pnode r) {
    push(t);operation(t);
    if (! l ||! r)
        t = l? l: r;
    else if (l-> prior> r-> prior)
        merge (l-> r, l-> r, r), t = l;
    else
        merge (r-> l, l, r-> l), t = r;
    upd_sz (t);operation(t);
}


void split(pnode t, pnode & l, pnode & r, int pos, int add = 0) {
    if (! t) return void (l = r = 0);
    int cur_key = add + sz (t-> l);
    push(t);operation(t);
    if (pos <= cur_key)
        split (t-> l, l, t-> l, pos, add), r = t;
    else
        split (t-> r, t-> r, r, pos, add + 1 + sz (t-> l)), l = t;
    upd_sz (t); operation(t);
     
}

void traversal(pnode start)
{ 
  if(!start)return;operation(start);
   if(start->l!=NULL ){traversal(start->l);}
   cout << start->val << " " ;
   if(start->r!=NULL ){traversal(start->r);}

}

int indexer(pnode &t,int val,int l)// passing a copy here
{
    pnode copy = t;
    int index = l, found = 0, add =0;
    while(found == 0)
    {
        if(copy->val == val) { found = 1; add = add + sz(copy->l);}
        else if(copy->l!=NULL){if(copy->l->rmq == val) copy = copy ->l;}
        else if(copy->r!=NULL){if(copy->r->rmq == val) {add=add+sz(copy->l)+1;copy = copy ->l;};};
    } 
    return add+l;
}

int multiquery (pnode &t, int l, int r,int type,int value) {
    pnode t1, t2, t3;int ans=0;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l + 1);
    if(type==1)t2-> rev ^= true;
    if(type==2)ans=t2->sum;
    if(type==3)t2->lazy+=value;
    if(type==4)ans=t2->maxsum;
    if(type==6)ans=t2->rmq;
    if(type==8){ans=indexer(t2,t2->rmq,l);}
    merge (t, t1, t2);
    merge (t, t, t3);
    return ans;
}

void insert(int pos)
{
   lef=righ=NULL;split(Treap,lef,righ,pos,0);Treap=NULL;
   merge(Treap,lef,it);merge(Treap,Treap,righ);
}

pnode init(int value){
    pnode ret = (pnode)malloc(sizeof(node));ret->visited=0;ret->rev=false;
    ret->prior=rand()%200;ret->val=value;ret->size=1;ret->l=ret->r=NULL;ret->sum=value;
    ret->lazy=0;    ret->prefixMaxSum=0;ret->suffixMaxSum=0;ret->maxsum=value;
    ret->rmq = ret->val;
    cout << (ret->prior) << "  This is that \n";
    return ret;
}


int main()
{
   int value, n, a, b, c, pos, type;
   cin >> n;
   fa(i,0,n){cin >> type;
         if(type==1){ cin >> value >> pos;it= init(value);                       
                     if(i==0)Treap=it; else insert(pos-1);traversal(Treap);cout<<"\n";}
         if(type==2){cin >> a >> b;cout << multiquery(Treap,a-1,b-1,2,0) <<"\n";}
         if(type==3){cin >> a >> b >> c;multiquery(Treap,a-1,b-1,3,c);} 
         if(type==4){cin >> a >> b;cout << multiquery(Treap,a-1,b-1,4,0) <<"\n";}
         if(type==5){traversal(Treap);cout <<"\n";}
         if(type==6){cin >> a >> b;cout << multiquery(Treap,a-1,b-1,6,0) <<"\n";}
         if(type==8){cin >> a >> b;cout << multiquery(Treap,a-1,b-1,8,0) <<"\n";}
         if(type==7){cin >> a >> b;multiquery(Treap,a-1,b-1,1,0);cout << "\n";traversal(Treap);}
         }
   fa(i,0,n){cin >> a >> b;multiquery(Treap,a-1,b-1,1,0);cout << "\n";traversal(Treap);}
    
    cout <<"\n";

}
/*
1 - > inserting stuff at position i 
5 - > traversal query
Subset queries
2 - > sum of the that value
3 - > adding a value to a range
4 - > maxsum in a subset
6 - > rmq in a subset
7 - > reverse a given range

*/
/*
Random Sample 
100
1 13 1
1 2  2
1 41 1
1 44 2
1 98 3
1 1  5
1 9  1

2 1 3
2 3 6 
2 4 7 

3 1 3
3 5 7
3 2 5
3 4 6




1 2
4 7
1 6
1 7
*/