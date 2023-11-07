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

// int createGitInit() 
// {
//     const char* repoName = "C:/Users/Aluno/Desktop/teste";
//     char command[100];
//     snprintf(command, sizeof(command), "git init %s", repoName);

//     int result = system(command);

//     if (result == 0) 
//     {
//         printf("Git Repository successfully created: %s\n", repoName);
//     } 
    
//     else 
//     {
//         printf("Failed to create git repository : %s\n", repoName);
//     }

//     return 0;
// }