/*
*	author:		mkbaloch
*	datetime:	2021-08-22 08:54:15
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
        freopen("outputf.txt", "w", stdout);
    #endif

    //-------Start-------//
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> pos(n);
    
    for(int i=0; i<n; i++){
        cin >> nums[i];
        pos[nums[i] - 1] = i;
    }

    int rounds=1;
    for(int i=1; i<n; i++){
        if(pos[i] < pos[i-1])
            rounds++;
    }
    cout << rounds << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}