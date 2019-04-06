//
//  main.c
//  FirstCProgram
//
//  Created by Ariosto Kuit on 4/6/19.
//  Copyright © 2019 Ariosto Kuit. All rights reserved.
//   CHAPTER 1 of THE C PROGRAMMING LANGUAGE

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    /*THIS IS FOR EXERCISE 1-3 to 1-5*/
    
    float fahr, celsius;
    int lower,upper,step;
    
    lower = 0;  /*lower limit of temperature table*/
    upper = 300; /*upper limit*/
    step = 20;  /*step size*/

    fahr = lower;
    
    printf("%10s\t%10s\n","Fahrenheit","Celsius");
    printf("-------------------------\n");
    while(fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%5.0f\t%12.1f\n",fahr,celsius);    /*%d specifies an interger arguent*/
        fahr = fahr + step;                   /*The number after the slash represent the size of the width in the printed field*/
    }
    
    /*Now lets try converting the program to display Celsius to Fahrenheit*/
    printf("\n\nNow displaying the Celsius to Fahrenheit table\n\n");
    printf("%s\t%15s\n","Celsius","Fahrenheit");

    lower = -20;
    upper = 160;
    celsius = lower;

    while(celsius <= upper){
        fahr = (celsius*9.0)/5.0 + 32;
        printf("%5.0f\t%12.1f\n",celsius,fahr);
        celsius = celsius + step;
    }
    
    /*Let's try the same program but by using a for loop*/
    printf("\n\nNow using a for loop to display the temperature conversion from 300 to zero degrees\n");
    printf("%10s\t%10s\n","Fahrenheit","Celsius");
    
    for(fahr = 300;fahr >= 0; fahr = fahr - step){
        printf("%5.0f\t%12.1f\n",fahr,(5.0/9.0)*(fahr - 32));
    }
    
    return 0;
}
