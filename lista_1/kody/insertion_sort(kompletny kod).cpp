#include <bits/stdc++.h>
using namespace std;

void wypisz(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
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
    insertion_sort(n, temp_tab, porownania, przypisania);
    wypisz(temp_tab, n);
    cout << "Porownania: " << porownania << ", Przypisania: " << przypisania << endl << endl;

    copy(tab, tab + n, temp_tab);
    mod_insertion_sort(n, temp_tab, porownania, przypisania);
    wypisz(temp_tab, n);
    cout << "Porownania: " << porownania << ", Przypisania: " << przypisania << endl;

    return 0;
}
