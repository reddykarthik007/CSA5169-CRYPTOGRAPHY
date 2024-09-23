#include <stdio.h>
#include <math.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to approximate a number as a power of 2
double log2_approximation(unsigned long long number) {
    return log2((double)number);
}

int main() {
    // Number of letters in Playfair cipher (25 letters, I/J combined)
    int letters = 25;
    
    // Calculate 25!
    unsigned long long total_keys = factorial(letters);
    
    // Approximate the total keys as a power of 2
    double approx_power_of_2 = log2_approximation(total_keys);
    
    // Display the result
    printf("Number of possible Playfair cipher keys: %llu\n", total_keys);
    printf("Approximation as power of 2: 2^%.2f\n", approx_power_of_2);
    
    // Note: This does not yet account for keys producing identical encryption results
    return 0;
}
