#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float kilometers_to_miles(float kilometers);
float miles_to_kilometers(float miles);
float calculate_power(float voltage, float current);

int main(void)
{
    int choice;
    float celsius, fahrenheit;
    float kilometers, miles;
    float voltage, current;

    do
    {
        printf("\n===== Unit Converter =====\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Kilometers to Miles\n");
        printf("4. Miles to Kilometers\n");
        printf("5. Voltage and Current to Power\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);

            printf("Temperature in Fahrenheit: %.2f F\n", celsius_to_fahrenheit(celsius));
        }
        else if (choice == 2)
        {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);

            printf("Temperature in Celsius: %.2f C\n", fahrenheit_to_celsius(fahrenheit));
        }
        else if (choice == 3)
        {
            printf("Enter distance in Kilometers: ");
            scanf("%f", &kilometers);

            printf("Distance in Miles: %.2f miles\n", kilometers_to_miles(kilometers));
        }
        else if (choice == 4)
        {
            printf("Enter distance in Miles: ");
            scanf("%f", &miles);

            printf("Distance in Kilometers: %.2f km\n", miles_to_kilometers(miles));
        }
        else if (choice == 5)
        {
            printf("Enter voltage of the circuit: ");
            scanf("%f", &voltage);

            printf("Enter current of the circuit: ");
            scanf("%f", &current);

            printf("Power: %.2f Watts\n", calculate_power(voltage, current));
        }
        else if (choice == 6)
        {
            printf("Exiting program...\n");
        }
        else
        {
            printf("Invalid choice. Please select from 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}

float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

float kilometers_to_miles(float kilometers)
{
    return kilometers * 0.621371;
}

float miles_to_kilometers(float miles)
{
    return miles * 1.60934;
}

float calculate_power(float voltage, float current)
{
    return voltage * current;
}
