#include <bits/stdc++.h>
using namespace std;

#define forall(i,a,b)               for(int i=a;i<b;i++)

int main () {
  int myints[] = {1,2,3,4,5};

  std::sort (myints,myints+5);
  int num=1;
  std::cout << "The 5! possible permutations with 5 elements:\n";
  do {  cout << num << "  ";num++;
   cout << myints[0]  << myints[1]  << myints[2] << myints[3] << myints[4]<<"\n" ;
  } while ( std::next_permutation(myints,myints+5) );

  return 0;
}