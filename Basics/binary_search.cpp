#include <bits/stdc++.h>
using namespace std;
#define forall(i,a,b)               for(int i=a;i<b;i++)
/*
   This is a compilation of binary search variants and what they do is one thing 
   return the p contains the largest index whose value is not larger than the search key
   The idea is to implement binary search like linear search but with larger steps. Variable p contains
   the current array index, and variable a contains the step length. 
   During the search, the step length is n, n/2, n/4, ..., 1.
   
   now their are three ways to use this 
   1 Existence check x[p]==k 
   2 lowerbound then x[p] is the lower bound or the largest thing just less than you 
   3 upper bound     x[p+1] is the upper bound because coz if it equals then the next is bigger
                            and if it does not then number is between x[p] and x[p+1]
                            

*/
int x[100];
int search( int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2)while (p+a < n && x[p+a] <= k) p += a;       
    return p;
}

/*A similar idea can be applied to binary search variations. For example, the following code counts 
how many times the key appears in the array. After the search, [p+1..q] is the range with value k.
it works in obvious manner the moment it find up what we need the first one ends 
whereas the other guy keeps going even after finding to hit the head with upperboud

while (l<r)
    {
          long long m = l + (r-l)/2;
          if (F(m*2,k)-F(m,k)<count) l = m+1;
          else
           r = m;
    }
    
*/

int count(int x[], int n, int k) {
    int p = -1, q = -1;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] < k) p += a;
        while (q+a < n && x[q+a] <= k) q += a;
    }
    return q-p;
}


/*Well, imagine you an array [0..n] and let us have an invariant: some function F which returns 
True for every a[i] as an argument for any i from [0..k] and False for every a[j] for j from [k+1..n-1]. 
Then my binarysearch which actually finds the border between
 these two parts of the array looks the following way:
 
 l=0, r = n-1, n
while r-l > 1:
    m = (l+r)//2
    if F(a[m]):
        l = m
    else:
        r = m
        
        l=k and r=k+1 by the end of the while loop.
        */

int main ()
{
   forall(i,0,20)x[i]=i*4+1;
   // This is an example of upper bound
   forall(i,0,20){int k=search(20,i);k=x[k+1];cout << "" << k << "\n";}
  return 0;
}