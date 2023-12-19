#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp < l)
            cout << l << " ";
        else if (tmp > r)
            cout << r << " ";
        else
            cout << tmp << " ";
    }

    return 0;
}
