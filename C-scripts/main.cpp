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

int main(int argc, char** argv) {

    test_checkTag();


    return 0;
}

