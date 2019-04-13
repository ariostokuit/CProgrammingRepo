//
//  main.c
//  StringLibrary
//
//  Created by Ariosto Kuit on 4/8/19.
//  Copyright © 2019 Ariosto Kuit. All rights reserved.
// This set of instructions demonstrates my understanding of pointers in
// programming language. I try implementing some of the string functions from the <string.h> library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Count the length of char array*/
size_t strlen_(char *s){
    size_t len = 0;
    if(s == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    while(*s != '\0'){
        len++;
        s++;
    }
    return len;
}

/*Another strlen function but accepts a const char *s*/
size_t const_strlen(const char *s){
    size_t len = 0;
    if(s == NULL){ /*If string input is empty*/
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    while(*s != '\0'){
        len++;
        s++;
    }
    return len;
}


/*Copy string ct to string s, includeing '\0', return s*/
char * strcpy_(char * s, const char* ct){
    if(s == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(*ct != '\0'){
        *s = *ct;
        ++ct;
        ++s;
    }
    return s;
}

/*Copy at most n characters of string ct to string s, terminate s with'\0' return s*/
char *strncpy_(char *s, char *ct, size_t n){
    size_t pos = 0;
    char *newS = s;
    
    if(s == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    while(pos < n && *ct != '\0'){
        *newS = *ct;
        ++newS;
        ++ct;
        pos++;
    }
    return s;
}

/*Concatenate cs to s*/
char *strcat_(char *s, char *ct){
    if(s == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    char *pch = malloc(strlen(s) + strlen_(ct) + 1); /*You will need to allocate enough memory*/
    int ptr = 0, temp = 0;
    
    while(s[temp] != '\0'){
        pch[ptr++] = s[temp++];
    }
    temp = 0;
    while(ct[temp] != '\0'){
        pch[ptr++] = ct[temp++];
    }
    
    return pch;
}

/*Concatenate cs to s at most n characters*/
char *strncat_(char *s, const char *ct, size_t n){
    size_t npos = 0;
    char *pch = malloc(strlen_(s) + (strlen_(ct) - (strlen_(ct) - n) + 1)); //Allocate enough memory for the new string
    if(s == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    int ptr = 0, temp = 0;
    
    while(s[temp] != '\0'){
        pch[ptr++] = s[temp++];
    }
    temp = 0;
    while(ct[temp] != '\0' && npos < n){
        pch[ptr++] = ct[temp++];
        npos++;
    }
    pch[ptr] = '\0'; //end the stirng with a null value
    
    return pch;
}

/*Compares the 2 strings*/
int strcmp_(const char *cs, const char* ct){
    int result = 0;
    
    if(cs == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(*cs != '\0' && *ct != '\0'){ //compares the characters based on ASCII
        if(*cs == *ct){
            ++cs;
            ++ct;
        }
        else if(*cs < *ct){
            result -= 1;
            ++cs;
            ++ct;
        }
        else{
            result +=1;
            ++cs;
            ++ct;
        }
    }
    return result;
}

/*Compares a number of characters in both strings*/
int strncmp_(const char *cs, const char *ct, size_t n){
    int result = 0;
    size_t npos = 0;
    
    if(cs == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(npos < n && (*cs!='\0' && *ct!='\0')){
        if(*cs == *ct){
            ++cs;
            ++ct;
            npos++;
        }
        else if(*cs < *ct){
            result -= 1;
            ++cs;
            ++ct;
            npos++;
        }
        else{
            result +=1;
            ++cs;
            ++ct;
            npos++;
        }
    }
    return result;
}

/*Searches for desire char in string*/
const char *strchr_(const char *cs, char ch){
    while(*cs != '\0'){
        if(*cs == ch){ //if cs == ch that means character is found
            return cs;
        }
        else if(*cs != ch){ //continue loop if characters do not match
            ++cs;
        }
    }
    return NULL;
}

/*swap all character in the string with the desired character*/
int main(int argc, const char * argv[]) {

    /*test StrLen function*/
    char str1[] = "Hello";
    printf("The length of the string 'Hello' is: ");
    printf("%ld\n",strlen_(str1));
    
    /*Test strccpy()*/
    char str2[] = "William Au";
    char str2_cpy[40];
    strcpy_(str2_cpy,str2);
    printf("%s\n",str2);
    printf("%s\n",str2_cpy);
    
    /*Test strncpy()*/
    char strncpy1[] = "joshua";
    char strncpy2[10];
    strncpy_(strncpy2,strncpy1,3);
    printf("%s\n", strncpy1);
    printf("%s\n", strncpy2);
    
    /*Test Strcmp()*/
    char strcmp1[] = "Hello";
    char strcmp2[] = "Hello";
    char strcmp3[] = "hello";
    
    if(strcmp_(strcmp1,strcmp2) == 0){
        printf("Both strings equal to each other\n");
    }
    else
        printf("Both strings do not equal to each other\n");
    
    if(strcmp_(strcmp1,strcmp3) == 0){
        printf("Both strings equal to each other\n");
    }
    else
        printf("the strings do not equal each other\n");
    
    /*Test Strncmp*/
    char strncmp1[] = "supreme";
    char strncmp2[] = "supreme";
    char strncmp3[] = "SuPreme";
    
    if(strncmp_(strncmp1,strncmp2,2) == 0){
        printf("Both strings are a match\n");
    }
    else
        printf("The two strings do not match\n");
    
    if(strncmp_(strncmp1,strncmp3,2)==0){
        printf("The strings are a match\n");
    }
    else
        printf("The two strings do not match\n");
    
    
    /*Test strchr*/
    char character = 'c';
    char array1[] = "character";
    char *pch;
    printf("Searching %c in %s\n",character,array1);
    pch = strchr_(array1,character);
    do{
        printf("Found at %ld\n",pch - array1 +1 );
        pch = strchr_(pch+1,character);
    }while(pch != NULL);
    
    /*Test Strcat*/
    char Strcat1[] = "Hello";
    char Strcat2[] = " World";
    printf("Strcat1 = %s\n",Strcat1);
    printf("Strcat2 = %s\n",Strcat2);
    printf("Concatenating the two arrays: ");
    printf("%s", strcat_(Strcat1, Strcat2));
  
    /*Test strncat*/
    size_t n = 3;
    printf("Strcat1 = %s\n",Strcat1);
    printf("Strcat2 = %s\n",Strcat2);
    printf("Want to concatenate %ld characters to Strcat1\n",n);
    pch = strncat_(Strcat1,Strcat2,n);
    printf("Result: %s",pch);
    
    return 0;
}
