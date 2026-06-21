#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int get_choice(void);
void write_log(char message[]);
void append_log(char message[]);
void system_startup(void);
void sensor_reading(void);
void warning_log(void);
void device_action(void);
void clear_logs(void);

int main(void){
    int choice;
    do{
        choice = get_choice();
        if(choice ==1){
            system_startup();
        }
        else if(choice ==2){
            sensor_reading();
        }
        else if(choice ==3){
            warning_log();
        }
        else if(choice ==4){
            device_action();
        }
        else if(choice ==5){
            clear_logs();
        }
        else{
            printf("Exitting.....\n");
        }

    }while(choice !=6);
    return 0;
}

int get_choice(void){
    int choice;

    while(true){
        printf("===== System Log Writer =====\n");
        printf("1. Write system startup log\n");
        printf("2. Write sensor reading log\n");
        printf("3. Write warning log\n");
        printf("4. Write device action log\n");
        printf("5. Clear log file\n");
        printf("6. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        if(choice>=1 && choice<=6){
            break;
        }
        else{
            printf("Invalid choice. Please Enter a number between 1 and 6\n");
        }
    }
    return choice;
}

void write_log(char message[]){
    FILE *file;
    file = fopen("system_log.txt","w");
    if(file == NULL){
        printf("FILE cannot be opened\n");
        return;
    }
    fprintf(file,"%s\n",message);
    fclose(file);
}

void append_log(char message[]){
    FILE *file;
    file = fopen("system_log.txt","a");
    if(file == NULL){
        printf("FILE cannot be opened\n");
        return;
    }
    fprintf(file,"%s\n",message);
    fclose(file);
}

void system_startup(void){
    write_log("System started successfully.");
    printf("System started\n");
}

void sensor_reading(void){
    FILE *file;
    char name[50];
    float value;
    printf("Enter sensor name: ");
    scanf("%49s",name);
    printf("Enter sensor value: ");
    scanf("%f",&value);
    file = fopen("system_log.txt", "a");
    if(file == NULL){
        printf("FILE cannot be opened\n");
        return;
    }
    fprintf(file,"Sensor %s reading: %.2f\n",name,value);
    fclose(file);
    printf("Sensor reading noted\n");
}

void warning_log(void){
    char message[50];
    printf("Enter warning message: ");
    scanf("%49s",message);
    append_log(message);
    printf("Warning message written\n");
}

void device_action(void){
    FILE *file;
    char name[50];
    char action[10];
    printf("Enter device name: ");
    scanf("%49s",name);
    while(true){
        printf("Please Enter Action(ON or OFF): ");
        scanf("%9s",action);
        if(strcmp(action,"ON")==0 || strcmp(action,"OFF")==0){
            break;
        }
        else{
            printf("Invalid Action");
        }
    }
    file = fopen("system_log.txt","a");
    if(file == NULL){
        printf("FILE cannot be opened\n");
        return;
    }
    fprintf(file,"Device %s action: %s \n",name,action);
    fclose(file);
    printf("Sensor reading noted\n");
}

void clear_logs(void){
    write_log("Log file cleared.");
    printf("Logs cleared\n");

}

    
    
    
