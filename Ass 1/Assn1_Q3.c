#include <stdio.h>
#include <stdlib.h>
/*
name: Luukas Suomi
date: sept, 24, 2021
ST#: 301443184
cmpt 295 Assn1 question 3
*/

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;

    for (i = 0; i < len; i++){
       printf("0x%p  0x%.2x\n",&start[i], start[i]); 
    } 	
    printf("\n");
}

// Put your answer to Question 3 b) here as a comment
/*
    our hexadecimal value for 12345 is 0x3039
    however it is printed in reverse order
    meaning this machine is little endian
    Output: 39 30 00 00
    actual hexadecimal representation(on paper)
    Ox30 39 00 00.
*/
void show_bytes_2(byte_pointer start, size_t len) {
    size_t i;

    for (i = 0; i < len; i++)
		printf("0x%p  0x%.2x\n",&start[i], *(start + i)); 	
    printf("\n");	
}

// Put your answer to Question 3 d) here
void show_bits(int f){
    //stores the value 32, the numbner of bits in an int
    const int NumOfBits = sizeof(int)*8;
    //array to store the bits
    int bit_vector[NumOfBits];

    //check the parameter for neg or pos.
    if(f < 0){
        //if negative do the following:
        //first set the value to its possitve version for the conversion code
        f = f*(-1);

        //set every value in the array to zero
        //this is essentially our default value until its needed to be a 1
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
        //itterator variable
        int w = 0;

        //now apply the addition of twos complement
        //while we are looking in the array and we havent found a zero
        while(w <NumOfBits && bit_vector[w] !=0){
            w++;
        }
        //once the first zero is found we make sure the point in the array is correct
        if(w != NumOfBits -1 || bit_vector[NumOfBits-1] == 0){
            //set the value to one once found
            bit_vector[w] = 1;
        }

    }else// if the value is possitive
     {
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
        //order of the bits so we need to traverse the array backwards
        for(int g = NumOfBits -1; g >=0;g--){
            printf("%d", bit_vector[g]);
          }
            printf("\n");
}

// Put your answer to Question 3 e) here
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
      //fill the bit vector with zeros.
      return n = (0<<NumOfBits-1);
  }
  //pushes a "1" n spaces to the left followed by n zeros,
  //subtracting one insures that the 1 is flipped to a zero and all its trailing zeros are flipped to 1.
  return n = (1<<n)-1;
}

void show_int(int x) {
	printf("\nival = %d\n", x); 
    show_bytes((byte_pointer) &x, sizeof(int)); 
	show_bytes_2((byte_pointer) &x, sizeof(int)); 
}

void show_float(float x) {
    printf("fval = %f\n", x); 	
    show_bytes((byte_pointer) &x, sizeof(float));
    show_bytes_2((byte_pointer) &x, sizeof(float)); 
}

void show_pointer(void *x) {
	printf("pval = %p\n", x); 
    show_bytes((byte_pointer) &x, sizeof(void *));
    show_bytes_2((byte_pointer) &x, sizeof(void *));
}