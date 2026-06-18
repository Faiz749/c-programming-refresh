#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Device {
    char name[50];
    int pin;
    float value;
    int status;
};

int get_choice(void);
void add_device(struct Device d[], int count);
void display_readings(struct Device d[], int count);
void update_value(struct Device d[], int count);
void search_device(struct Device d[], int count);
void active_inactive_command(struct Device d[],int count);


int main(void)
{
    int choice;
    int count = 0;

    struct Device device[100];

    do {
        choice = get_choice();

        if (choice == 1) {
            add_device(device,count);
            count++;
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("Please enter device first\n");
            }
            else {
                display_readings(device, count);
            }
        }
        else if (choice == 3) {
            if (count == 0) {
                printf("Please enter device first\n");
            }
            else {
                update_value(device,count);
            }
        }
        else if (choice == 4) {
            if (count == 0) {
                printf("Please enter device first\n");
            }
            else {
                search_device(device,count);
            }
        }
        else if (choice == 5) {
            if (count == 0) {
                printf("Please enter device first\n");
            }
            else {
                active_inactive_command(device, count);
            }
        }
        else if (choice == 6) {
            printf("Exiting.....\n");
        }

    } while (choice != 6);

    return 0;
}

int get_choice(void)
{
    int choice;

    while (true) {
        printf("\n===== Device Record System =====\n");
        printf("1. Add device\n");
        printf("2. Display all devices\n");
        printf("3. Update device value\n");
        printf("4. Search device by name\n");
        printf("5. Show active/inactive device count\n");
        printf("6. Exit\n");
        printf("Please enter your choice: ");

        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            break;
        }
        else {
            printf("Invalid choice. Please try again\n");
        }
    }

    return choice;
}

void add_device(struct Device d[], int count)
{
    printf("Enter Device name: ");
    scanf("%49s", d[count].name);

    printf("Please enter pin number: ");
    scanf("%d", &d[count].pin);

    printf("Please enter value: ");
    scanf("%f", &d[count].value);

    while (true) {
        printf("Enter status 1 for active, 0 for inactive: ");
        scanf("%d", &d[count].status);

        if (d[count].status == 0 || d[count].status == 1) {
            break;
        }
        else {
            printf("Invalid command. Please enter 0 or 1\n");
        }
    }

    printf("Device added successfully\n");
}

void display_readings(struct Device d[], int count)
{
    printf("\n===== Device Info =====\n");

    for (int i = 0; i < count; i++) {
        printf("\nDevice %d readings\n", i + 1);
        printf("Name: %s\n", d[i].name);
        printf("PIN Number: %d\n", d[i].pin);
        printf("Value: %.2f\n", d[i].value);

        if (d[i].status == 1) {
            printf("Status: Active\n");
        }
        else {
            printf("Status: Inactive\n");
        }
    }
}

void update_value(struct Device d[], int count){
    char name[50];
    bool device_found = false;
    while(true){
       printf("Enter device name: ");
       scanf("%49s",name);
       for(int i=0;i<count;i++){
         if(strcmp(name, d[i].name)==0){
            printf("Enter the new value: ");
            scanf("%f",&d[i].value);
            printf("Value changed successfully\n");
            device_found = true;
         }
    }
    if(device_found){
        break;
    }
    else{
        printf("Invalid device name\n");
    }
    
  } 
}

void search_device(struct Device d[], int count){
    char name[50];
    bool device_found = false;
    while(true){
      printf("Enter device name: ");
      scanf("%49s",name);
      for(int i=0;i<count;i++){
         if(strcmp(name, d[i].name) == 0){
              printf("Device %d readings\n", i + 1);
              printf("Name: %s\n", d[i].name);
              printf("PIN Number: %d\n", d[i].pin);
              printf("Value: %.2f\n", d[i].value);

            if (d[i].status == 1) {
             printf("Status: Active\n");
            }
            else {
            printf("Status: Inactive\n");
            }
            device_found = true;
        }
    }
    if(device_found){
        break;
    }
    else{
        printf("Invalid device name\n");
    }
  }
}

void active_inactive_command(struct Device d[],int count){
    int active_count = 0;
    int inactive_count =0;
    for(int i=0;i<count;i++){
        if(d[i].status == 1){
            active_count ++;
        }
        else{
            inactive_count ++;
        }
    }
    printf("Active devices: %d\n",active_count);
    printf("Inactive devices: %d\n",inactive_count);
}