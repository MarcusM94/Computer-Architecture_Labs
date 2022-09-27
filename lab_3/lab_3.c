#include <stdio.h>;
#include <stdlib.h>;

#define BITS sizeof(int) * 8

int main(void){  
    int n = 12;
    is_lsb_set(n);
    is_msb_set(n);
    get_bit(n, 2);
    bit_representation(n);
    multiply_by_16(n);
    set_bit(n, 1);
    clear_bit(n, 3);

}

int is_lsb_set(n){
    if((n & 1) == 0)
        printf("The LSB is not set\n");
    else
        printf("The LSB is set\n");
}

int is_msb_set(n){
    //Create a new bit number where only the MSB is set to 1 and rest set to 0
    int bit_mask = 1 << (BITS - 1);
    //Check if the MSB in both numbers is set
    if (n & bit_mask)
        printf("The MSB is set\n");
    else
        printf("The MSB is not set\n");
    
}

int get_bit(n, index){
    //Move the bit at the given position to the position of LSB and compare it to the binary number of the int 1
    int n_bit = ((n >> index) & 1);
    printf("The bit at index %i is %i\n", index, n_bit);

}

int multiply_by_16(n){
    //TODO: Fix when overflow happends with number greater than 32bits
    printf("%i * 16 = %i\n", n, n << 4);
}

int set_bit(n, index){
    printf("The %i-th bit has been set: \n", index+1);
    //Create an bit sequence with the only bit set is that of the index given
    bit_representation((n | ( 1 << index)));
}

int clear_bit(n, index){
    printf("The %i-th bit has been cleared: \n", index+1);
    //Create a bit sequence just like set_bit but inverse where the only unset bit is that of the index
    //Then do a & operation to clear that bit
    bit_representation((n & ~(1 << index)));
}

int bit_representation(n){
    printf("The number %i in bits is: ", n);
    for(int i = (BITS - 1); i >= 0; i--){
        printf("%i", ((n >> i) & 1));
        if(i%4 == 0)
            printf(" ");
    }
    printf("\n");
}