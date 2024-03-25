#include <stdio.h>
int main(){
    int a, b;
    int x, y, z;
    scanf("%d %d", &a, &b); //a = 00001010; b = 00000001
    x = a; y = b; z = a + b;
    while (a) {
        x = x | b; // 
        y = y ^ a; // X
        z = z & (a+b);
        a = a >> 1;
        b = b << 1;
    }
    printf ("%d %d %d\n", x, y, z);
    return 0;
}
// 15 13 0
/* o while só irá parar quando a = 0.
inicialmente temos: 
a = 00001010 (int -> 4 bytes / 32 bits)
b = 00000001

loop 1:
OR bit-a-bit => x = a OR b = 00001011 = 11
XOR bit-a-bit => y = b XOR a = 00001011 = 11
AND bit-a-bit => z = z AND (a+b) = z AND 11 = 00001011 = 11
Deslocar a para a direita em 1 bit => a =  00000101 = 5
Deslocar b para a esquerda em 1 bit => b = 00000010 = 2

loop 2:
x = 00000111 = 7
y = 00000111 = 7
z = 11 AND 7 = 1011 AND 0111 = 0011 = 3
a = 00000010 = 3
b = 00000001 = 1

loop 3:

*/