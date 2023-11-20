#include <bits/stdc++.h>

#include <iostream>
#define int long long
#define endl '\n'
using namespace std;
int a[200010];
int b[200010] = {0};
signed main() {
    int i, j, t, k, m, n, max1, max2, s = 0, sum;
    cin >> m >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    max1 = 0;
    t = 0;
    for (i = 0; i < n; i++) {
        b[a[i]]++;
        if (max1 < b[a[i]]) {
            max1 = b[a[i]];
            t = a[i];
        } else if (max1 == b[a[i]])
            if (t > a[i]) {
                max1 = b[a[i]];
                t = a[i];
            }
        cout << t << endl;
    }
}