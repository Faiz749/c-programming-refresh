#include<stdio.h>

int get_length(char sentance[]);
int count_vowel(int size,char sentance[]);
int count_consonants(int size,char sentance[]);
int count_spaces(int size,char sentance[]);
int count_digits(int size,char sentace[]);
int count_upper_case(int size,char sentance[]);
int count_lower_case(int size,char sentance[]);

int main(void){
    char sentance[50];
    printf("Please enter a sentance: ");
    fgets(sentance,sizeof(sentance),stdin);
    int length = get_length(sentance);
    printf("Letters                      = %d\n",length);
    printf("Vowel count                  = %d\n",count_vowel(length,sentance));
    printf("Consonants count             = %d\n",count_consonants(length,sentance));
    printf("Number of digits             = %d\n",count_digits(length,sentance));
    printf("Number of spaces             = %d\n",count_spaces(length,sentance));
    printf("Number of upper case letters = %d\n",count_upper_case(length,sentance));
    printf("Number of Lower case letters = %d\n",count_lower_case(length,sentance));
    return 0;
}

int get_length(char sentance[]){
    int size =0;
    while(sentance[size] != '\n' && sentance[size] != '\0'){
        size ++;
    }
    return size;
}

int count_vowel(int size,char word[]){
    int count=0;
    for(int i=0;i<size;i++){
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i'|| word[i] == 'o'||word[i] == 'u' ||
        word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U'){
            count ++;
        }
    }
    return count;
}
int count_consonants(int size,char word[]){
    int count =0;
    for(int i=0;i<size;i++){
        if((word[i]>'a' && word[i]<'z')|| (word[i]>'A' && word[i]<'Z')){
            if (!(word[i] == 'a' || word[i] == 'e' || word[i] == 'i'|| word[i] == 'o'||word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')){
            count ++;
          }

        }
    }
    return count;
}

int count_spaces(int size,char sentance[]){
    int count=0;
    for(int i =0;i<size;i++){
        if(sentance[i] == ' '){
            count++;

        }
    }
    return count;
}

int count_digits(int size,char sentance[]){
    int count=0;
    for(int i = 0 ;i<size;i++){
        if(sentance[i] >= '0' && sentance[i]<='9'){
            count++;
        }
    }
    return count;
}

int count_upper_case(int size,char sentance[]){
    int count=0;
    for(int i =0;i<size;i++){
        if(sentance[i] >= 'A' && sentance[i]<='Z'){
            count++;
        }
    }
    return count;
}

int count_lower_case(int size,char sentance[]){
    int count=0;
    for(int i =0;i<size;i++){
        if(sentance[i] >= 'a' && sentance[i]<='z'){
            count++;
        }
    }
    return count;
}
