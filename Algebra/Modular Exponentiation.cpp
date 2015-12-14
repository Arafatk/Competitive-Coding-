#include <iostream>
#include <list>
#include <limits.h>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;

/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1) x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
// this function returns a^b mod c
long long powmodsimple(long long base,long long expo,long long modulus){
    long long i,j,k,l;l=1;
    for(i=0;i<expo;i++)l=(l*base)%modulus;
    return l;
}
long long powmod_binary(long long base,long long expo,long long modulus)
{
    long long i,j,k,l;l=1;
    base=base%modulus;
    while(expo>0)
    {
        if(expo%2==1)l=(l*base)%modulus;
        expo=expo >> 1;
        base=(base * base)%modulus;
    }
    return l;
}
int main()
{
  long long a,b,c;
  a=9;
  b=7;c=11;
  long long e=mulmod(a,b,c);
  printf("%lld\n",e);
  e=powmod_binary(2,9,511);
  printf("%lld",e);
}



















