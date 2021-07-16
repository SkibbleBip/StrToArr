/**************************************************************************
Copyright (C) 2021 SkibbleBip

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

/***************************************************************************
* File:  main.c
* Author:  SkibbleBip
* Procedures:
* main  -Main function, converts string to char array
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***************************************************************************
* int main(void)
* Author: SkibbleBip
* Date: 07/16/2021
* Description: The main function, converts inputting string from stdin to a char
*               array.
*
* Parameters:
*        main   O/P     int     The returning value of exit
**************************************************************************/
int main(void)
{
        char* input             = NULL;
        size_t input_length     = 0;
        const char* definition  = "char val[] = { ";
        const char* closing     = "0x00 };";
        ssize_t ret             = 0;
        /*definition of the input string, the length of input, the definition
        *of the array in C, the closing null terminator and the bracket, and
        *size of string returned by getline
        */

        printf("Enter string to convert to a byte array: ");
        fflush(stdout);
        /*ask for the string to convert*/

        ret = getline(&input, &input_length, stdin);
        /*obtain the dynamic string from stdin*/
        if(ret < 0){
                perror("Failed to read input string");
                return -1;
                /*if failed to read input, display error and exit*/
        }

        input[ret-1] = '\000';
        /*trim the ending newline*/
        printf("%s",definition);
        fflush(stdout);
        /*print the definition of the char array*/

        char buff[7];
        /*allocate space for the hex code and null terminator for the string*/
        for(size_t i = 0; i < ret-1; i++){
        /*for each char in the string, generate it's equivilent hex value*/
                char tmp = input[i];
                sprintf(buff, "0x%02X, ", tmp);
                printf("%s", buff);
                /*print the buffer*/
        }
        printf("%s\n", closing);
        /*print the closing bracket*/

        free(input);
        /*free the dynamic input*/
        return 0;

}
