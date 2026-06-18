#include<stdio.h>
#include<stdbool.h>

int get_size(void);
void input_readings(int size,float *arr);
int show_choice(void);
void show_readings(int size,float *arr);
float return_average(int size,float *arr);
float return_highest(int size,float *arr);
float return_lowest(int size,float *arr);
void calibration_value(int size,float *arr);
int danger_count(int size,float *arr);
void show_status(int count);


int main(void){
    int size,choice ;
    bool value_entered = false;
    float readings[100];
    do{
        choice = show_choice();
        if(choice == 1){
            size = get_size();
            input_readings(size,readings);
            value_entered = true;
        }
        else if(choice ==2){
            if(value_entered){
                show_readings(size,readings);
            }
            else{
                printf("Please input sensor readings first.\n");
            }
        }
        else if(choice ==3){
            if(value_entered){
                float average = return_average(size,readings);
                printf("Average reading: %.2f\n",average);
            }
            else{
                printf("Please input sensor readings first.\n");
            }
        }
         else if(choice ==4){
            if(value_entered){
                float highest = return_highest(size,readings);
                printf("Highest reading: %.2f\n",highest);
            }
            else{
                printf("Please input sensor readings first.\n");
            }
        }
         else if(choice ==5){
            if(value_entered){
                float lowest = return_lowest(size,readings);
                printf("Lowest reading: %.2f\n",lowest);
            }
            else{
                printf("Please input sensor readings first.\n");
            }
        }
         else if(choice ==6){
            if(value_entered){
                calibration_value(size,readings);
            }
            else{
                printf("Please input sensor readings first.\n");
            }
        }
         else if(choice ==7){
            if(value_entered){
                int count = danger_count(size,readings);
                printf("Danger readings: %d\n",count);
                show_status(count);

            }
            else{
                printf("Please input sensor readings first.\n");
            }
        }
         else{
            printf("Exiting....\n");
        }

    }while(choice!=8);
    return 0;
}

int show_choice(void){
    int choice;
    printf("===== Array Pointer Analyzer =====\n");
    printf("1. Input sensor readings\n");
    printf("2. Display all readings\n");
    printf("3. Show average reading\n");
    printf("4. Show highest reading\n");
    printf("5. Show lowest reading\n");
    printf("6. Add calibration value\n");
    printf("7. Show danger report\n");
    printf("8. Exit\n");

    while(true){
        printf("Please Enter your choice: ");
        scanf("%d",&choice);
        if(choice>=1 && choice<=8){
            break;
        }
        else{
            printf("Invalid Choice. Please try again\n");
        }
    }
    return choice;

}

int get_size(void){
    int length;

    while(true){
        printf("Please Enter number of readings: ");
        scanf("%d",&length);
        if(length > 0 && length <=100){
            break;
        }
        
        else{
            printf("Invalid Size entered. Make sure the length is between 1 and 100\n");
        }
    }
    return length;
}

void input_readings(int size,float *arr){
    for(int i=0;i<size;i++){
        printf("Enter reading %d: ",i+1);
        scanf("%f", arr+i);
    }
}

void show_readings(int size,float *arr){
    for(int i=0;i<size;i++){
        printf("Reading %d: %.2f\n",i+1,*(arr+i));
    }
}

float return_highest(int size,float *arr){
    float highest = *(arr+0);
    for(int i=1;i<size;i++){
        if(highest < *(arr+i)){
            highest = *(arr+i);
        }
    }
    return highest;
}

float return_lowest(int size,float *arr){
    float lowest = *(arr+0);
    for(int i=1;i<size;i++){
        if(lowest > *(arr+i)){
            lowest = *(arr+i);
        }
    }
    return lowest;
}

float return_average(int size,float *arr){
    float sum = 0;
    for(int i=0;i<size;i++){
        sum += *(arr+i);
    }
    return sum/size;
}

void calibration_value(int size,float *arr){
    float calibration;
    printf("Enter calibration Value: ");
    scanf("%f",&calibration);
    for(int i=0;i<size;i++){
        *(arr+i)+= calibration;
    }
    printf("All values calibrated by %.2f\n",calibration);
}

int danger_count(int size,float *arr){
    int count =0;
    float threshold;
    printf("Enter danger threshold: ");
    scanf("%f",&threshold);
    for(int i=0;i<size;i++){
        if(threshold < *(arr+i)){
            count ++;
        }
    }
    return count;
}

void show_status(int count){

    if(count>=0 && count<=1){
        printf("readings = NORMAL\n");
    }
    else if(count>=2 && count<=3){
        printf("readings = WARNING\n");
    }
    else{
        printf("readings = DANGER\n");
    }
}