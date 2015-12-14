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

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

/* This is an (n*log(n)*log(n)) approach for suffix array construction */

string S;
const int MAXN = 1 << 21;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

/*The reason why we are doing badly on the construction of the SA is because 
  we are NOT EXPLOITING 
  the fact that the strings we are sorting, are actually 
  all part of the SAME original string, and not random, unrelated
  strings.*/

bool sufCmp(int i, int j)
	{
		if (pos[i] != pos[j])
			return pos[i] < pos[j];
		i += gap;
		j += gap;
		
		/* Compare(S[i], S[j], t) is not '=', then the result of Compare(S[i], S[j], 2t) 
		   is the same as Compare(S[i], S[j], t).
           if Compare(S[i], S[j], t) is '=', then we should compare last t characters of 
           these two suffixes  (since the first t symbols are same), i.e.
           the result is equal to Compare(T[i+t .. n], T[j+t .. n], t), which 
           is equal to Compare(S[i+t], S[j+t], t). and since we know the result of this
           because of our        previous iteration  , we can find the 
           result of Compare(S[i], S[j], 2t) in O(1).*/
           
		return (i < N && j < N) ? pos[i] < pos[j] : i > j;
		/* Their is no such thing as two suffixes with identical length in cases of commonality we
		   use what one might call as the legth based comparision */
	}	


void buildSA() 
	{
		N = S.length();
		REP(i, N) sa[i] = i, pos[i] = S[i];
		for (gap = 1;; gap *= 2)
		{
			sort(sa, sa + N, sufCmp);
    	/*Basically on the first instance sa sorted the suffix strings of length 1 
    	lexicographically the first symbol of two suffixes which are in the same bucket are the same. 
    	we set t = 1. And same 	goes for the rest  So basically the tmp here 
    	checks the bucket ideas we
    	need to check to associate
    	the similar thing in same stuff */
			
			REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
		/*Now we set the position of the nth suffix array in its bucket  */
			REP(i, N) pos[sa[i]] = tmp[i];
		/*and if their is a case where our ability to choose up on things in different
		bucket is n-1 for n-1
		  then you my friend have officially sorted the whole thing
			  */
			if (tmp[N - 1] == N - 1) break;
		}
	}	
void buildLCP()
	{
		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
		{
			for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
			++k;
			lcp[pos[i]] = k;
			if (k)--k;
		}
	}	
/*

   The real reason behind building LCP 
   array is that you can find the least common Prefix of Any 
   Two substrings of the Array in Basically 
   O(1) When you use the idea of range minimum query of Seg Tree
   Why 
   Because LCM (i,j) = min (LCM(i,i+1),(i+1,i+2),....(j-1,j))
   Since we have some results we can get the LCP between any 
   Two Strings in O(1) using Nlog n *log n Construct suffix
   N log n Sparse Table
   And O(1) per query for Answering

  Eg Banana 
  Suffix array 
  a
  ana
  anana
  banana
  na
  nana

  The build LCp works like this first you know the suffix at the start 
  for example Banana has a suffix 
  Banana for i=0; 
  But what do you care about ?
  You care about matching of banana suffix with the guy ahead of him in the
  suffix array which is na
  But you figure out that their is no matchin so you set matching 
  Banana =0
  then you go for i=1 
  you now have anana as the suffix 
  You look for the next guy and you realise their is no matchin so you set matching 
  anana =0
  Now you look for i=2 
  you now have nana as the suffix 
  Since Nana is last in the sa we don't check and set 0 immediately
  Now you look for i=3 
  you now have ana as the suffix 
  you get the K after raising shit as k=3
  So we set 
  Ana has =3
  And so forth 
  na= 2
  a=1

*/	
int main()
{
    S="banana";
    buildSA();buildLCP();
forall(i,0,N){int j=sa[i];forall(k,j,N)cout << S[k]; cout <<"\n";}
cout <<"Guy at this position       The position of the guy who was here\n";
forall(i,0,N){cout <<sa[i] <<"                          " << pos[i] <<"          " ;
             cout << lcp[i] <<"\n"; }
}