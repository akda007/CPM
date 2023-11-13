#include "tracker.h"

LinkedList *headers, *impls;

void print_dirent(void *dir)
{
    printf("Filename: %s\n", ((struct dirent *)dir)->d_name);
}

// bool is_directory(struct dirent* dir)
// {
//     DIR* d = opendir(dir->d_name);
//     return ((dir = readdir(d)) != NULL);
// }

int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0)
        return 0;

    return S_ISDIR(statbuf.st_mode);
}

bool check_extension(char* filename, char* extension)
{
    char *ext = strrchr(filename, '.');
    return (ext != NULL) ? (strcmp(ext, extension) == 0) : false;
}

void find_members(char* origin, char* location)
{
    DIR* d = opendir(origin);
    struct dirent* dir;

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            char absolute_path[256] = "";
            strcpy(absolute_path, origin);
            strcat(absolute_path, "\\");
            strcat(absolute_path, dir->d_name);

            if (is_directory(absolute_path) == 1 && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
            {
                find_members(absolute_path, dir->d_name);
            }
            else
            {
                struct dirent * copy = malloc(sizeof(struct dirent));
                *copy = *dir;

                if (strcmp(location, "") != 0)
                {
                    char relative_path[256] = "";
                    strcpy(relative_path, location);
                    strcat(relative_path, "\\");
                    strcat(relative_path, dir->d_name);

                    strcpy(copy->d_name, relative_path);
                }

                if (check_extension(dir->d_name, ".h"))
                {
                    append_list(headers, init_node(copy, print_dirent, NULL));
                }
                else if (check_extension(dir->d_name, ".c"))
                {
                    append_list(impls, init_node(copy, print_dirent, NULL));
                }
            }

        }
        closedir(d);
    }
}

void make_members(char* origin)
{
    char* members_path = strcat(origin, "\\MEMBERS");
    FILE *fp = fopen(members_path, "w+");
    struct dirent* dir;

    fprintf(fp, "[header]\n");
    for (int i = 0; i < headers->length; i++)
    {
        dir = (struct dirent*)fetch_index_list(headers, i);
        fprintf(fp, "%s\n", dir->d_name);
    }

    fprintf(fp, "\n[impl]\n");
    for (int i = 0; i < impls->length; i++)
    {
        dir = (struct dirent*)fetch_index_list(impls, i);
        fprintf(fp, "%s\n", dir->d_name);
    }
}

int call_tracker(char* origin_path)
{
    headers = init_list();
    impls = init_list();

    find_members(origin_path, "");
    make_members(origin_path);

    free_list(headers);
    free_list(impls);

    return 0;
}