#include "directory.h"

#include <Windows.h>
#include <stdio.h>
#include <sys/stat.h>

bool getDirectory(char * cwd, int size) 
{
    DWORD result = GetCurrentDirectoryA(size, cwd);

    if (result == 0) 
    {
        DWORD error = GetLastError();

        printf("GetCurrentDirectory failed with error %lu\n", error);
        
        return false;
    } 
    
    // else {
    //     printf("%s\n", cwd);
    // }

    return true;
    
}

//Create new folders 
bool newdirectory(const char *cwd, const char *newname)
{
    char fullPath[256];

    snprintf(fullPath, sizeof(fullPath), "%s\\%s", cwd, newname);

    if(mkdir(fullPath) == 0)
    {
        printf("Directory created sucessfully: %s\n", fullPath);

        return true;
    }

    return false;
}

//Start a git repository

bool gitInit(const char *cwd)
{
    // char command[256];

    // snprintf(command, sizeof(command), "cd /d \"%s\" && git init", cwd);

    int result = system("git init");

    if (result == 0) 
    {
        printf("Git Repository successfully created: %s\n", cwd);

        return true;
    }    
    
    printf("Failed to create git repository : %s\n", cwd);

    return false;
}

// int main() 
// {
//     char cwd[MAX_PATH];

//     if(getDirectory(cwd, MAX_PATH) != 0)
//     {
//         return 1;
//     }

//     newDirectory(cwd, "src"); 
//     newDirectory(cwd, "includes"); 
//     newDirectory(cwd, "bin");
    
//     gitInit(cwd);

//     return 0;
// }