/*
*	author:		mkbaloch
*	datetime:	2021-08-23 07:25:29
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
    int x, n;
    cin >> x >> n;

    set<int> bounds;
    bounds.insert(0);
    bounds.insert(x);

    multiset<int> partitions;
    partitions.insert(x);

    for(int i=0; i<n; i++){
        int light;
        cin >> light;

        bounds.insert(light);
        auto prev_it = prev(bounds.find(light));
        auto next_it = next(bounds.find(light));

        partitions.erase(partitions.find(*next_it - *prev_it));
        partitions.insert(light - *prev_it);
        partitions.insert(*next_it - light);

        cout << *partitions.rbegin() << endl;
    }

    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}