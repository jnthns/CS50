#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    float cash = get_float("Change Owed: ");
    
    while (cash < 0) {
        cash = get_float("Change Owed: ");
    }
    
    int pennies = (int) round((cash * 100));
    
    int quarters = (int) (pennies / 25);
    pennies %= 25;
    
    int dimes = (int) (pennies / 10);
    pennies %= 10;
    
    int nickels = (int) (pennies / 5);
    pennies %= 5;
    
    int coins = quarters + dimes + nickels + pennies;
    
    printf("%i\n",coins);
    
}
