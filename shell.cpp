#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
int n, x;

void shellSort( vector<int>& a, int n )
{
    int p = 1;
    while (p * p - 1 <= n )
        p *= 2;
    p /= 2;

    for (int k = p; k > 1; k/=2) {
        int gap = k-1;

        for (int i=gap; i<n; ++i) {
            int aux = a[i];

            int j;
            for (j=i; j>=gap && a[j-gap] > aux; j-=gap)
                a[j] = a[j - gap];

            a[j] = aux;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    cin >> n;

    vector <int> a;

    for (int i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    auto start = high_resolution_clock::now();

    shellSort(a, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    assert( is_sorted(a.begin(), a.end()) );

    cout << duration.count() << '\n';
    return 0;
}
