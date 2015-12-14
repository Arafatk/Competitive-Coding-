#include<bits/stdc++.h>

using namespace std;
/*
 This is the use terenary search for convex function which are first strictly increasing 
 and then strictly decreasing 

*/
while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(f(mid) > f(mid+1)) {
        hi = mid;
    }
    else {
        lo = mid+1;
    }
}
/*You'd normally use binary search for finding an element from an increasing sequence of values, 
and ternary search for finding the maximum when the values first increase and then start decreasing 
at some point.
The observation here is that you can replace ternary search with a binary search for the point
when the sign between adjacent values change. This is of course a simple thing, but in many places
you can find the
recommended solution being ternary search, which is harder to get right and less efficient.
What you're doing is very similar to binary search on continuous derivative (which may be 
useful for some floating-point problems, because calculating derivative may be performed 
with more precision sometimes). If it is below zero until some point and is above zero after
that point, then local optima is in the point where derivative is zero. 
You've calculated discrete derivative and look for a point where it changes the sign.*/