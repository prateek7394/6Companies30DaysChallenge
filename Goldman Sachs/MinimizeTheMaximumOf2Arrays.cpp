// Problem: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/

// We have two arrays arr1 and arr2 which are initially empty.
// You need to add positive integers to them such that they satisfy all the following conditions:
// arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
// arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
// No integer is present in both arr1 and arr2.

// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer
// that can be present in either array.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll lcm (ll a, ll b){
    return (a*b)/(__gcd(a,b));
}
bool check (ll mid, ll d1, ll d2, ll c1, ll c2){
    ll divisibleByd1 = mid/d1;
    ll divisibleByd2 = mid/d2;
    ll divisibleByBoth = mid/lcm(d1, d2);

    ll a = mid - divisibleByd1; // notDivisibleByd1
    ll b = mid - divisibleByd2; // notDivisibleByd2
    ll c = mid - divisibleByBoth; // notDivisibleByBoth

    if(a>=c1 && b>=c2 && c>=c1+c2){
        return true;
    }

    return false;
}
int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    int s=1, e=INT_MAX;
    int ans = -1;

    while(s<=e){
        int mid = s+(e-s)/2;
    // here mid represents minimum possible max overall value among both arrays

        if(check(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}