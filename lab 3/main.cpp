#include <iostream>
#include <cmath>
#include "output.h"

using namespace std;

double y(double x, int n) {
    if (n <= 0){
        return 0;
    } 
    if (x <= 0) {
        double product = 1;
        for (int i = 0; i <= n - 1; i++) {
            double term = pow(i, 3) + x;
            product *= term;
        }
        return x + product;
    }
    if (x > 0) {
        double sum = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                sum += (x / (i + j));
            }
        }
        return sum;
    }
    return 0;
}

int main() {
	double start, end, step;
	int n;

	cout << "Input start, end of interval, step and value of n: ";
	cin >> start >> end >> step >> n;

	cout << "\nTable for calculated function y:" << endl;
	PrintFunction(start, end, step, n, FunctionY);

	cout << "\nTable for calculated square root of x:" << endl;
	PrintFunction(start, end, step, n, squareRoot);

	return 0;
}