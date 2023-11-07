#include <Windows.h>
#include <stdio.h>

int main() 
{
    char cwd[MAX_PATH];
    
    DWORD result = GetCurrentDirectory(MAX_PATH, cwd);

    if (result == 0) 
    {
        DWORD error = GetLastError();
        printf("GetCurrentDirectory failed with error %lu\n", error);
    } 
    
    else 
    {
        printf("%s\n", cwd);
    }

    return 0;
}