#include <bits/stdc++.h>
using namespace std;

void wypisz(int A[], int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void heapify(int A[], int n, int i){
    int d = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && A[l] > A[d]){
        d = l;
    }
    if(r < n && A[r] > A[d]){
        d = r;
    }
    if(d != i){
        int t = A[i];
        A[i] = A[d];
        A[d] = t;
        heapify(A, n, d);
    }
}

void heap_sort(int A[], int n){
    for(int i=n/2 - 1; i>=0; i--){
        heapify(A, n, i);
    }
    for(int i=n - 1; i>0; i--){
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        heapify(A, i, 0);
    }
}

void mod_heapify(int A[], int n, int i) {
    int d = i;
    int c1 = 3 * i + 1;
    int c2 = 3 * i + 2;
    int c3 = 3 * i + 3;

    if(c1 < n && A[c1] > A[d]){
        d = c1;
    }
    if(c2 < n && A[c2] > A[d]){
        d = c2;
    }
    if(c3 < n && A[c3] > A[d]){
        d = c3;
    }
    if(d != i){
        int t = A[i];
        A[i] = A[d];
        A[d] = t;
        mod_heapify(A, n, d);
    }
}

void mod_heap_sort(int A[], int n){
    for(int i=(n - 2)/3; i>=0; i--){
        mod_heapify(A, n, i);
    }
    for(int i=n - 1; i>0; i--){
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        mod_heapify(A, i, 0);
    }
}

int main(){
    int tab[] = {1, 2, 4, 3, 5, 6, 77, 11, 12, 13, 33, 76, 67, 1, 1, 0, 0, 5, 7, 66, 66, 33};
    int n = sizeof(tab) / sizeof(tab[0]);

    int temp_tab[n];

    copy(tab, tab + n, temp_tab);
    heap_sort(temp_tab, n);
    wypisz(temp_tab, n);

    copy(tab, tab + n, temp_tab);
    mod_heap_sort(temp_tab, n);
    wypisz(temp_tab, n);

    return 0;
}
