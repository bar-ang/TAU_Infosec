#include <stdbool.h>
#include <stdio.h>
#include <limits.h>


#define _INT_MAX_DIGITS CHAR_BIT * sizeof(int) //find how many digits has INT_MAX in radix 2 with sign
/*
 convert integer into a representable string at certain radix


 @param int     n:    the number that have to be converted
 @param char *str:    the buffer where the new string will be putted into
 @param int radix:    the radix of whom the number will be converted to, must be between 0x02 and 0x10


 @return char*:        pointer to str
 
 @undefined behavior when:
    radix is not between  0x02 and 0x10
    str size is not big enough to contain the string
*/
char *itoa(int n, char *str, int radix)
{
    bool sgn = false;
    char buf[_INT_MAX_DIGITS];
    int dgt;
    int buf_loc = 0;
    int str_loc = 0;


    //take care of MSB signed integer
    if (n < 0)
    {
        sgn = true;
        n = (-n); //switching actual sign, to positive, overflow proof (can't multiply)
    }


    //construct the string backward
    do
    {
        dgt = (unsigned int)n % radix; //safe conversation, sign took care of
        buf[buf_loc++] = dgt < 0x0a
            ? dgt + '0'  //any number  < 0x0a required representation between '0' to '9'
            : dgt - 0x0a + 'a'; //other numbers required representation between 'a' and 'f', safe substruction, value guaranteed > 0x0a


        n = (((unsigned int)n) / radix); //split off the first digit
    } while ((unsigned int)n > 0);


    //add the sign back
    if (sgn)
        buf[buf_loc] = '-';
    else
        buf_loc--;


    //reverse the reversed string
    while (buf_loc >= 0) // copy bytes until retracted to the start, end of the actual string
        str[str_loc++] = buf[buf_loc--];


    str[str_loc] = NULL; // add null termination.
    return str;
}
#undef _INT_MAX_DIGITS