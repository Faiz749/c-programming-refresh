#include<stdio.h>
#include<string.h>
#include <stdbool.h>

struct Device{
    char name[50];
    int device_type;
    float value;
    int status;
};

int get_choice(void);
void add_device(struct Device d1[],int count);
void show_device(struct Device d1[],int count);
void update_value(struct Device d1[],int count);
void control_output(struct Device d1[],int count);
void automatic_control(struct Device d1[],int count);
int device_number(struct Device d1[],int count);


int main(void){
    struct Device d[100] = {};
    int choice;
    int count=0;
    int dummy = 0;

    do{
        choice = get_choice();

        if(choice ==1){
            if(count >= 100){
                printf("Device limit reached\n");
            }
            else{
                add_device(d,count);
                count ++;
            }
        }
        else if(choice ==2){
            if(count ==0){
                printf("Enter data first\n");
             
            }
            else{
                show_device(d,count);
            }
        }
        else if(choice ==3){
            if(count ==0){
                printf("Enter data first\n");
            }
            else{
                update_value(d,count);
            }
        }
        else if(choice ==4){
            if(count ==0){
                printf("Enter data first\n");
            }
            else{
                control_output(d,count);
            }
        }
        else if(choice ==5){
            if(count ==0){
                printf("Enter data first\n");
            }
            else{
                dummy = device_number(d,count);
                if(dummy == 0){
                    printf("No input devices found to control.\n");
                }
                else if(dummy == 1){
                    printf("No output devices found. Please add an output device first\n");
                }
                else{
                    automatic_control(d,count);
                }
            }
        }
        else{
            printf("Exiting......\n");
            break;
        }

    }while(choice!=6);

    return 0;
}

int get_choice(void){
    int choice;
    while(true){
       printf("===== Embedded Device Manager =====\n");
       printf("1. Add device\n");
       printf("2. Show all devices\n");
       printf("3. Update input value\n");
       printf("4. Control output device\n");
       printf("5. Run automatic control\n");
       printf("6. Exit\n");
       printf("Please Enter your choice: ");
       scanf("%d",&choice);

       if(choice >=1 && choice<=6){
        break;
       }
       else{
        printf("Invalid choice. Please try again\n");
       }
    }
    return choice;
}

void add_device(struct Device d1[],int count){
    printf("Enter device name: ");
    scanf("%49s", d1[count].name);

    while(true){
       printf("Enter type 1 input, 2 output: ");
       scanf("%d",&d1[count].device_type);

       if(d1[count].device_type>=1 && d1[count].device_type<=2){
        break;
       }
       else{
        printf("Please Enter either 1 or 2 only\n");
       }
    }

    printf("Enter device value: ");
    scanf("%f",&d1[count].value);

    while(true){
        printf("Enter status 1 active, 0 inactive: ");
        scanf("%d",&d1[count].status);

        if(d1[count].status>=0 && d1[count].status<=1){
            break;
        }
        else{
            printf("Please Enter either 0 or 1 only\n");
        }
    }
}

void show_device(struct Device d1[],int count){
    for(int i=0;i<count;i++){
        printf("\nDevice Name: %s\n",d1[i].name);

        if(d1[i].device_type==1){
            printf("Type: Input\n");
        }
        else{
            printf("Type: Output\n");
        }

        printf("Value: %.2f\n",d1[i].value);

        if(d1[i].status==1){
            printf("Status: Active\n");
        }
        else{
            printf("Status: Inactive\n");
        }
    }
}

void update_value(struct Device d1[],int count){
    char name[50];
    int found = 0;

    printf("Enter device Name: ");
    scanf("%49s",name);

    for(int i=0;i<count;i++){
        if(strcmp(name,d1[i].name)==0){
            found = 1;

            if(d1[i].device_type==1){
                printf("Please Enter new value: ");
                scanf("%f",&d1[i].value);
                printf("Value updated\n");
            }
            else{
                printf("Only INPUT devices can have sensor values updated.\n");
            }

            break;
        }
    }

    if(found == 0){
        printf("No such device found\n");
    }
}

void control_output(struct Device d1[],int count){
    char name[50];
    int found = 0;

    printf("Enter device Name: ");
    scanf("%49s",name);

    for(int i=0;i<count;i++){
        if(strcmp(name,d1[i].name)==0){
            found = 1;

            if(d1[i].device_type==2){
                while(true){
                    printf("Enter state 1 ON, 0 OFF: ");
                    scanf("%d",&d1[i].status);

                    if(d1[i].status>=0 && d1[i].status<=1){
                        break;
                    }
                    else{
                        printf("Please Input either 0 or 1 only\n");
                    }
                }
            }
            else{
                printf("Only OUTPUT devices can be controlled.\n");
            }

            break;
        }
    }

    if(found == 0){
        printf("No such device found\n");
    }
}

void automatic_control(struct Device d1[],int count){
    
    float threshold;
    int high = 0;

    printf("Enter threshold value for automatic control: ");
    scanf("%f",&threshold);

    for(int i=0;i<count;i++){
        if(d1[i].device_type==1){
            if(d1[i].value > threshold){
                high = 1;
            }
        }
    }

    if(high == 1){
        for(int j=0;j<count;j++){
            if(d1[j].device_type==2){
                d1[j].status=1;
            }
        }
        printf("WARNING: Sensor value is high. Outputs turned ON.\n");
    }
    else{
        for(int k=0;k<count;k++){
            if(d1[k].device_type==2){
                d1[k].status=0;
            }
        }
        printf("NORMAL: Sensor value is safe. Outputs turned OFF.\n");
    }
}

int device_number(struct Device d1[],int count){
    int count_output = 0;
    int count_input = 0;

    for(int i=0;i<count;i++){
        if(d1[i].device_type==1){
            count_input++;
        }
        else if(d1[i].device_type==2){
            count_output++;
        }
    }

    if(count_input==0){
        return 0;
    }
    else if(count_output==0){
        return 1;
    }
    else{
        return 2;
    }
}