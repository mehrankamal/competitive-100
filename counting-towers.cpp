/*
*	author:		mkbaloch
*	datetime:	2021-08-24 23:09:30
*/

#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define deb(x) cerr << "[" << #x << ": " << x << "]" << endl;

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
        auto start = chrono::high_resolution_clock::now();
        freopen("inputf.txt", "r", stdin);
        freopen("outputf.txt", "w", stdout);
    #endif

    //-------Start-------//
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        ll dp[x][2];

        dp[0][0] = 1;
        dp[0][1] = 1;
        
        for(int i=1; i<x; i++){
            dp[i][0] = (dp[i-1][0] * 2 + dp[i-1][1]) % MOD;
            dp[i][1] = (4 * dp[i-1][1] + dp[i-1][0]) % MOD;
        }
        cout << (dp[x-1][0] + dp[x-1][1]) % MOD << endl;
    }
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}