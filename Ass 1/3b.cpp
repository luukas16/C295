#include <stdio.h>
#include <math.h>
void show_bits(int f){
    //represent the 
    const int NumOfBits = sizeof(int)*8;
    //array to store the bits
        int bit_vector[NumOfBits];
    if(f < 0){
        f = f*(-1);
        //set every value in the array to zero
        for(int b =0; b < 32; b++){
            bit_vector[b] = 0;
        }
        
        int i =0;
        //perform the division method for U2B
        while( f >0){
        //remainder when divided by 2
        bit_vector[i] = f %2;
        //move along in the division
        f = f/2;
        i++;
        }
        //now time for twos complement
        //first we make it ones complement
        for(int l =0; l < NumOfBits ;l++){
            if(bit_vector[l] == 0){
                bit_vector[l] = 1;
            }else{
                bit_vector[l] = 0;
            }
        }
        int w = 0;
        while(w <NumOfBits && bit_vector[w] !=0){
            w++;
        }
        if(w != NumOfBits -1 || bit_vector[NumOfBits-1] == 0){
            bit_vector[w] = 1;
        }

    }else{
    //set every value in the array to zero
    for(int b =0; b < 32; b++){
        bit_vector[b] = 0;
    }
    int i =0;
    //perform the division method for U2B
    while( f >0){
      //remainder when divided by 2
      bit_vector[i] = f %2;
      //move along in the division
      f = f/2;
      i++;
    }
    }
            //the division method gives us the reverse 
        //order of the bits so we need to travers the array backwards
        for(int g = NumOfBits -1; g >=0;g--){
            printf("%d", bit_vector[g]);
        }
            printf("\n");
}
int  mask_LSbits(int n){
    const int NumOfBits = sizeof(int)*8;
 //help recieved on the code below
 //sources:
 //date accesed September, 22, 2021
 //https://www.programiz.com/swift-programming/bitwise-operators
 //see examples 4 and 5
 //and
 //https://www.cs.uaf.edu/courses/cs301/2014-fall/notes/bits-bitwise/
 //see the section labeled Interesting facts about left shift:
 //to find this:
 //1<<n pushes a 1 up into bit number n, creating the bit pattern 1 followed by n zeros.
  if( n >=NumOfBits){
      //this shifts to the left by 31 bits and turns the trailing zeros to 1's via subtraction
      //the problem is the MSB is left as a zero
      //to fix that we simply shift the bits over and add back the LSB
      return n = ((((1<<(NumOfBits-1))-1)<<1)+1);
  }else if(n <=0){
      return n = (0<<NumOfBits-1);
  }return n = (1<<n)-1;
}

int main(){
    int val = 5;
    float fval = (float) 2;
    int *pval = &val;

    show_bits(val);
    mask_LSbits(val);
    show_bits(mask_LSbits(val));


    return 0;
}