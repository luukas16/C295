# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "main.c"
long decode2(long x , long y , long z ){
   y-=z;
   x*=y;
   long temp = y;

   return (temp <<63 >> 63)^(x);
}
