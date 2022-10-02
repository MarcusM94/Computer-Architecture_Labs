#include <stdio.h>;
#include <stdlib.h>;

#define BITS sizeof(int) * 8

void list_commands(){
    printf("Check if LSB is set:\t\t\t1\n");
    printf("Check if MSB is set:\t\t\t2\n");
    printf("Get bit at a given index:\t\t3\n");
    printf("Set bit at a given index:\t\t4\n");
    printf("Clear bit at a given index:\t\t5\n");
    printf("Flip bit at a given index:\t\t6\n");
    printf("Multiply number by 16:\t\t\t7\n");
    printf("Check if number is odd or even:\t\t8\n");
    printf("Divide the number by 128:\t\t9\n");
    printf("Check amount of trailing zeroes:\t10\n");
    printf("Check amount of leading zeroes:\t\t11\n");
    printf("Exit:\t\t\t\t\t0\n");
}

int main(void){

    int userInput;
    int n = 12;

    do
    {   bit_representation(n);
        list_commands();
        printf("Enter a command: ");
        scanf("%i", &userInput);
        printf("%i", userInput);
        printf("\n");
        system("cls");
        switch (userInput)
        {
        case 1:
            is_lsb_set(n);
            break;
        case 2:
            is_msb_set(n);
            break;
        case 3:
            get_bit(n);
            break;
        case 4:
            n = set_bit(n);
            break;
        case 5:
            n = clear_bit(n);
            break;
        case 6:
            n = flip_bit(n);
            break;
        case 7:
            n = multiply_by_16(n);
            break;
        case 8:
            is_number_odd(n);
            break;
        case 9:
            n = divide_by_128(n);
            break;
        case 10:
            trailing_zeroes(n);
            break;
        case 11:
            leading_zeroes(n);
            break;
        case 0:
            printf("Shutting down...\n");
            break;        
        default:
            printf("Wrong input, please try again\n");
            break;
        }

    } while (userInput != 0);
}


int leading_zeroes(n){
    int count = 0;
    int bit_mask = n;
    int oneReverse = 1 << (BITS - 1);
    for(int i = 0; i < BITS; i++){
        if(bit_mask & oneReverse){
            break;
        } else {
            bit_mask = bit_mask << 1;
            count++;
        }
    }
    printf("Total leading zeroes: %i\n", count);
}

int trailing_zeroes(n){
    int count = 0;
    int bit_mask = n;
    for(int i = 0; i < BITS; i++){
        if(bit_mask & 1){
            break;
        } else {
            bit_mask = bit_mask >> 1;
            count++;
        }
    }
    printf("Total trailing zeroes: %i\n", count);
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

int get_bit(n){
    int index;
    printf("Get bit at what index:\n");
    scanf("%i", &index);
    //Move the bit at the given position to the position of LSB and compare it to the binary number of the int 1
    int n_bit = ((n >> index) & 1);
    printf("\nThe bit at index %i is %i\n", index, n_bit);

}

int multiply_by_16(n){
    //TODO: Fix when overflow happends with number greater than 32bits
    return n << 4;
}

int set_bit(n){
    int index;
    printf("Set bit at what index:\n");
    scanf("%i", &index);
    printf("\nThe %i-th bit has been set: \n", index+1);
    //Create an bit sequence with the only bit set is that of the index given
    return (n | ( 1 << index));
}

int clear_bit(n){
    int index;
    printf("Clear bit at what index:\n");
    scanf("%i", &index);
    printf("\nThe %i-th bit has been cleared: \n", index+1);
    //Create a bit sequence just like set_bit but inverse where the only unset bit is that of the index
    //Then do a & operation to clear that bit
    return (n & ~(1 << index));
}

int flip_bit(n){
    int index;
    printf("Flip bit at what index:\n");
    scanf("%i", &index);
    printf("\nThe %ith bit has been flipped: \n", index);
    return n ^ (1 << index);
}

int is_number_odd(n){
    //Any way to avoid if statement??
    if((n & 1) == 0)
        printf("%i is even\n", n);
    else
        printf("%i is odd\n", n);
}

int divide_by_128(n){
    //First create a bit sequence with only zeros
    //then inverse that to a sequence with only 1 (-1)
    //then shit left 7 spaces to get 0 on the first 7 bits
    //then inverse again to get 1's in the first 7 bits
    //then finally do a AND operation to find out what's left from the division, ie, the bits that are still set out of those seven bits
    printf("The remainder of %i / 128 is: %i\n", n, (n & ~((~(int)0) << 7)));
    //return n / 128;
    return n >> 7;
    
}

int bit_representation(n){
    printf("Current number: %i\nIn bits: ", n);
    for(int i = (BITS - 1); i >= 0; i--){
        printf("%i", ((n >> i) & 1));
        if(i%4 == 0)
            printf(" ");
    }
    printf("\n");
}