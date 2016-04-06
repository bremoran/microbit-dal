/**
  * This file contains functions used to maintain compatability and portability.
  * It also contains constants that are used elsewhere in the DAL.
  */

#ifndef MICROBIT_COMPAT_H
#define MICROBIT_COMPAT_H

#include "mbed.h"
#include "MicroBitConfig.h"

#define PI 3.14159265359

/**
  * Determines the smallest of the two numbers
  *
  * @param a the first number
  *
  * @param b the second number
  *
  * @return The smallest of the two given values.
  */
inline int min(int a, int b)
{
    return (a < b ? a : b);
}

/**
  * Determines the largest of the two numbers
  *
  * @param a the first number
  *
  * @param b the second number
  *
  * @return The larger of the two given values.
  */
inline int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
  * Sets a given area of memory to zero.
  *
  * @param a the pointer to the beginning of the memory to clear
  *
  * @param b the number of bytes to clear.
  */
inline void *memclr(void *a, size_t b)
{
    return memset(a,0,b);
}

/**
  * Determines if the given character is a printable ASCII/UTF8 decimal digit (0..9).
  *
  * @param c the character to check
  *
  * @return true if the character is a digit, false otherwise.
  */
inline bool isdigit(char c)
{
    return (c > 47 && c < 58);
}

/**
  * Performs an in buffer reverse of a given char array.
  *
  * @param s the string to reverse.
  *
  * @return MICROBIT_OK, or MICROBIT_INVALID_PARAMETER.
  */
int string_reverse(char *s);

/**
  * Converts a given integer into a string representation.
  *
  * @param n The number to convert.
  *
  * @param s A pointer to the buffer where the resulting string will be stored.
  *
  * @return MICROBIT_OK, or MICROBIT_INVALID_PARAMETER.
  */
int itoa(int n, char *s);

#endif