#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

void prostewybieranie(int a[], int n) {
    int k, x;                               // k - indeks minimalnego elementu; x - obiekt minimalny
    int counter = 0;

    for (int i = 0; i < n; i++) {
        k = i;
        x = a[i];                           // szukamy elementu minimalnego w ciagu a[i]...a[n]
        
        for (int j = i + 1; j < n; j++) {
            counter++;
            
            if (a[j] < x) {
                k = j;
                x = a[j];
            }
        }

        a[k] = a[i];
        swap(a[i], x);                      // zamieniamy element i-ty z min
    }

    cout << "Operacje dominujace: " << counter << endl;
}

int main() {
    int n = 10;
    int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    prostewybieranie(a, n);

    for (int x : a) {
        cout << x << endl;
    }

    for (int i = 0; i < 10; i++) {
        a[i] = 10 - i;
    }

    prostewybieranie(a, n);

    for (int x : a) {
        cout << x << endl;
    }

    srand(time(NULL));
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
            a[k] = (rand() % 1000) - 500;
        }

        prostewybieranie(a, n);

        for (int x : a) {
            cout << x << endl;
        }
    }
}