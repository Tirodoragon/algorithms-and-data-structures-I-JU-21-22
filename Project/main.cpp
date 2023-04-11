#include <iostream>

using namespace std;

void Wypisz(int wielomian[], int n) {
    if (wielomian[n] != 0) {
        if (wielomian[n] == -1) {
            cout << '-';
        }

        if (wielomian[n] != 1 && wielomian[n] != -1) {
            cout << wielomian[n];
        }

        if (n != 1) {
            cout << "x^" << n;
        }
        else {
            cout << "x";
        }

        if (wielomian[n - 1] > 0) {
            cout << "+";
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if (wielomian[i] != 0) {
            if (wielomian[i] == -1) {
                cout << '-';
            }

            if (wielomian[i] != 1 && wielomian[i] != -1) {
                cout << wielomian[i];
            }

            if (i != 1) {
                cout << "x^" << i;
            }
            else {
                cout << "x";
            }
        }

        if (wielomian[i - 1] > 0) {
            cout << "+";
        }
    }

    if (wielomian[0] != 0) {
        cout << wielomian[0];
    }   

    cout << endl;
}

int *PodajPierwszyWielomian(int &m) {
        cout << "Podaj stopien pierwszego wielomianu: ";
        cin >> m;

        m++;
        int *A = new int[m];
        m--;

        for (int j = m; j >= 0; j--) {
            cout << "Podaj wspolczynnik a" << j << " pierwszego wielomianu: ";
            cin >> A[j];
        }

        cout << "Pierwszy wielomian to: ";
        Wypisz(A, m);

        return A;
}

int *PodajDrugiWielomian(int &n) {
        cout << "Podaj stopien drugiego wielomianu: ";
        cin >> n;

        n++;
        int *B = new int[n];
        n--;

        for (int k = n; k >= 0; k--) {
            cout << "Podaj wspolczynnik a" << k << " drugiego wielomianu: ";
            cin >> B[k];
        }

        cout << "Drugi wielomian to: ";
        Wypisz(B, n);

        return B;
}

int WiekszaLiczba(int m, int n) {
    return (m > n) ? m : n;
}

int *Dodaj(int A[], int B[], int m, int n) {
    m++;
    n++;
    int rozmiar = WiekszaLiczba(m, n);
    m--;
    n--;

    int *suma = new int[rozmiar];

    for (int l = 0; l <= m; l++) {
        suma[l] = A[l];
    }

    for (int o = 0; o <= n; o++) {
        suma[o] += B[o];
    }

    return suma;
}

int *Odejmij(int A[], int B[], int m, int n) {
    m++;
    n++;
    int rozmiar = WiekszaLiczba(m, n);
    m--;
    n--;

    int *roznica = new int[rozmiar];

    for (int p = 0; p <= m; p++) {
        roznica[p] = A[p];
    }

    for (int q = 0; q <= n; q++) {
        roznica[q] -= B[q];
    }

    return roznica;
}

int *Pomnoz(int A[], int B[], int m, int n) {
    int *iloczyn = new int[m + n];

    for (int r = 0; r <= m + n; r++) {
        iloczyn[r] = 0;
    }

    for (int s = 0; s <= m; s++) {
        for (int t = 0; t <= n; t++) {
            iloczyn[s + t] += A[s] * B[t];
            cout << iloczyn[s + t] << endl;
        }
    }

    return iloczyn;
}

int Horner(int A[], int m, int x) {
    int wynik;

    for (int u = m; u > 0; u--) {
        wynik = (wynik + A[u]) * x;
    }

    return wynik = wynik + A[0];
}

int main() {
    cout << "Mozliwe dzialania:" << endl;
    cout << "d - dodawanie" << endl;
    cout << "o - odejmowanie" << endl;
    cout << "m - mnozenie" << endl;
    cout << "h - obliczanie wartosci wielomianu (algorytm Hornera)" << endl;
    cout << "w - wyjscie" << endl;

    cout << endl;

    bool koniec = false;
    char dzialanie;
    int m;
    int n;
    int *A;
    int *B;
    int *suma;
    int *roznica;
    int *iloczyn;
    int rozmiar;
    int x;
    int wartosc;
    while (!koniec) {
        cout << "Wybierz dzialanie: ";
        cin >> dzialanie;
        switch (dzialanie) {
            case 'd':
                A = PodajPierwszyWielomian(m);

                B = PodajDrugiWielomian(n);

                suma = Dodaj(A, B, m, n);

                m++;
                n++;
                rozmiar = WiekszaLiczba(m, n);

                cout << "Suma wielomianow to: ";
                Wypisz(suma, rozmiar - 1);

                cout << endl;

                delete[] A;
                delete[] B;
                delete[] suma;

                m = 0;
                n = 0;
                
                rozmiar = 0;

                break;

            case 'o':
                A = PodajPierwszyWielomian(m);

                B = PodajDrugiWielomian(n);

                roznica = Odejmij(A, B, m, n);
                
                m++;
                n++;
                rozmiar = WiekszaLiczba(m, n);

                cout << "Roznica wielomianow to: ";
                Wypisz(roznica, rozmiar - 1);

                cout << endl;

                delete[] A;
                delete[] B;
                delete[] roznica;

                m = 0;
                n = 0;
                rozmiar = 0;

                break;

            case 'm':
                A = PodajPierwszyWielomian(m);

                B = PodajDrugiWielomian(n);

                iloczyn = Pomnoz(A, B, m, n);

                cout << "Iloczyn wielomianow to: ";
                Wypisz(iloczyn, m + n);

                cout << endl;

                delete[] A;
                delete[] B;

                m = 0;
                n = 0;

                break;

            case 'h':
                A = PodajPierwszyWielomian(m);

                cout << "Podaj wartosc x: ";
                cin >> x;
                
                wartosc = Horner(A, m, x);
                cout << "Wartosc wielomianu to: " << wartosc << endl;

                cout << endl;

                delete[] A;

                m = 0;
                x = 0;

                break;

            case 'w':
                koniec = true;

                cout << "Zamknieto program." << endl;

                cout << endl;

                break;

            default:
                cout << "Podane dzialanie jest bledne. Prosze podac poprawne dzialanie: \"d, o, m, h, lub w\"" << endl;

                cout << endl;

                break;
        }
    }
}