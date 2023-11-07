#include "tracker.h"

void list_files(char* origin)
{
    DIR *d;
    dirent *dir;

    d = opendir(origin);

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

int main(int argc, char* argv[])
{
    assert(argc > 1);

    list_files(argv[1]);

    return 0;
}