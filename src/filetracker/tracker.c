#include "tracker.h"

struct dirent *header_list, *impl_list;
unsigned header_len = 1, impl_len = 1;

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
            if (is_directory(dir))
            {
                // find_members(dir->d_name);
            }
            else
            {
                printf("Achei: %s\n", dir->d_name);

                if (check_extension(dir->d_name, ".h"))
                {
                    header_len++;
                    header_list = realloc(header_list, header_len * sizeof(struct dirent));
                    header_list[header_len] = *dir;
                }
                else if (check_extension(dir->d_name, ".c"))
                {
                    impl_len++;
                    impl_list = realloc(impl_list, impl_len * sizeof(struct dirent));
                    impl_list[impl_len] = *dir;
                }
            }
        }
        closedir(d);
    }
}

int main(int argc, char* argv[])
{
    assert(argc > 1);

    header_list = malloc(sizeof(struct dirent));
    impl_list = malloc(sizeof(struct dirent));

    printf("Ola mundo\n");

    find_members(argv[1]);

    printf("Ola mundo 2\n");

    printf("Número de headers: %d\n", header_len);
    printf("Número de implementações: %d\n", impl_len);

    for (int i = 0; i < header_len; i++)
    {
        printf("%s\n", header_list[i].d_name);
    }

    for (int i = 0; i < impl_len; i++)
    {
        printf("%s\n", impl_list[i].d_name);
    }

    return 0;
}