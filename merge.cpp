#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long

int n, x;

void Merge( vector<int>& a, int left, int mid, int right ) {
    //copiez jumatate intr-un vector si jumatate in altul
    //apoi interclasez
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i=0; i<n1; ++i)
        L[i] = a[left + i];
    for (int i=0; i<n2; ++i)
        R[i] = a[mid + i + 1];

    int i=0, j=0, k=left;

    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            ++k;
            ++i;
        }
        else {
            a[k] = R[j];
            ++k;
            ++j;
        }
    }
    while (i < n1) {
        a[k] = L[i];
        ++k;
        ++i;
    }
    while (j < n2) {
        a[k] = R[j];
        ++k;
        ++j;
    }
}

void mergeSort( vector<int>& a, int left, int right ) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    Merge(a, left, mid, right);
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

    mergeSort(a, 0, n-1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    assert( is_sorted(a.begin(), a.end()) );

    cout << duration.count() << '\n';
    return 0;
}
