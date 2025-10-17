#include <bits/stdc++.h>
using namespace std;

void wypisz(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

void insertion_sort(int n, int A[]){
    for(int i=1; i<n; i++){
        int k = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > k){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = k;
    }
}

void mod_insertion_sort(int n, int A[]){
    int i;
    for(i = 1; i < n - 1; i += 2){
        int m_k, d_k;
        if(A[i] > A[i+1]){
            d_k = A[i];
            m_k = A[i+1];
        }
        else{
            m_k = A[i];
            d_k = A[i+1];
        }
        int j = i - 1;
        while(j >= 0 && A[j] > d_k){
            A[j + 2] = A[j];
            j--;
        }
        A[j + 2] = d_k;
        while(j >= 0 && A[j] > m_k){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = m_k;
    }
    if(i < n){
        int o_k = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > o_k){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = o_k;
    }
}
int main(){
    int tab[] = {1, 2, 4, 3, 5, 6, 77, 11, 12, 13, 33, 76, 67, 1, 1, 0, 0, 5, 7, 66, 66, 33};
    int n = sizeof(tab) / sizeof(tab[0]);

    int temp_tab[n];

    copy(tab, tab + n, temp_tab);
    insertion_sort(n, temp_tab);
    wypisz(temp_tab, n);

    copy(tab, tab + n, temp_tab);
    mod_insertion_sort(n, temp_tab);
    wypisz(temp_tab, n);

    return 0;
}
