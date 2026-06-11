#include<stdio.h>
#include<stdbool.h>

float celsius_to_fahrenheit(float c);
float farenheit_to_celsius(float f);
float km_to_miles(float km);
float miles_to_km(float miles);
float calculate_power(float v,float i);

int main(void){
    int choice;
    float fahrenheit,celsius,kilometer,miles,voltage,current;
    do{
        printf("---unit converter----\n");
        printf("Press 1 to convert Celsius to Fahrenheit\n");
        printf("Press 2 to convert Fahrenheit to Celsius\n");
        printf("Press 3 to convert Kilometers to Miles\n");
        printf("Press 4 to convert Miles to Kilometers\n");
        printf("Press 5 to calculate Power\n");
        printf("Press 6 to Exit\n");

        while(true){
             printf("Please Enter your choice: ");
             scanf("%d",&choice );
             if(choice>=1 && choice<=6){
                break;
             }
             else {
                printf("Invalid Choice please try again");
             }
        }

        if(choice == 1){
            printf("Please eneter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            printf("Temperature in Celsius: %.2f\n",farenheit_to_celsius(fahrenheit));
        }

        else if(choice == 2){
            printf("Please eneter temperature in Celsius: ");
            scanf("%f", &celsius);
            printf("Temperature in Fahrenheit: %.2f\n",celsius_to_fahrenheit(celsius)); 
        }

        else if(choice == 3){
            printf("Enter distance in Kilometers: ");
            scanf("%f",&kilometer);
            printf("Distance in Meters: %.2f\n",km_to_miles(kilometer));
        }

        else if(choice == 4){
            printf("Enter distance in Miles");
            scanf("%f",&miles);
            printf("Distance in Kilometers: %.2f\n", miles_to_km(miles));
        }

        else if(choice ==5){
            printf("Enter Voltage of the circut");
            scanf("%f",&voltage);
        }

        else{
            printf("Exiting.......");
        }

        }while(choice!=6);
    
    return 0;

    }

float celsius_to_fahrenheit(float c){
    return (c * 9 / 5) + 32 ;
}

float farenheit_to_celsius(float f){
    return  (f - 32) * 5 / 9 ;
}

float km_to_miles(float km){
    return km * 0.621371;
}

float miles_to_km(float miles){
    return miles * 1.60934;
}

float calculate_power(float v,float i){
    return v*i;
}