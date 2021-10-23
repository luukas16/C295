
long decode2(long x /*rdi*/, long y /*rsi*/, long z /*rdx*/){
   y-=z;//subq effect x-=y (subq rdx, rsi)
   x*=y;//imulq effect x*=y (imulq rsi,rdi)
   long temp = y;//movq effect rsi->rax (movq rsi, rax)
   //salq, sarq, xorq and ret in one line
   return (temp <<63 >> 63)^(x);
}



