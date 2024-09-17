#include <stdio.h>
#include <ctype.h>

#define MOD 26

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}
char affineDecrypt(char c, int a, int b) {
    int a_inv = modInverse(a, MOD);
    
    if (a_inv == -1) {
        printf("No modular inverse found for a = %d\n", a);
        return '\0';
    }
    
    int c_num = toupper(c) - 'A';
    int p_num = (a_inv * (c_num - b + MOD)) % MOD;
    
    return p_num + 'A';
}
void breakAffineCipher(char cipherText[], char freq1, char freq2) {
    for (int a = 1; a < MOD; a++) {
        if (gcd(a, MOD) != 1) continue; 
        
        for (int b = 0; b < MOD; b++) {
            char dec1 = affineDecrypt(freq1, a, b);
            char dec2 = affineDecrypt(freq2, a, b);
            
            printf("Trying a = %d, b = %d: Dec1 = %c, Dec2 = %c\n", a, b, dec1, dec2);
        }
    }
}

int main() {
    char cipherText[] = "YOUR CIPHERTEXT HERE"; 
    char mostFrequent = 'B';  
    char secondMostFrequent = 'U';
    breakAffineCipher(cipherText, mostFrequent, secondMostFrequent);
    
    return 0;
}
