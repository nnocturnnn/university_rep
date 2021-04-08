#include <iostream>
#include <array>

double *addarray(double *arr1, double *arr2, int size) {
    double *arr = new double[size];

    for(int i=0;i<10;i++) {
        *(arr+i) = *(arr1 + i);
        *(arr+i+10) = *(arr1 + i);
    }
    return arr;
}

int main(int argc, char **argv) {
    int n = 10;
    double *arr = new double[n];
    double *arr1 = new double[n];
    for(int i=0;i<10;i++) {
        *(arr+i)=(double)rand()/RAND_MAX*(25.0-0.01)+0.01;
        *(arr1+i)=(double)rand()/RAND_MAX*(25.0-0.01)+0.01;
    }
    double *arr2 = addarray(arr, arr1, 20);
    for(int i=0;i<20;i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}