#include <Windows.h>
#include <stdio.h>
#include <sys/stat.h>
#include "directory.h"

int main() 
{
    char cwd[MAX_PATH];

    if(getDirectory(cwd, MAX_PATH) != 0)
    {
        return 1;
    }

    newDirectory(cwd, "src"); 
    newDirectory(cwd, "includes"); 
    newDirectory(cwd, "bin");
    
    gitInit(cwd);

    return 0;
}