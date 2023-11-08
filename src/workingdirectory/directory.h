#define DIRECTORY_H
#ifndef DIRECTORY_H

#include <Windows.h>
#include <stdio.h>

int getDirectory(char *cwd, int size) 
{
 
    DWORD result = GetCurrentDirectory(size, cwd);

    if (result == 0) 
    {
        DWORD error = GetLastError();

        printf("GetCurrentDirectory failed with error %lu\n", error);
        
        return 1;
    } 
    
    else 
    {
        printf("%s\n", cwd);
    }

    return 0;
    
}

int gitInit(char *cwd)
{
    char command[100];

    snprintf(command, sizeof(command), "git init %s", cwd);

    int result = system(command);

    if (result == 0) 
    {
        printf("Git Repository successfully created: %s\n", cwd);
    } 
    
    else 
    {
        printf("Failed to create git repository : %s\n", cwd);
    }

    return 0;
}
#endif