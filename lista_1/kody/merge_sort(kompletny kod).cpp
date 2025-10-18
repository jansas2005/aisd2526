#include <bits/stdc++.h>
using namespace std;

void wypisz(int A[], int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void merge_s(int A[], int p, int s, int k, long long& porownania, long long& przypisania){
    int r_L = s - p + 1;
    int r_P = k - s;

    int L[r_L];
    int P[r_P];

    for(int i=0; i<r_L; i++){
        L[i] = A[p + i];
        przypisania++;
    }
    for(int j=0; j<r_P; j++){
        P[j] = A[s + 1 + j];
        przypisania++;
    }
    int i = 0, j = 0, w = p;

    while(i < r_L && j < r_P){
        porownania++;
        if(L[i] <= P[j]){
            A[w] = L[i];
            i++;
        }
        else{
            A[w] = P[j];
            j++;
        }
        przypisania++;
        w++;
    }
    while(i < r_L){
        A[w] = L[i];
        przypisania++;
        i++;
        w++;
    }
    while(j < r_P){
        A[w] = P[j];
        przypisania++;
        j++;
        w++;
    }
}

void merge_sort(int A[], int p, int k, long long& porownania, long long& przypisania){
    if(p < k){
        int s = p + (k - p) / 2;

        merge_sort(A, p, s, porownania, przypisania);
        merge_sort(A, s + 1, k, porownania, przypisania);

        merge_s(A, p, s, k, porownania, przypisania);
    }
}

void mod_merge_s(int A[], int p, int s1, int s2, int k, long long& porownania, long long& przypisania){
    int r_L = s1 - p + 1;
    int r_S = s2 - s1;
    int r_P = k - s2;

    int L[r_L];
    int S[r_S];
    int P[r_P];

    for(int i=0; i<r_L; i++){
        L[i] = A[p + i];
        przypisania++;
    }
    for(int j=0; j<r_S; j++){
        S[j] = A[s1 + 1 + j];
        przypisania++;
    }
    for(int l=0; l<r_P; l++){
        P[l] = A[s2 + 1 + l];
        przypisania++;
    }
    int i = 0, j = 0, l = 0, w = p;

    while(i < r_L && j < r_S && l < r_P){
        porownania++;
        przypisania++;
        if(L[i] <= S[j]){
            porownania++;
            if(L[i] <= P[l]){
                A[w] = L[i];
                i++;
            } else {
                A[w] = P[l];
                l++;
            }
        } else {
            porownania++;
            if(S[j] <= P[l]){
                A[w] = S[j];
                j++;
            } else {
                A[w] = P[l];
                l++;
            }
        }
        w++;
    }
    while(i < r_L && j < r_S){
        porownania++;
        if(L[i] <= S[j]){
            A[w] = L[i];
            i++;
        } else {
            A[w] = S[j];
            j++;
        }
        przypisania++;
        w++;
    }
    while(i < r_L && l < r_P){
        porownania++;
        if(L[i] <= P[l]){
            A[w] = L[i];
            i++;
        } else {
            A[w] = P[l];
            l++;
        }
        przypisania++;
        w++;
    }
    while(j < r_S && l < r_P){
        porownania++;
        if(S[j] <= P[l]){
            A[w] = S[j];
            j++;
        } else {
            A[w] = P[l];
            l++;
        }
        przypisania++;
        w++;
    }
    while(i < r_L){
        A[w] = L[i];
        przypisania++;
        i++;
        w++;
    }
    while(j < r_S){
        A[w] = S[j];
        przypisania++;
        j++;
        w++;
    }
    while(l < r_P){
        A[w] = P[l];
        przypisania++;
        l++;
        w++;
    }
}

void mod_merge_sort(int A[], int p, int k, long long& porownania, long long& przypisania){
    if(p < k){
        int s1 = p + (k - p) / 3;
        int s2 = p + 2 * (k - p) / 3;

        mod_merge_sort(A, p, s1, porownania, przypisania);
        mod_merge_sort(A, s1 + 1, s2, porownania, przypisania);
        mod_merge_sort(A, s2 + 1, k, porownania, przypisania);

        mod_merge_s(A, p, s1, s2, k, porownania, przypisania);
    }
}
void insertion_sort(int n, int A[], long long& porownania, long long& przypisania){
    porownania = 0;
    przypisania = 0;
    for(int i=1; i<n; i++){
        int k = A[i];
        przypisania++;
        int j = i - 1;
        while(j >= 0){
            porownania++;
            if(A[j] > k){
                A[j + 1] = A[j];
                przypisania++;
                j--;
            }
            else{
                break;
            }
        }
        A[j + 1] = k;
        przypisania++;
    }
}

void mod_insertion_sort(int n, int A[], long long& porownania, long long& przypisania){
    porownania = 0;
    przypisania = 0;
    int i;
    for(i=1; i<n - 1; i+=2){
        int m_k, d_k;
        porownania++;
        if(A[i] > A[i+1]){
            d_k = A[i];
            m_k = A[i+1];
        }
        else{
            m_k = A[i];
            d_k = A[i+1];
        }
        przypisania+=2;
        int j = i - 1;
        while(j >= 0){
            porownania++;
            if(A[j] > d_k){
                A[j + 2] = A[j];
                j--;
                przypisania++;
            }
            else{
                break;
            }
        }
        A[j + 2] = d_k;
        przypisania++;
        while(j >= 0){
            porownania++;
            if(A[j] > m_k){
                A[j + 1] = A[j];
                j--;
                przypisania++;
            }
            else{
                break;
            }
        }
        A[j + 1] = m_k;
        przypisania++;
    }
    if(i < n){
        int o_k = A[i];
        int j = i - 1;
        przypisania++;
        while(j >= 0){
            porownania++;
            if(A[j] > o_k){
                A[j + 1] = A[j];
                j--;
                przypisania++;
            }
            else{
                break;
            }
        }
        A[j + 1] = o_k;
        przypisania++;
    }
}

int main(){
    int tab[] = {1, 2, 4, 3, 5, 6, 77, 11, 12, 13, 33, 76, 67, 1, 1, 0, 0, 5, 7, 66, 66, 33};
    int n = sizeof(tab) / sizeof(tab[0]);

    int temp_tab[n];
    long long porownania = 0;
    long long przypisania = 0;

    copy(tab, tab + n, temp_tab);
    merge_sort(temp_tab, 0, n - 1, porownania, przypisania);
    cout << "Posortowana tablica (standard):" << endl;
    wypisz(temp_tab, n);
    cout << "Porownania: " << porownania << ", Przypisania: " << przypisania << endl << endl;

    copy(tab, tab + n, temp_tab);
    porownania = 0;
    przypisania = 0;
    mod_merge_sort(temp_tab, 0, n - 1, porownania, przypisania);
    cout << "Posortowana tablica (modyfikacja):" << endl;
    wypisz(temp_tab, n);
    cout << "Porownania: " << porownania << ", Przypisania: " << przypisania << endl;

    return 0;
}

