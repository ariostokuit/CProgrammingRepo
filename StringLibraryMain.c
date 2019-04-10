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
char *strncpy_(char *s, const char *ct, size_t n){
    size_t pos = 0;
    
    if(s == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    while(pos < n && *ct != '\0'){
        *s = *ct;
        s++;
        ct++;
        pos++;
    }
    return s;
}

/*Concatenate cs to s*/
char *strcat(char *s,const char *ct){
    if(s == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(*ct != '\0'){
        *(s+1) = *ct;
        ++ct;
    }
    return s;
}

/*Concatenate cs to s at most n characters*/
char *strncat(char *s, const char *ct, size_t n){
    size_t npos = 0;

    if(s == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    while(npos < n && *ct != '\0'){
        *(s+1) = *ct;
        ++ct;
        npos++;
    }
    return s;
}

/*Compares the 2 strings*/
int strcmp_(const char *cs, const char* ct){
    int result = 0;
    
    if(cs == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(*cs != '\0' && *ct != '\0'){
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

/*strspn returns the length of prefix of cs consisting of characters in ct*/
size_t strspn_(const char*cs, const char*ct){
    size_t preLen = 0; //prefix length
    
    if(cs == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(*cs != '\0'&& *ct != '\0'){
        if(*cs == *ct){
            preLen++;
            ++cs;
            ++ct;
        }
        else
            ++ct;
    }
    return preLen;
}

/*strcspn return length of prefix of cs consisiting of chracters not in ct*/
size_t strcspn_(const char *cs, const char *ct){
    size_t len_notinCT = 0;
    
    if(cs == NULL || ct == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(*cs !='\0' && *ct != '\0'){
        if(*cs != *ct){
            len_notinCT++;
            ++cs;
            ++ct;
        }
        else{
            ++cs;
            ++ct;
        }
    }
    return len_notinCT;
}

/*swap all character in the string with the desired character*/
char *swapChar(char *s, char charistr ,char char_toswap){ /*charistr = character in string*/
    if(s == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    
    while(*s != '\0'){
        if(*s == charistr){
            *s = char_toswap;
            ++s;
        }
        ++s;
    }
    return s;
}

/*This function removes a string of characters from a string*/
char *removeCharinString(char *s, const char ch){
    if(s == NULL){
        fprintf(stderr, "Error, empty string found\n");
        exit(-1);
    }
    while(*s != '\0'){
        if(*s == ch){
            *s = ' ';
            ++s;
        }
        if(*s == '\0'){
            return NULL; /*Character in the string does not exist*/
        }
    }
    return s;
}

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
    char strncpy2[40];
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
    char strncmp3[] = "suPreme";
    
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
    
    /*Test strspn*/
    
    return 0;
}
