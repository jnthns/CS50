#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    float cash = get_float("Change Owed: ");
    
    while (cash < 0) {
        cash = get_float("Change Owed: ");
    }
    
    int quarters;
    int dimes;
    int nickels;
    int pennies = (int) (cash * 100);
    
    quarters = (int) (pennies / 25);
    pennies %= 25;
    
    dimes = (int) (pennies / 10);
    pennies %= 10;
    
    nickels = (int) (pennies / 5);
    pennies %= 5;
    
    printf("Quarters: %i\nDimes: %i\nNickels: %i\nPennies: %i\n", quarters, dimes, nickels, pennies);
    
}
