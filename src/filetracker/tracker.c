#include "tracker.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dirent.h>
#include <sys/stat.h>
#include "linked_list/linked_list.h"

LinkedList *headers, *impls;
char *target, *make_path, *extension;

void print_dirent(void *dir)
{
    printf("Filename: %s\n", ((struct dirent *)dir)->d_name);
}

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

    fprintf(fp, "[config]\n");
    fprintf(fp, "target=%s\n", target);
    fprintf(fp, "make=%s\n", make_path);
    fprintf(fp, "extension=.%s\n", extension);

    fprintf(fp, "\n[header]\n");
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

//Remove some special chars and spaces from string
void sanitize_string(char *buffer, const char * custom_chars) {
    char chars[300];
    strcpy(chars, custom_chars);
    strcat(chars, "\n\r ");

    for (char * i = buffer; *i != '\0'; i++) {
        if (strchr(chars, *i)){
            for (char * c = i; *c != '\0'; c++) {
                *c = *(c+1);
            }
            i--;
        }
    }
}

char* retrieve_config(const char* section, const char *setting)
{
    FILE *members_file = fopen(SAVE_FILE, "r");

    char buff[200], name[100], value[100];

    //Find section
    bool found = false;
    while(fgets(buff, sizeof(buff), members_file) != NULL) {
        sanitize_string(buff, "[]");
        if (strcmp(buff, section) == 0) {
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Unable to find the %s section in the members file.\n", section);
        return NULL;
    }

    found = false;

    while(fgets(buff, sizeof(buff), members_file) != NULL) {
        sanitize_string(buff, "");

        for (char *i = buff; *i != '\0'; i++) {
            if (*i == '=')
                *i = '\n';
        }

        sscanf(buff, "%s\n%s", name, value);        

        if (strcmp(name, setting) == 0) {
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Unable to find the %s setting in the members file.\n", setting);
        return NULL;
    }

    //Needs to be dealocated later
    return strdup(value);
}

int call_tracker(char* origin_path, char* target_name, char* makepath_name, char *ext_extension)
{
    headers = init_list();
    impls = init_list();

    target = target_name;
    make_path = makepath_name;
    extension = ext_extension;

    find_members(origin_path, "");
    make_members(origin_path);

    free_list(headers);
    free_list(impls);

    return 0;
}