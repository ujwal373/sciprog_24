#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int interactiveGCD(int a, int b)
{
    
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int recursiveGCD(int a, int b)
{
    if (b == 0){
        return a;
    }
    else{
        return recursiveGCD(b, a % b);
    }
}

int main()
{
    int a, b, error;
    //generate random numbers between 1 and 100
    srand(time(NULL));
    a = rand() % 100 + 1;
    b = rand() % 100 + 1;

    printf("GCD of %d and %d is %d\n", a, b, interactiveGCD(a, b));
    printf("GCD of %d and %d is %d\n", a, b, recursiveGCD(a, b));
    return 0;
}
