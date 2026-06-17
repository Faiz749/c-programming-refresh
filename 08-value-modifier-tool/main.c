#include <stdio.h>
#include <stdbool.h>
int show_options(void);
void show_values(int*a,int *b);
void update_value1(int *a);
void update_value2(int *b);
void swap_value(int *a,int *b);
void reset_value(int *a,int *b);

int main(void){
    int value_1,value_2,choice;
    printf("Please Enter value 1: ");
    scanf("%d",&value_1);
    printf("Please Enter value 2: ");
    scanf("%d",&value_2);
    do{
        choice = show_options();
        if(choice ==1){
            show_values(&value_1,&value_2);
        }
        else if(choice ==2){
            update_value1(&value_1);
        }
        else if(choice ==3){
            update_value2(&value_2);
        }
        else if(choice==4){
            swap_value(&value_1,&value_2);
        }
        else if(choice ==5){
            reset_value(&value_1,&value_2);
        }
        else{
            printf("Exiting......");
        }
    }while(choice <=5);

    return 0;
}

int show_options(void){

    int choice;
    while(true){
        printf("===== Value Modifier Tool =====\n");
        printf("1. Show values\n");
        printf("2. Update first number\n");
        printf("3. Update second number\n");
        printf("4. Swap numbers\n");
        printf("5. Reset numbers\n");
        printf("6. Exit\n");
        printf("Please Enter your choice: ");
        scanf("%d",&choice);
        if(choice>= 1 && choice<=6){
            break;
        }
        else{
            printf("Invalid Choice. Try again\n");
        }
    }
    return choice;
}

void show_values(int*a,int *b){
    printf("Value 1: %d\n",*a);
    printf("Value 2: %d\n",*b);
}

void update_value1(int *a){
    printf("Enter the updated value 1: ");
    scanf("%d",a);
}

void update_value2(int *b){
    printf("Enter the updated value 2: ");
    scanf("%d",b);
}

void swap_value(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reset_value(int *a,int *b){
    *a = 0;
    *b = 0;
}