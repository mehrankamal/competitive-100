/*
*	author: mkbaloch
*	2021-09-10 00:59:31
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
        int n;
        cin >> n;
        int max_poss = 0;
        vector<int> coins(n);
        for(int i=0; i<n; i++){
            cin >> coins[i];
            max_poss += coins[i];
        }

        vector<vector<bool>> knapsack(n+1, vector<bool>(max_poss + 1, false));

        knapsack[0][0] = true;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=max_poss; j++){
                knapsack[i][j] = knapsack[i-1][j];
                if(j - coins[i-1] >= 0 && knapsack[i-1][j-coins[i-1]])
                    knapsack[i][j] = true;
            }
        }

        vector<int> possible;

        for(int i=1; i<=max_poss; i++){
           if(knapsack[n][i]) possible.push_back(i);
        }

        cout << possible.size() << endl;
        for(auto poss : possible)
            cout << poss << " ";
        cout << endl;



    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6));
    #endif
    return 0;
}
