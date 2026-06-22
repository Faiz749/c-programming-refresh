#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Sensor {
    char name[50];
    float value;
    int valid;
};

struct Device {
    char name[50];
    int state;
};

int get_choice(void);
void get_sensor_readings(struct Sensor d1[]);
void show_readings(struct Sensor d1[]);
void analyze_room_condition(struct Sensor d1[]);
void show_device_status(struct Device d[]);
void automatic_control(struct Sensor d1[],struct Device d[]);
void reset_devices(struct Device d[]);
void write_system_log(struct Sensor d[], struct Device d1[]);

int main(void)
{
    struct Sensor d[4] = {{"TEMP", 0, 0},{"LIGHT", 0, 0},{"MOTION", 0, 0},{"GAS", 0, 0}};
    struct Device d1[4] = { {"FAN", 0}, {"ROOM_LIGHT", 0},{"BUZZER", 0},{"ALARM", 0} };
    int choice;

    do {
        choice = get_choice();

        if (choice == 1) {
            get_sensor_readings(d);
        }
        else if (choice == 2) {
            show_readings(d);
        }
        else if (choice == 3) {
            analyze_room_condition(d);
        }
        else if (choice == 4) {
            show_device_status(d1);
        }
        else if (choice == 5){
            automatic_control(d,d1);
        }
        else if(choice ==6){
            write_system_log(d,d1);
        }
        else if(choice ==7){
            reset_devices(d1);
        }
        else{
            printf("Exiting\n");
        }

    } while (choice != 8);

    printf("Program ended.\n");

    return 0;
}

int get_choice(void){
    int choice;

    while (true) {
        printf("\n===== Smart Room Controller =====\n");
        printf("1. Load sensor readings from file\n");
        printf("2. Show sensor readings\n");
        printf("3. Analyze room conditions\n");
        printf("4. Show device status\n");
        printf("5. Run automatic control\n");
        printf("6. Write system log\n");
        printf("7. Reset devices\n");
        printf("8. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if (choice >= 1 && choice <= 8) {
            break;
        }
        else {
            printf("Invalid Choice. Please try again\n");
        }
    }

    return choice;
}

void get_sensor_readings(struct Sensor d1[])
{
    FILE *file;
    float value;
    char token[50];

    file = fopen("room_readings.txt", "r");

    if (file == NULL) {
        printf("Could not access file\n");
        return;
    }

    while (fscanf(file, "%49s %f", token, &value) == 2) {

        if (strcmp(token, "TEMP") == 0) {
            d1[0].value = value;
            d1[0].valid = 1;
        }
        else if (strcmp(token, "LIGHT") == 0) {
            d1[1].value = value;
            d1[1].valid = 1;
        }
        else if (strcmp(token, "MOTION") == 0) {
            d1[2].value = value;
            d1[2].valid = 1;
        }
        else if (strcmp(token, "GAS") == 0) {
            d1[3].value = value;
            d1[3].valid = 1;
        }
    }

    fclose(file);

    printf("Sensor readings loaded successfully.\n");
}

void show_readings(struct Sensor d1[])
{
    printf("\n===== Sensor Readings =====\n");

    for (int i = 0; i < 4; i++) {
        if (d1[i].valid == 0) {
            printf("%s : Invalid readings\n", d1[i].name);
        }
        else {
            printf("%s : %.2f\n", d1[i].name, d1[i].value);
        }
    }
}

void analyze_room_condition(struct Sensor d1[]){
    printf("\n===== Room Condition Analysis =====\n");

    for (int i = 0; i < 4; i++) {

        if (d1[i].valid == 0) {
            printf("%s reading is invalid or not loaded.\n", d1[i].name);
            continue;
        }

        if (strcmp(d1[i].name, "TEMP") == 0) {
            if (d1[i].value > 35) {
                printf("Room is hot\n");
            }
            else {
                printf("Temperature is normal\n");
            }
        }
        else if (strcmp(d1[i].name, "LIGHT") == 0) {
            if (d1[i].value < 30) {
                printf("Room is dark\n");
            }
            else {
                printf("Room has enough light\n");
            }
        }
        else if (strcmp(d1[i].name, "MOTION") == 0) {
            if (d1[i].value == 1) {
                printf("Motion detected\n");
            }
            else {
                printf("No Motion detected\n");
            }
        }
        else if (strcmp(d1[i].name, "GAS") == 0) {
            if (d1[i].value > 50) {
                printf("Gas warning detected\n");
            }
            else {
                printf("Gas level is normal\n");
            }
        }
    }
}

void show_device_status(struct Device d[])
{
    printf("\n===== Device Status =====\n");

    for (int i = 0; i < 4; i++) {
        if (d[i].state == 0) {
            printf("%s: OFF\n", d[i].name);
        }
        else if (d[i].state == 1) {
            printf("%s: ON\n", d[i].name);
        }
    }
}

void automatic_control(struct Sensor d1[], struct Device d[]){
    if (d1[0].value > 35) {
        printf("Turning FAN on\n");
        d[0].state = 1;
    }
    else {
        printf("Turning FAN off\n");
        d[0].state = 0;
    }

    if (d1[1].value < 30) {
        printf("Turning ROOM_LIGHT on\n");
        d[1].state = 1;
    }
    else {
        printf("Turning ROOM_LIGHT off\n");
        d[1].state = 0;
    }

    if (d1[2].value == 1) {
        printf("Turning BUZZER on\n");
        d[2].state = 1;
    }
    else {
        printf("Turning BUZZER off\n");
        d[2].state = 0;
    }

    if (d1[3].value > 50) {
        printf("Turning ALARM on\n");
        d[3].state = 1;
    }
    else {
        printf("Turning ALARM off\n");
        d[3].state = 0;
    }
}

void reset_devices(struct Device d[]){
    for(int i=0;i<4;i++){
        d[i].state = 0;
    }
    printf("All devices reseted\n");
}

void write_system_log(struct Sensor d[], struct Device d1[]){
    FILE *file;

    file = fopen("room_log.txt", "a");

    if (file == NULL) {
        printf("Could not write log file\n");
        return;
    }

    fprintf(file, "===== Smart Room System Log =====\n");

    fprintf(file, "\nSensor Readings:\n");

    for (int i = 0; i < 4; i++) {
        fprintf(file, "%s : %.2f\n", d[i].name,d[i].value);
        
    }
    fprintf(file, "\nDevice Status:\n");
    for (int i = 0; i < 4; i++) {
        if (d1[i].state == 0) {
            fprintf(file, "%s : OFF\n", d1[i].name);
        }
        else {
            fprintf(file, "%s : ON\n", d1[i].name);
        }
    }
    fclose(file);
    printf("System log written successfully.\n");
}