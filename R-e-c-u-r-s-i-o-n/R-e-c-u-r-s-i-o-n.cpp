#include <iostream>
#include <string>

using namespace std;

void XN_input(int *X, int *N);
void num_changer(int *number);
void poly_in(int *polynom, int N);
int poly_rec(int *polynom, int N, int I, int X);
int der_poly_rec(int *polynom, int N, int I, int X);

int main() {
    int number;
	num_changer(&number);
	while (number) {
		if (number == 1) {
            int X, N;
            XN_input(&X, &N);
            int *polynom = new int[N];
            poly_in(polynom, N);
            printf("f(X) = %i on X = %i\n", poly_rec(polynom, N, 0, X), X);
            delete[] polynom;
        }
        if (number == 2) {
            int X, N;
            XN_input(&X, &N);
            int *polynom = new int[N];
            poly_in(polynom, N);
            printf("f'(X) = %i on X = %i\n", der_poly_rec(polynom, N, 0, X), X);
            delete[] polynom;
        }
        num_changer(&number);
    }
    return 0;
}

void XN_input(int* X, int* N) {
    printf("Enter the exp of the polynom - ");
    cin >> *N;
    printf("Enter the X for the polynom - ");
    cin >> *X;
    *N += 1;
}

void num_changer(int* number) {
	cout << "Enter the number or 0 to close - ";
	cin >> *number;
}

void poly_in(int *polynom, int N) {
    for (int i = 0; i < N; i++) {
        printf("Enter the %i coefficient - ", i + 1);
        cin >> polynom[i];
    }
}

int poly_rec(int *polynom, int N, int I, int X) {
    if (I == N - 1) return polynom[I];
    return polynom[I] * pow(float(X), N - I - 1) + poly_rec(polynom, N, I + 1, X);
}

int der_poly_rec(int *polynom, int N, int I, int X) {
    if (I == N - 2) return polynom[I];
    return polynom[I] * (N - I - 1) * pow(float(X), N - I - 2) + der_poly_rec(polynom, N, I + 1, X);
}