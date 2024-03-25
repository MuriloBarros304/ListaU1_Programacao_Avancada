#include <stdio.h>
int main(){
    int a, b;
    int x, y, z;
    scanf("%d %d", &a, &b); //a = 00001010; b = 00000001
    x = a; y = b; z = a + b;
    while (a) {
        x = x | b;
        y = y ^ a; 
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
a = 00001010 
b = 00000001

loop 1:
OR bit-a-bit => x = x OR b = 00001010 OR 00000001 = 00001011 = 11
XOR bit-a-bit => y = y XOR a = 00000001 XOR 00001010 = 00001011 = 11
AND bit-a-bit => z = z AND (a+b) = z AND 11 = 00001011 AND 00001011 = 00001011 = 11
Deslocar a para a direita em 1 bit => a =  00000101 = 5
Deslocar b para a esquerda em 1 bit => b = 00000010 = 2

loop 2:
x = 00001011 OR 00000010 = 00001011 = 11
y = 00001011 XOR 00000101 = 00001110 = 14
z = 11 AND 7 = 00001011 AND 00000111 = 00000011 = 3
a = 00000010 = 2
b = 00000100 = 4

loop 3:
x = 00001011 OR 00000100 = 00001111 = 15
y = 00001110 XOR 00000010 = 00001100 = 12
z = 00000011 AND 00000110 = 00000010 = 2
a = 00000001 = 1
b = 00001000 = 8

loop 4:
x = 00001111 OR 00001000 = 00001111 = 15
y = 00001100 XOR 00000001 = 00001101 = 13
z = 00000010 AND 00001001 = 00000000 = 0
a = 00000000 = 0
b = 00010000 = 16

a=0, portanto o while termina
Resultado: x = 15; y = 13; z = 0.
Alternativa 
*/