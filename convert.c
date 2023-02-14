#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaring the Functions
int get_bin();
int get_dec();

//Using Argument Count & Argument Value
int main (int argc, char *argv[])
{
    //Adding Limitations Based on Argument Count
    while(argc != 2)
    {
        printf("USE: ./convert 1 (for dec to bin) or ./convert 2 (for bin to dec)\n");
        return 1;
    }
    //Using the Argument Value to Choose Type of Conversion
    char *k = argv[1];
    int key = atoi(k);

    //Calling the Functions in Main Based on the Value of the Argument
    if(key == 1)
    {
       int bin = get_bin();
    }

    else if(key == 2)
    {
       int dec = get_dec();
    }
    //Message if the Argv is not Valid
    else
    {
        printf("The key must be: 1 or 2\n");

        return 1;
    }
}

//Function to Convert from Decimal to Binary
int get_bin()
{
    int j = 0;
    int i = 0;
    char ip[50];
    const char del[] = ".";
    int deci[4];
    int bin[32];

    //Getting the IP in Decimal as a String
    printf("Give the IP in Decimal: ");
    fgets(ip, 50, stdin);

    //Splitting the Array with Delimeter
    //And
    //Converting it to Integers
    char *tok = strtok(ip, del);

        while(tok != 0)
    {
        deci[i++] = atoi(tok);

        tok = strtok(NULL, del);
    }

    //Filling the Array that we will Store the Binary with 0s
    for(int l = 0; l <= 31; l++)
    {
        bin[l] = 0;
    }
    //Gradually Decreasing the Size of the Index
    //To Convert All Parts of the Array
    i--;

    //Storing the Conversion in a New Array
    //Gradually Increasing its Index in Every Itteration of the Loop
        do
    {
        bin[j++] = deci[i]%2;
        deci[i] /= 2;
    }
    while(deci[i] > 0);

    i--;
    j = 8;

            do
    {
        bin[j++] = deci[i]%2;
        deci[i] /= 2;
    }
    while(deci[i] > 0);

    i--;
    j = 16;

            do
    {
        bin[j++] = deci[i]%2;
        deci[i] /= 2;
    }
    while(deci[i] > 0);

    i--;
    j = 24;

            do
    {
        bin[j++] = deci[i]%2;
        deci[i] /= 2;
    }
    while(deci[i] > 0);

    //Starting Printing from the Last Position of the Array
    //To Get Our IP Placement Right
    for(j = j - 1; j >= 0; j--)
    {
    // Printing The "." in the Correct position of the Array
        if(j == 7 || j == 15 || j == 23)
        {
            printf(".");
        }
        printf("%i", bin[j]);
    }
    printf("\n");

    return 0;
}

//Function to Convert from Binary to Decimal
int get_dec()
{
    int base = 1;
    int rem;
    int i = 0;
    int j = 0;
    char ip[50];
    const char del[] = ".";
    long bine[4];
    int deca[4];

    //Getting the IP in Binary
    printf("Give the IP in Binary: ");
    fgets(ip, 50, stdin);

    //Splitting the Array with Delimeter
    //And
    //Converting it to Integers
    char *tok = strtok(ip, del);

    while(tok != 0)
    {
    bine[i++] = atoi(tok);
    tok = strtok(NULL, del);
    }

    //Storing the Conversion of Each Part of the Array in a New Array
    //Gradually Increasing its Index in Every Itteration of the Loop
        for(i = 0; i < 4; i++)
    {
        do
    {
    rem = bine[i]%10;
    deca[j] = deca[j] + rem * base;
    bine[i] /= 10;
    base *= 2;
    }
        while(bine[i] > 0);

    base = 1;
    j++;
    }

    //Splitting the New Array with "." in the Correct Positions
        for(int k = 0; k < j; k++)
    {
        if(k == 1 || k == 2 || k == 3)
        {
            printf(".");
        }
        printf("%i", deca[k]);
    }
    printf("\n");

    return 0;
}