#include<stdio.h>
#include<stdbool.h>
float sum(int length,float number[]);
float max(int length,float number[]);
float min(int length,float number[]);
int pass(int length,float number[]);
int main(void){
    int size,passing,failing;
    float average,total;
    while(true){
    printf("Enter number of subjects: ");
    scanf("%d",&size);
    if(size>0){
        break;
     }
    else{
        printf("Invalid input please try again \n");
     }

    }
    float number[size];
    for(int i=0;i<size;i++){
        while(true){
            printf("Please enter marks of Subject %d = ",i+1);
            scanf("%f", &number[i]);
            if(number[i]>=0 && number[i]<=100){
                break;
            }
            else{
                printf("Invalid input please try again \n");  
            }
        }
    }
    total = sum(size,number);
    average = (float)total/size;
    printf("Total  Marks  = %.2f \n",total);
    printf("Average Marks = %.2f \n",average);
    printf("Highest Marks = %.2f \n",max(size,number));
    printf("Lowest  Marks = %.2f \n",min(size,number));
    passing = pass(size,number);
    failing = size - passing;
    printf("Number of subjects passed = %d \n",passing);
    printf("Number of subjects failed = %d \n",failing);
    
    return 0;

}
float sum(int length,float number[]){
    float sum = 0;
    for(int i=0;i<length;i++){
        sum += number[i];
    }
    return sum;
}

float max(int length,float number[]){
    float max = number[0];
    for(int i=1;i<length;i++){
        if(max < number[i]){
            max = number[i];
        }
    }
    return max;
}

float min(int length,float number[]){
    float min = number[0];
    for(int i=1;i<length;i++){
        if(min > number[i]){
            min = number[i];
        }
    }
    return min;
}

int pass(int length,float number[]){
    int pass = 0;
    for(int i=0;i<length;i++){
        if(number[i]>=50){
            pass ++;
        }
    }
    return pass;
}

