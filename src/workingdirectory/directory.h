#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <Windows.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int getDirectory(char *cwd, int size) 
{
 
    DWORD result = GetCurrentDirectoryA(size, cwd);

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

int newDirectory(const char *cwd, const char *newname)
{
    char fullPath[256];

    snprintf(fullPath, sizeof(fullPath), "%s\\%s", cwd, newname);

    if(mkdir(fullPath) == 0)
    {
        printf("Directory created sucessfully: %s\n", fullPath);
    }
}

int gitInit(const char *cwd)
{
    char command[256];

    snprintf(command, sizeof(command), "cd /d \"%s\" && git init", cwd);

    int result = system(command);

    if (result == 0) 
    {
        printf("Git Repository successfully created: %s\n", cwd);
    } 
    
    else 
    {
        printf("Failed to create git repository : %s\n", cwd);
    }

    return result;
}
#endif