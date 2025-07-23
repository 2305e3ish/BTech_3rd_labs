/*
 * CRC-12 Implementation
 * Polynomial: x^12 + x^11 + x^3 + x^2 + x + 1
 * Binary: 1100000001011
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* bindiv(const char*, const char*);
const char* binsub(const char*, const char*);

int f = 0, ll = 0;

int main() {
    char *a, p[13] = "1100000001011", g[30], g1[30], yy[30] = "", td[30], *aa;
    int l = 0, i;
    
    printf("=== CRC-12 Implementation ===\n");
    printf("Polynomial: x^12 + x^11 + x^3 + x^2 + x + 1\n");
    printf("Binary representation: %s\n\n", p);
    
    printf("Enter transferred data (binary): ");
    scanf("%s", g);
    
    printf("Enter received data (binary): ");
    scanf("%s", td);
    
    strcpy(g1, g);
    strcat(g, "000000000000"); // Append 12 zeros
    
    printf("\nSender Side - Computing CRC:\n");
    printf("%s ) %s (\n", p, g);
    
    a = bindiv(g, p);
    
    // Pad CRC to 12 bits
    if(strlen(a) < 12) {
        for(i = strlen(a); i < 12; i++) {
            yy[l++] = '0';
        }
        yy[l] = '\0';
    }
    
    strcat(yy, a);
    strcat(g1, yy);
    
    printf("CRC-12 checksum: %s\n", yy);
    printf("Transmitted data: %s\n", g1);
    printf("                ------------------\n");
    
    // Receiver side verification
    printf("\nReceiver Side - Verifying Data:\n");
    strcat(td, yy);
    printf("%s ) %s (\n", p, td);
    
    ll = 0;
    f = 0;
    aa = bindiv(td, p);
    strcpy(a, aa);
    
    printf("Remainder: %s\n", a);
    printf("                -----------------\n");
    
    if(f == 1) {
        printf("✓ Data transferred correctly\n");
    } else {
        printf("✗ Data transferred incorrectly\n");
    }
    
    return 0;
}

const char* bindiv(const char* s, const char* d) {
    int i, j, k = 0, x = 13, h, p = 0, l;
    static char q[15] = "", b[30], *w;
    
    for(i = 0; i < strlen(s); i++) {
        if((i + x) > strlen(s)) {
            x = (i + x) - strlen(s) + 1;
        }
        
        for(j = i; j < (i + x); j++) {
            b[k++] = s[j];
        }
        
        b[k] = '\0';
        
        if(ll != 0) {
            printf("                %s\n", b);
        }
        ll = 1;
        
        if(strlen(b) == 12) {
            break;
        }
        
        printf("                %s\n", d);
        printf("                -----------------\n");
        
        w = binsub(b, d);
        k = 0;
        i = j - 1;
        
        for(l = 0; l < strlen(w); l++) {
            if(w[l] == '1') {
                break;
            }
        }
        
        if(l == strlen(w)) {
            f = 1;
            return w;
        }
        
        for(h = l; h < strlen(w); h++) {
            q[p++] = w[h];
        }
        
        q[p] = '\0';
        x = 13 - strlen(q);
        strcpy(b, "");
        strcat(b, q);
        k = strlen(q);
        p = 0;
    }
    
    return b;
}

const char* binsub(const char* x, const char* y) {
    int i, j = 0;
    static char w[15] = "", e[3], f[3], n[3];
    
    e[0] = '1';
    e[1] = '\0';
    f[0] = '0';
    f[1] = '\0';
    
    for(i = 0; i < strlen(x); i++) {
        if((x[i] == '1') && (y[i] == '1')) {
            strcat(w, f);
        } else if((x[i] == '0') && (y[i] == '0')) {
            strcat(w, f);
        } else {
            strcat(w, e);
        }
    }
    
    n[0] = '\0';
    n[1] = '\0';
    strcat(w, n);
    
    return w;
}
