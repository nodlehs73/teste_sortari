/**
Primul element ca pivot

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
int n, x;

int partition( vector<int>&a, int st, int dr ) {

    int pivot = a[dr];

    int i = st;
    for (int j=st; j<dr; ++j)
        if (a[j] <= pivot)
            swap (a[i++], a[j]);

    swap (a[i], a[dr]);

    return i;
}

void quickSort( vector<int>&a, int st, int dr ) {

    if (st < dr) {
        int index = partition(a, st, dr);
        quickSort( a, st, index-1 );
        quickSort( a, index+1, dr );
    }
}

signed main()
{
    cin >> n;
    vector <int> a;

    for (int i=0; i<n; ++i) {
        cin >> x;
        a.push_back(x);
    }

    auto start = high_resolution_clock::now();

    quickSort(a, 0, n-1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    assert( is_sorted(a.begin(), a.end()) );

    cout << duration.count() << '\n';
    return 0;
}
*/

/**
Pivotul ca mediana din 5 elemente alese random
*/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int long long
int n, x;

pair <int, int>medianOf5( vector<int>& a, int st, int dr ) {

    //generam aleator 5 indici in int [st, dr]
    int lungime = dr - st + 1;

    set<int> indici;

    while (indici.size() < min(5, lungime) ) {
        int indiceRandom = rand() % lungime + st;
        indici.insert( indiceRandom );
    }

    vector< pair<int,int> > v;

    set<int>::iterator x;
    for (x = indici.begin(); x!=indici.end(); ++x) {
        v.push_back( {a[*x], *x} );
    }

    for (int i=0; i<v.size(); ++i)
    {
        int mi = v[i].first, miIndex = i;
        for( int j = i+1; j<v.size(); ++j )
            if( v[j].first < mi ) {
                mi = v[j].first;
                miIndex = j;
            }
        if (miIndex != i)
            swap (v[i], v[miIndex]);
    }

    return v[ (v.size()/2) ];

}

int Partition( vector<int>&a, int st, int dr ) {

    pair <int, int> pivotPair = medianOf5(a, st, dr);
    int pivot = pivotPair.first;
    int pivotIndex = pivotPair.second;

    swap(a[dr], a[pivotIndex]);

    int i = st;
    for (int j=st; j<dr; ++j)
        if (a[j] <= pivot)
            swap (a[i++], a[j]);

    swap (a[i], a[dr]);

    return i;
}

void quickSort( vector<int>&a, int st, int dr ) {

    if (st < dr) {
        int index = Partition(a, st, dr);
        quickSort( a, st, index-1 );
        quickSort( a, index+1, dr );
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

    srand(time(0));

    auto start = high_resolution_clock::now();

    quickSort(a, 0, n-1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << '\n';

    assert( is_sorted(a.begin(), a.end()) );
    return 0;
}
// 87 25 39 42 13 54 61 98 31 73 50 66 19 5 11
