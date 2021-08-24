/*
*	author:		mkbaloch
*	datetime:	2021-08-24 22:18:05
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int> (m + 1, 0));
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    if(arr[0] == 0){
        for(int i=1; i<=m; i++) dp[0][i] = 1;
    } else {
        dp[0][arr[0]] = 1;
    }
    
    for(int i=1; i<n; i++){
        if(arr[i] == 0){
            for(int j=1; j<=m; j++){
                for(int k=-1; k<=1; k++){
                    if(j+k > 0 && j+k <= m) dp[i][j] += dp[i-1][j+k];
                    dp[i][j] %= MOD;
                }
            }
        } else {
            int dir[] = {-1, 0, 1};
            for(auto k: dir){
                if(arr[i] + k > 0 && arr[i] + k <= m){
                    dp[i][arr[i]] += dp[i-1][arr[i] + k];
                    dp[i][arr[i]] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=m; i++){
        ans += dp[n-1][i];
        ans %= MOD;
    }

    cout << ans << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}