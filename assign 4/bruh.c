#include <stdio.h>
void foo( int n, int A, int B, int C ) {
 if( n==1 ) {
 printf("%d to %d\n",A,B);
 return;
 }
 foo( n-1, A, C, B );
 printf("%d to %d\n",A,B);
 foo( n-1, B, C, A );
}
int main(){
    foo(4,4,5,6);
}