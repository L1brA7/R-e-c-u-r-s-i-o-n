#include <iostream>
#include <string>

using namespace std;

void poly_in(int *polynom, int N);
int poly_rec(int *polynom, int N, int I, int X);
void poly_out(int *polynom, int N);

int main() {
    int X, N;
	printf("Enter the exp of the polynom - ");
	cin >> N;
    printf("Enter the X for the polynom - ");
    cin >> X;
    N++; //так как место для свободного члена
    int *polynom = new int[N];
    poly_in(polynom, N);
    poly_out(polynom, N);
    printf(" = %i on X = %i", poly_rec(polynom, N, 0, X), X);
}

void poly_in(int *polynom, int N) {
    for (int i = 0; i < N; i++) {
        printf("Enter the %i coefficient - ", i + 1);
        cin >> polynom[i];
    }
}

int poly_rec(int *polynom, int N, int I, int X) {
    if (I == N) return 0;
    return polynom[I] * pow(float(X), N - I - 1) + poly_rec(polynom, N, I + 1, X);
}

void poly_out(int *polynom, int N) {
    for (int i = 0; i < N; i++) {
        if (polynom[i] != 0) {
            if (i == N - 1) cout << polynom[i];
            else printf("(%i*x^%i) + ", polynom[i], N - i - 1);
        }
    }
}