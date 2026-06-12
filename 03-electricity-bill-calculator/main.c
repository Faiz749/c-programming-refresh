#include <stdbool.h>
#include <stdio.h>

void show_slab(void);
int get_rate(float u);
float base_bill(int r, float u);
float final_bill(float baseAmount);
float tax(float baseAmount);

int main(void) {
    int choice, rate;
    float units, baseAmount, finalAmount;

    do {
        printf("===== Electricity Bill Calculator =====\n");
        printf("1. Calculate bill\n");
        printf("2. Show slab info\n");
        printf("3. Exit\n");

        while (true) {
            printf("Please enter your choice: ");
            scanf("%d", &choice);

            if (choice >= 1 && choice <= 3) {
                break;
            } else {
                printf("Invalid choice. Try again\n");
            }
        }

        if (choice == 1) {
            while (true) {
                printf("Enter consumed units: ");
                scanf("%f", &units);

                if (units >= 0) {
                    break;
                } else {
                    printf("Units cannot be negative. Please try again.\n");
                }
            }

            rate = get_rate(units);
            baseAmount = base_bill(rate, units);
            finalAmount = final_bill(baseAmount);

            printf("----------Bill details----------\n");
            printf("Units = %.2f\n", units);
            printf("Rate = %d\n", rate);
            printf("Base Bill = %.2f\n", baseAmount);
            printf("Service charges = 100\n");
            printf("Tax = %.2f\n", tax(baseAmount));
            printf("Final Bill = %.2f\n", finalAmount);
        }
        else if (choice == 2) {
            show_slab();
        }
        else {
            printf("Exiting........\n");
        }

    } while (choice != 3);

    return 0;
}

int get_rate(float u) {
    if (u <= 100) {
        return 10;
    }
    else if (u <= 200) {
        return 15;
    }
    else if (u <= 300) {
        return 20;
    }
    else {
        return 30;
    }
}

float base_bill(int r, float u) {
    return r * u;
}

float tax(float baseAmount) {
    baseAmount = baseAmount + 100;
    return (baseAmount / 100) * 10;
}

float final_bill(float baseAmount) {
    float service_charge = 100;
    float taxAmount;

    baseAmount = baseAmount + service_charge;
    taxAmount = (baseAmount / 100) * 10;

    return baseAmount + taxAmount;
}

void show_slab(void) {
    printf("0 - 100 units = 10 per unit\n");
    printf("101 - 200 units = 15 per unit\n");
    printf("201 - 300 units = 20 per unit\n");
    printf("Above 300 units = 30 per unit\n");
}
