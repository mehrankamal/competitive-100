/*
*	author:		mkbaloch
*	datetime:	2021-08-18 02:10:29
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
    int t;
    cin >> t;
    while(t--){
        ll y, x;
        cin >> y >> x;
        ll ans;
        if (x>y){
            ans = (((x&1) == 1) ? (x * x - y + 1) : (((x - 1) * (x- 1)) + y));
        } else {
            ans = (((y&1) == 1) ? (((y - 1) * (y - 1))  + x) : (y * y - x + 1));
        }
        cout << ans << endl;
    }
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}