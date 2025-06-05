#ifndef FUNCTION_TABLE_H
#define FUNCTION_TABLE_H

typedef double (*MathFunc)(double, int);
double squareRoot(double x, int n); 
void PrintFunction(double start, double end, double step, int n, MathFunc func);

#endif