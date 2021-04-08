#include <iostream>
#include <array>

int main(int argc, char **argv) {
    int n = 10;
    double *arr = new double[n];
    double buff;
    double arif;

    for (int i = 0; i < n; i++) {
        std::cin >> buff;
        arif += buff;
        *(arr+i) = buff;
    }
    arif = arif / 10;
    std::cout << "Mid num : " << arif << std::endl;

    return 0;
}