#include <Windows.h>
#include <stdio.h>
#include "directory.h"

int main() 
{
    char cwd[MAX_PATH];

    if(getDirectory(cwd, MAX_PATH) != 0)
    {
        return 1;
    }
    
    gitInit(cwd);

    return 0;
}