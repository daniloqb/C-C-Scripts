/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: tic
 *
 * Created on 23 de Agosto de 2016, 19:54
 */

#include <cstdlib>
#include <stdio.h>
#include "stringToByte.c"
#include <string.h>

using namespace std;

/*
 * 
 */

void test_stringToByte() {

    char c[2] = {'6', 'F'};
    char result;

    result = stringToByte(c);
    printf("%x", result);
}

void test_checkTag() {
    /*
     * Este script testa se o checksum de uma tag RFID 125khz eh valida.
     */
    int tagLen = 12;
    char tag[tagLen] = {'0', '0', '0', '0', '0', '0', '1', '4', '5', '0', '4', '4'};
    char checksum[2] = {'0', '0'};;
    char checksumValue = '\0';
    char piece[2] = {'0', '0'};
    char hexValue = '\0';

    strncpy(checksum,tag+10,2);
    checksumValue = stringToByte(checksum);
    
    for (int i = 0; i < tagLen-2; i+=2){
        strncpy(piece,tag+i,2);
        hexValue ^= stringToByte(piece);
        printf("%.2x\n",hexValue);
    }
    printf("%.2x\n",checksumValue);
    
    if (checksumValue == hexValue){
        printf("Checksum correct\n");        
    }
    else{
        printf("Invalid checksum.\n");
    }
    
}
const int MAX_PARAMS = 3;


typedef struct param {
    char name[20];
    char value[20];
    
}Params;

char url[255] = "/rgblamp?color=255;brightness=100";
// char url[] = "/rgblamp?red=255;green=0;blue=255";
Params params[MAX_PARAMS];
char uri[255];




void split_url(char  * url, char * uri, Params *params){

  
    char * raw_params[MAX_PARAMS];
    char * token;
    
    int num_params = 0;
    
    token = strtok(url,"?");
    strncpy(uri,token,255);
    token = strtok(NULL,"?");

    
    token = strtok(token,"&;");
    
    while(token != NULL && num_params < MAX_PARAMS){
        raw_params[num_params] = token;
        token = strtok(NULL,"&;");
        num_params++;
    }
    
    for(int i=0; i < num_params;i++){
    
      token = strtok(raw_params[i],"=");
      strncpy(params[i].name,token,20);
      token = strtok(NULL,"=");
      if(token !=NULL){

        strncpy(params[i].value,token,20);
      }else{
        strncpy(params[i].value,"",20);

      }
      
    }
   
}


char * getParam(char * name){
    
       
    for(int i=0; i < MAX_PARAMS;i++){
        
        if (strcmp(params[i].name,name) == 0){
            return params[i].value;
        }
    }
    
    return NULL;
}



int main(int argc, char** argv) {

   // test_checkTag();

    
     strcpy(uri,"");
    for(int i=0;i< MAX_PARAMS;i++){
        strcpy(params[i].name,"");
        strcpy(params[i].value,"");
    }
    
    split_url(url,uri,params);
    
    
    printf("Param Value: %s", getParam("brightness"));
    
    return 0;
}

