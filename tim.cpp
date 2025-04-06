#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
const int run = 32;
int n, x;

// sorteaza o bucata mica din vector
void insertionSort (vector<int>& a, int st, int dr) {

    for (int i=st+1; i<=dr; ++i) {
        int aux = a[i];
        int j = i - 1;

        while (j >= st && a[j] > aux) {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = aux;
    }
}

// lipeste bucatile sortate
void Merge( vector<int>& a, int st, int mij, int dr ) {

    int len1 = mij - st + 1;
    int len2 = dr - mij;
    vector<int> L(len1), R(len2);

    for (int i=0; i<len1; ++i)
        L[i] = a[st+i];
    for (int i=0; i<len2; ++i)
        R[i] = a[mij+1+i];

    int i=0, j=0, k=st;

    while (i < len1 && j < len2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            ++i; ++k;
        }
        else {
            a[k] = R[j];
            ++j; ++k;
        }
    }

    while (i < len1) {
        a[k] = L[i];
        ++i; ++k;
    }

    while (j < len2) {
        a[k] = R[j];
        ++j; ++k;
    }
}


void timSort( vector<int>&a, int n ) {

    for (int i=0; i<n; i+=run)
        insertionSort( a, i, min( (i+run-1), (n-1) ) );

    for (int s=run; s<n; s*=2) {

        for (int l=0; l<n; l+=2*s) {

            int mij = l + s - 1;
            int r = min( (l + 2*s - 1), (n-1) );

            if (mij < r)
                Merge(a, l, mij, r);
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    cin >> n;
    vector<int> a;

    for (int i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    auto start = high_resolution_clock::now();

    timSort(a, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    assert( is_sorted(a.begin(), a.end()) );

    cout << duration.count() << '\n';
    return 0;
}
