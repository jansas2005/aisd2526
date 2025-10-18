#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void wypisz(int A[], int n){
    int limit = min(n, 30);
    for(int i=0; i<limit; i++){
        cout << A[i] << " ";
    }
    if (n > limit) {
        cout << "...";
    }
    cout << "\n";
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
void heapify(int A[], int n, int i, long long& porownania, long long& przypisania){
    int d = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n){
        porownania++;
        if(A[l] > A[d]){
            d = l;
        }
    }
    if(r < n){
        porownania++;
        if(A[r] > A[d]){
            d = r;
        }
    }

    if(d != i){
        int t = A[i];
        A[i] = A[d];
        A[d] = t;
        przypisania += 3;
        heapify(A, n, d, porownania, przypisania);
    }
}

void heap_sort(int A[], int n, long long& porownania, long long& przypisania){
    porownania = 0;
    przypisania = 0;
    for(int i=n/2 - 1; i>=0; i--){
        heapify(A, n, i, porownania, przypisania);
    }
    for(int i=n - 1; i>0; i--){
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        przypisania += 3;
        heapify(A, i, 0, porownania, przypisania);
    }
}

void mod_heapify(int A[], int n, int i, long long& porownania, long long& przypisania){
    int d = i;
    int c1 = 3 * i + 1;
    int c2 = 3 * i + 2;
    int c3 = 3 * i + 3;

    if(c1 < n){
        porownania++;
        if(A[c1] > A[d]){
            d = c1;
        }
    }
    if(c2 < n){
        porownania++;
        if(A[c2] > A[d]){
            d = c2;
        }
    }
    if(c3 < n){
        porownania++;
        if(A[c3] > A[d]){
            d = c3;
        }
    }

    if(d != i){
        int t = A[i];
        A[i] = A[d];
        A[d] = t;
        przypisania += 3;
        mod_heapify(A, n, d, porownania, przypisania);
    }
}

void mod_heap_sort(int A[], int n, long long& porownania, long long& przypisania){
    porownania = 0;
    przypisania = 0;
    for(int i=(n - 2)/3; i>=0; i--){
        mod_heapify(A, n, i, porownania, przypisania);
    }
    for(int i=n - 1; i>0; i--){
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        przypisania += 3;
        mod_heapify(A, i, 0, porownania, przypisania);
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


int main(){
    vector<int> n_values = {100, 1000, 10000, 50000};

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 10000);

    cout << fixed << setprecision(3);

    for (int n : n_values) {
        cout << "==========================================" << endl;
        cout << "--- TESTY DLA n = " << n << " ---" << endl;
        cout << "==========================================" << endl;

        int* original_data = new int[n];
        int* temp_data = new int[n];
        long long porownania = 0;
        long long przypisania = 0;

        for(int i=0; i<n; i++) {
            original_data[i] = distrib(gen);
        }

        high_resolution_clock::time_point start, end;
        duration<double, milli> elapsed_ms;

        copy(original_data, original_data + n, temp_data);
        start = high_resolution_clock::now();
        insertion_sort(n, temp_data, porownania, przypisania);
        end = high_resolution_clock::now();
        elapsed_ms = end - start;
        cout << "Insertion Sort: \t" << porownania << " por, " << przypisania << " przy, " << elapsed_ms.count() << " ms" << endl;

        copy(original_data, original_data + n, temp_data);
        start = high_resolution_clock::now();
        mod_insertion_sort(n, temp_data, porownania, przypisania);
        end = high_resolution_clock::now();
        elapsed_ms = end - start;
        cout << "Mod Insertion Sort: \t" << porownania << " por, " << przypisania << " przy, " << elapsed_ms.count() << " ms" << endl;

        copy(original_data, original_data + n, temp_data);
        porownania = 0; przypisania = 0;
        start = high_resolution_clock::now();
        merge_sort(temp_data, 0, n - 1, porownania, przypisania);
        end = high_resolution_clock::now();
        elapsed_ms = end - start;
        cout << "Merge Sort: \t\t" << porownania << " por, " << przypisania << " przy, " << elapsed_ms.count() << " ms" << endl;

        copy(original_data, original_data + n, temp_data);
        porownania = 0; przypisania = 0;
        start = high_resolution_clock::now();
        mod_merge_sort(temp_data, 0, n - 1, porownania, przypisania);
        end = high_resolution_clock::now();
        elapsed_ms = end - start;
        cout << "Mod Merge Sort: \t" << porownania << " por, " << przypisania << " przy, " << elapsed_ms.count() << " ms" << endl;

        copy(original_data, original_data + n, temp_data);
        start = high_resolution_clock::now();
        heap_sort(temp_data, n, porownania, przypisania);
        end = high_resolution_clock::now();
        elapsed_ms = end - start;
        cout << "Heap Sort: \t\t" << porownania << " por, " << przypisania << " przy, " << elapsed_ms.count() << " ms" << endl;

        copy(original_data, original_data + n, temp_data);
        start = high_resolution_clock::now();
        mod_heap_sort(temp_data, n, porownania, przypisania);
        end = high_resolution_clock::now();
        elapsed_ms = end - start;
        cout << "Mod Heap Sort: \t\t" << porownania << " por, " << przypisania << " przy, " << elapsed_ms.count() << " ms" << endl;

        delete[] original_data;
        delete[] temp_data;

        cout << endl;
    }

    return 0;
}
