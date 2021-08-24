/*
*	author:		mkbaloch
*	datetime:	2021-08-24 23:23:49
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
    string a, b;
    cin >> a >> b;
    vector<vector<int>> edit(a.length() + 1, vector<int>(b.length() + 1, 0));

    for(int i=0; i<=(int)a.length(); i++){
        for(int j=0; j<=(int)b.length(); j++){
            
            if(i==0) edit[i][j] = j;
            else if(j==0) edit[i][j] = i;
            else if(a[i-1] != b[j-1]) edit[i][j] = min(edit[i-1][j], min(edit[i][j-1], edit[i-1][j-1])) + 1;
            else edit[i][j] = edit[i-1][j-1];
        }
    }
    
    cout << edit[a.length()][b.length()] << endl;
    //-------End---------//

    #ifdef LOCAL
        auto end = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(end - start);
        fprintf(stderr, "Execution time: %.6Lf seconds.\n", ((long double)dur.count() / 1e6)); 
    #endif

    return 0;
}