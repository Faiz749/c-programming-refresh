#include <stdio.h>
#include <stdbool.h>
int get_length(void);
void get_inputs(int length,float number[]);
void get_readings(int length,float number[]);
void highest_lowest_average(int length,float number[]);
void count_normal_warning_danger(int length,float number[]);
void count_therashold(int length,float number[]);
bool search_readings(int length,float number[]);
int main(void){
    int size,choice;
    size = get_length();
    float readings[size];
    get_inputs(size,readings);
    do{
        printf("=======Sensor Reading Analyzer=======\n");
        printf("Enter 1 to show all readings\n");
        printf("Enter 2 for average,highest,lowest readings\n");
        printf("Enter 3 to count normal/warning/danger readings\n");
        printf("Enter 4 to count readings above custom therashold\n");
        printf("Enter 5 to search a reading\n");
        printf("Enter 6 to get a full report\n");
        printf("Enter 7 to Exit the program\n");
        while(true){
            printf("Please Enter your choice: ");
            scanf("%d",&choice);
            if(choice>=1 && choice<=7){
                break;
            }
            else{
                printf("Invalid Input Please try again \n");
            }
        }

        if(choice ==1){
            get_readings(size,readings);

        }
        else if(choice ==2){
            highest_lowest_average(size,readings);
        }
        else if(choice ==3){
            count_normal_warning_danger(size,readings);
        }
        else if(choice ==4){
            count_therashold(size,readings);
        }
        else if(choice ==5){
            if( search_readings(size,readings)){
                printf("Reading found\n");
            }
            else{
                printf("Reading not found\n");
            }
        }
        else if(choice ==6){
            printf("===== Full Sensor Report =====\n");
            printf("Total Readings = %d\n",size);
            highest_lowest_average(size,readings);
            count_normal_warning_danger(size,readings);

        }
        else {
            printf("Exiting..........\n");
        }


    }while(choice!=7);
    return 0;

}

int get_length(void){
    int size;
    while(true){
        printf("Enter number of readings: ");
        scanf("%d",&size);
        if(size > 0){
            break;
        }
        else{
            printf("Invalid size inputed. Please try again\n");
        }
    }
    return size;
}

void get_inputs(int length,float number[]){
    for(int i=0;i<length;i++){
        while(true){
            printf("Please enter reading %d : ",i+1);
            scanf("%f",&number[i]);
            if(number[i]>=-50 && number[i]<=100){
                break;
            }
            else{
                printf("Invalid Temperature reading. Please try again\n");
            }
        }
    }
}

void get_readings(int length,float number[]){
    for(int i=0;i<length;i++){
        printf("Reading %d : %.2f\n",i+1,number[i]);
    }
}

void highest_lowest_average(int length,float number[]){
    float highest = number[0];
    float lowest = number[0];
    float sum = number[0];
    for(int i=1;i<length;i++){
        sum += number[i];
        if(highest < number[i]){
            highest = number[i];
        }
        if(lowest > number[i]){
            lowest = number[i];
        }
    }
    float average = sum/length;
    printf("Highest Temperature: %.2f \n", highest);
    printf("Lowest  Temperature: %.2f \n", lowest );
    printf("Average Temperarure: %.2f \n",average);
}

void count_normal_warning_danger(int length,float number[]){
    int count_normal = 0;
    int count_warning = 0;
    int count_danger = 0;
    float danger_percentage;
    for(int i=0;i<length;i++){
        if(number[i]<30){
            count_normal ++;
        }
        else if(number[i]<40){
            count_warning ++;
        }
        else{
            count_danger ++;
        }
    }
    printf("Normal readings: %d\n", count_normal);
    printf("Warning readings: %d\n",count_warning);
    printf("Danger readings: %d\n", count_danger);
    danger_percentage = (float) count_danger / length * 100;
    printf("Danger percentage: %.2f%%\n", danger_percentage);


}

void count_therashold(int length,float number[]){
    int count=0;
    float value;
    while(true){
         printf("Please Enter therashold value: ");
         scanf("%f",&value);
         if(value>= -50 && value<=100){
            break;
         }
         else{
            printf("Invalid Value. Please try again\n");
         }
    }
    for(int i=0;i<length;i++){
        if(number[i]>value){
            count ++;
        }
    }
    printf("Value above therashold value is: %d\n ",count);
}

bool search_readings(int length,float number[]){
    float temp;
    printf("Please Enter the reading u want to search: ");
    scanf("%f",&temp);
    for(int i=0;i<length;i++){
         if(temp == number[i]){
            return true;
         }
    }
    return false;
}