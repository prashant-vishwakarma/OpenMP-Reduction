#include<iostream>
#include<omp.h>
#include<cstdlib>

using namespace std;

int findMin(int* a, int n) {
	int minimum = a[0];
#pragma omp parallel for reduction(min: minimum)
	for (int i = 0; i < n; i++) {
		minimum = min(a[i], minimum);
	}
	return minimum;
}

int findMax(int* a, int n) {
	int maximum = a[0];
#pragma omp parallel for reduction(max: maximum)
	for (int i = 0; i < n; i++) {
		maximum = max(a[i], maximum);
	}
	return maximum;
}

int getSum(int* a, int n) {
	int sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < n; i++) {
		sum = sum + a[i];
	}
	return sum;
}

int getAvg(int* a, int n) {
	int sum = 0;
#pragma omp parallel for reduction(+:sum)
	for (int i = 0; i < n; i++) {
		sum = sum + a[i];
	}
	return sum/n;
}

int main() {
	int* a = new int[100];
	int maximum = 0,minimum = 1000;
	for (int i = 0; i < 100; i++) {
		a[i] = rand() % 1000;
	}
	for (int i = 0; i < 100; i++) {
		cout << a[i] << endl;
	}
	cout << "Min: " << findMin(a, 100) << endl;
	cout << "Max: " << findMax(a, 100) << endl;
	cout << "Sum: " << getSum(a, 100) << endl;
	cout << "Avg: " << getAvg(a, 100) << endl;
	return 0;
}
