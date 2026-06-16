#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void show_help(void);
void status(bool led_on, bool buzzer_on);

int main(void) {

    char command[50];
    bool led_on = false;
    bool buzzer_on = false;

    while (true) {

        printf("\n===== Command Parser =====\n");
        printf("Type HELP to see available commands.\n");
        printf("Enter Command: ");

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "LED ON") == 0) {
            printf("LED turned ON\n");
            led_on = true;
        }
        else if (strcmp(command, "LED OFF") == 0) {
            printf("LED turned OFF\n");
            led_on = false;
        }
        else if (strcmp(command, "BUZZER ON") == 0) {
            printf("Buzzer turned ON\n");
            buzzer_on = true;
        }
        else if (strcmp(command, "BUZZER OFF") == 0) {
            printf("Buzzer turned OFF\n");
            buzzer_on = false;
        }
        else if (strcmp(command, "STATUS") == 0) {
            status(led_on, buzzer_on);
        }
        else if (strcmp(command, "HELP") == 0) {
            show_help();
        }
        else if (strcmp(command, "EXIT") == 0) {
            printf("Exiting.......\n");
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}

void show_help(void) {
    printf("\nAvailable commands:\n");
    printf("LED ON\n");
    printf("LED OFF\n");
    printf("BUZZER ON\n");
    printf("BUZZER OFF\n");
    printf("STATUS\n");
    printf("HELP\n");
    printf("EXIT\n");
}

void status(bool led_on, bool buzzer_on) {
    if (led_on) {
        printf("LED: ON\n");
    }
    else {
        printf("LED: OFF\n");
    }

    if (buzzer_on) {
        printf("BUZZER: ON\n");
    }
    else {
        printf("BUZZER: OFF\n");
    }
}