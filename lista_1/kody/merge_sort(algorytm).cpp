#include <bits/stdc++.h>
using namespace std;

void wypisz(int A[], int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void merge_s(int A[], int p, int s, int k){
    int r_L = s - p + 1;
    int r_P = k - s;

    int L[r_L];
    int P[r_P];

    for(int i=0; i<r_L; i++){
        L[i] = A[p + i];
    }
    for(int j=0; j<r_P; j++){
        P[j] = A[s + 1 + j];
    }
    int i = 0, j = 0, w = p;

    while(i < r_L && j < r_P){
        if(L[i] <= P[j]){
            A[w] = L[i];
            i++;
        }
        else{
            A[w] = P[j];
            j++;
        }
        w++;
    }
    while(i < r_L){
        A[w] = L[i];
        i++;
        w++;
    }
    while(j < r_P){
        A[w] = P[j];
        j++;
        w++;
    }
}

void merge_sort(int A[], int p, int k){
    if(p < k){
        int s = p + (k - p) / 2;

        merge_sort(A, p, s);
        merge_sort(A, s + 1, k);

        merge_s(A, p, s, k);
    }
}

void mod_merge_s(int A[], int p, int s1, int s2, int k){
    int r_L = s1 - p + 1;
    int r_S = s2 - s1;
    int r_P = k - s2;

    int L[r_L];
    int S[r_S];
    int P[r_P];

    for(int i=0; i<r_L; i++){
        L[i] = A[p + i];
    }
    for(int j=0; j<r_S; j++){
        S[j] = A[s1 + 1 + j];
    }
    for(int l=0; l<r_P; l++){
        P[l] = A[s2 + 1 + l];
    }
    int i = 0, j = 0, l = 0, w = p;

    while(i < r_L && j < r_S && l < r_P){
        if(L[i] <= S[j] && L[i] <= P[l]){
            A[w] = L[i];
            i++;
        }
        else if(S[j] <= L[i] && S[j] <= P[l]){
            A[w] = S[j];
            j++;
        }
        else{
            A[w] = P[l];
            l++;
        }
        w++;
    }
    while(i < r_L && j < r_S){
        if(L[i] <= S[j]){
            A[w] = L[i];
            i++;
    }
        else{
            A[w] = S[j];
            j++;
        }
        w++;
    }
    while(i < r_L && l < r_P){
        if(L[i] <= P[l]){
            A[w] = L[i];
            i++;
        }
        else{
            A[w] = P[l];
            l++;
        }
        w++;
    }
    while(j < r_S && l < r_P){
        if(S[j] <= P[l]){
            A[w] = S[j];
            j++;
        }
        else{
            A[w] = P[l];
            l++;
        }
        w++;
        }
    while(i < r_L){
        A[w] = L[i];
        i++;
        w++;
    }
    while(j < r_S){
        A[w] = S[j];
        j++;
        w++;
    }
    while(l < r_P){
        A[w] = P[l];
        l++;
        w++;
    }
}

void mod_merge_sort(int A[], int p, int k){
    if(p < k){
        int s1 = p + (k - p) / 3;
        int s2 = p + 2 * (k - p) / 3;

        mod_merge_sort(A, p, s1);
        mod_merge_sort(A, s1 + 1, s2);
        mod_merge_sort(A, s2 + 1, k);

        mod_merge_s(A, p, s1, s2, k);
    }
}

int main(){
    int tab[] = {1, 2, 4, 3, 5, 6, 77, 11, 12, 13, 33, 76, 67, 1, 1, 0, 0, 5, 7, 66, 66, 33};
    int n = sizeof(tab) / sizeof(tab[0]);

    int temp_tab[n];

    copy(tab, tab + n, temp_tab);
    merge_sort(temp_tab, 0, n-1);
    wypisz(temp_tab, n);

    copy(tab, tab + n, temp_tab);
    mod_merge_sort(temp_tab, 0, n-1);
    wypisz(temp_tab, n);

    return 0;
}
