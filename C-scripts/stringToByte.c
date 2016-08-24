/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>

unsigned char charToHexDigit(char c)
{
  if (c >= 'A')
    return c - 'A' + 10;
  else
    return c - '0';
}

unsigned char stringToByte(char c[2])
{
  return charToHexDigit(c[0]) * 16 + charToHexDigit(c[1]);
}

