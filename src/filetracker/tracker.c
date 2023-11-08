#include "tracker.h"

LinkedList *headers, *impls;

bool is_directory(struct dirent* dir)
{
    DIR* d = opendir(dir->d_name);
    struct dirent* test;

    return ((dir = readdir(d)) != NULL);
}

bool check_extension(char* filename, char* extension)
{
    char *ext = strrchr(filename, '.');
    return (strcmp(ext, extension) == 0);
}

void find_members(char* origin)
{
    DIR* d = opendir(origin);
    struct dirent* dir;

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (check_extension(dir->d_name, ".h"))
            {
                append_list(headers, init_node(dir, NULL, NULL));
            }
            else if (check_extension(dir->d_name, ".c"))
            {
                append_list(impls, init_node(dir, NULL, NULL));
            }
        }
        closedir(d);
    }
}

int main(int argc, char* argv[])
{
    assert(argc > 1);

    headers = init_list();
    impls = init_list();

    find_members(argv[1]);

    printf("Número de headers: %d\n", headers->length);
    printf("Número de implementações: %d\n", impls->length);

    return 0;
}