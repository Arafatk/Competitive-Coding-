#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz size
#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define forall(i,a,b)               for(int i=a;i<b;i++)

typedef long long int lld;
typedef pair < int, int > pii;
#define MAXN 1000
#define MAXLOGN 10

/*This is the usage of range minimm query using  And then for each query, first of all, 
find the maximum x such that 2^x<=r-l+1 and answer is min(st[l][x],st[r-2^x+1][x]) 
so basically we got the two ki power smaller than their distance and now we need the minimum
between the starting + 2 ki power and ending - 2 ki power this can obviously never 
exceed the r-l+1 as their is over lap not exceeding and  
So, the main idea of Sparse Table, is to keep the value for each interval of length 2k 
for each possible k
You can use the same idea for LCA problem and so many other problems. */

int M[MAXN][MAXLOGN];
void Compute_ST(int A[],int N){
    int i,j;
    for(i=0;i<N;i++)
        M[i][0]=i;
    for(j=1;1<<j <=N ;j++){
        for(i=0;i+(1<<(j-1))<N;i++){
            if(A[M[i][j-1]]<=A[M[i+(1<<(j-1))][j-1]])
                M[i][j]=M[i][j-1];
            else
                M[i][j]=M[i+(1<<(j-1))][j-1];
        }
    }
}
int RMQ(int A[],int s,int e){
    int k=e-s;
    k=31-__builtin_clz(k+1); // k = log(e-s+1)
    if(A[M[s][k]]<=A[M[e-(1<<k)+1][k]])
        return A[M[s][k]];
    return A[M[e-(1<<k)+1][k]];
}
// driver programme
int main(){
    int A[10] = {3,1,2,-1,5,4,6,0,9,8};
    Compute_ST(A,10);
    int s,e;
    forall(i,0,10)
    {
        scanf("%d %d",&s,&e);
        printf("%d\n",RMQ(A,s,e));
    }
   
    return 0;
}