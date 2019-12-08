#include <stdlib.h>
#include <time.h>
#include <iostream>

bool randomPointBelongsToQ(double x, double y) {
    return ((x * x) + (y * y) <= 1);
}

int main() {
    int n = 1000000; // Number of iteration to generate random points
    double nq = 0; // The counter to increase if (x, y) belongs to Q
    double pi = 0.0; // Final appromximate value of pi (π)

    std::cout << "===[ MC Simulation: Approximation of π ]===" << std::endl;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        // we generate a random point (x, y)
        double x = ((double) rand() / RAND_MAX); // x random number between 0 and 1
        double y = ((double) rand() / RAND_MAX); // y random number between 0 and 1
        if(randomPointBelongsToQ(x, y)) nq++;
    }
    pi = (nq / n) * 4; // Because nq / n = π / 4
    std::cout << "number of iteration = " << n << std::endl;
    std::cout << "nq = " << nq << std::endl;
    std::cout << "π = (" << nq << " / " << n << ") * 4 = " << pi << std::endl;
    return 0;
}