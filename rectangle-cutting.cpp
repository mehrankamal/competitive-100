/*
*	author: mkbaloch
*	2021-09-10 00:25:47
*/

#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define deb(x) cerr << "[" << #x << ": " << x << "]" << endl;

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
        auto start = chrono::high_resolution_clock::now();
        freopen("inputf.txt", "r", stdin);
    #endif

    //-------Start-------//
        int r, c;
        cin >> r >> c;

        int dp[r + 1][c + 1];

        for(int i=0; i<=r; i++)
            for(int j=0; j<=c; j++)
                dp[i][j] = INT_MAX;

        int sqs = min(r, c);
        for(int i=1; i<=sqs; i++)
            dp[i][i] = 0;

        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                for(int k=1; k<i; k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                for(int k=1; k<j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }

        cout << dp[r][c] << endl;

    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6));
    #endif
    return 0;
}
