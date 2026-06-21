#include <stdio.h>
#include <stdbool.h>

int get_choice(void);
void show_valid_readings(void);
void count_readings(void);
void calculate_average(void);
void get_highest_lowest(void);
void get_reading(void);
void show_status(void);

int main(void){
    int choice;
    do{
        choice = get_choice();
        if(choice ==1){
            show_valid_readings();
        }
        else if(choice ==2){
            count_readings();
        }
        else if(choice ==3){
            calculate_average();
        }
        else if(choice ==4){
            get_highest_lowest();
        }
        else if(choice ==5){
            get_reading();
        }
        else if(choice ==6){
            show_status();
        }
        else{
            printf("Exiting.....");
        }

    }while(choice !=7);
    return 0;
}

int get_choice(void){
    int choice;
    while(true){
        printf("===== Sensor File Analyzer =====\n");
        printf("1. Show all valid readings\n");
        printf("2. Count valid readings\n");
        printf("3. Calculate average\n");
        printf("4. Find highest and lowest\n");
        printf("5. Count danger readings\n");
        printf("6. Show system status\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice >=1 && choice<=7){
            break;
        }
        else{
            printf("Invalid choice please try again\n");
        }
    }
    return choice;
}

void show_valid_readings(void){
    FILE *file;
    char token[10];
    float value;
    file = fopen("readings.txt","r");
    if(file == NULL){
        printf("Couldn't access file\n");
        return;
    }
    while(fscanf(file,"%9s",token)==1){
        if(sscanf(token,"%f",&value)==1){
            printf("Valid reading: %.2f\n",value);
        }
        else{
            printf("Invalid reading: %s\n",token);
        }
    }
    fclose(file);
}

void count_readings(void){
    FILE *file;
    char token[10];
    float value;
    int valid_count = 0;
    int invalid_count = 0;
    file = fopen("readings.txt","r");
    if(file == NULL){
        printf("Couldn't access file\n");
        return;
    }
    while(fscanf(file,"%9s",token)==1){
        if(sscanf(token,"%f",&value)==1){
            valid_count++;
        }
        else{
            invalid_count++;
        }
    }
    fclose(file);
    printf("Valid Entries: %d\n",valid_count);
    printf("Invalid Entries skipped: %d\n",invalid_count);
}

void calculate_average(void){
    FILE *file;
    char token[10];
    float value;
    float sum = 0;
    int count = 0;
    int invalid_count = 0;
    file = fopen("readings.txt","r");
    if(file == NULL){
        printf("Couldn't access file\n");
        return;
    }
    while(fscanf(file,"%9s",token)==1){
        if(sscanf(token,"%f",&value)==1){
            sum += value;
            count++;
        }
        else{
            invalid_count++;
        }
    }
    fclose(file);
    if(count > 0){
    printf("Average readings:  %.2f\n",sum/count);
    printf("Invalid Entries skipped: %d\n",invalid_count);
    }
    else{
        printf("No Valid readings\n");
    }
}

void get_highest_lowest(void){
    FILE *file;
    char token[10];
    float value;
    float highest,lowest;
    int count =0;
    file = fopen("readings.txt","r");
    if(file == NULL){
        printf("Couldn't access file\n");
        return;
    }
    while(fscanf(file,"%9s",token)==1){
        if(sscanf(token,"%f",&value)==1){
            if(count ==0){
                highest = value;
                lowest = value;
            }
            if(value > highest){
                highest = value;
            }
            if(lowest > value){
                lowest = value;
            }

        count ++;
        }
    }
    fclose(file);
    if(count >0){
        printf("Highest Reading:%.2f \n",highest);
        printf("Lowest Reading:%.2f \n",lowest);
    }
    else{
        printf("No valid data");
    }
}

void get_reading(void){
    FILE *file;
    char token[10];
    float value;
    float threshold;
    int count = 0;
    int invlaid_count = 0;
    printf("Please enter threshold: ");
    scanf("%f",&threshold);
    file = fopen("readings.txt","r");
    if(file == NULL){
        printf("Couldn't access file\n");
        return;
    }
    while(fscanf(file,"%9s",token)==1){
        if(sscanf(token,"%f",&value)==1){
            if(value >  threshold){
                count ++;
            }
        }
        else{
            invlaid_count ++;
        }
    }

    fclose(file);
    printf("Danger readings: %d\n",count);
    printf("Readings skipped: %d\n",invlaid_count);
}

void show_status(void){
    FILE *file;
    char token[10];
    float value;
    float threshold;
    int count = 0;
    int invlaid_count = 0;
    printf("Please enter threshold: ");
    scanf("%f",&threshold);
    file = fopen("readings.txt","r");
    if(file == NULL){
        printf("Couldn't access file\n");
        return;
    }
    while(fscanf(file,"%9s",token)==1){
        if(sscanf(token,"%f",&value)==1){
            if(value >  threshold){
                count ++;
            }
        }
        else{
            invlaid_count ++;
        }
    }

fclose(file);

if(count == 0){
    printf("Danger Reading: %d\n",count);
    printf("System status: NORMAL\n");
}
else if(count>=1 && count<=2 ){
    printf("Danger Reading: %d\n ",count);
    printf("System status: WARNING\n");
    
}
else{
    printf("Danger Reading: %d\n ",count);
    printf("System status: Danger\n");

}
}
