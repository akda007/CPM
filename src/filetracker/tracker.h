#ifndef TRACKER_H
#define TRACKER_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <assert.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include "linked_list/linked_list.h"

    void print_dirent(void *dir);
    int is_directory(const char *path);
    bool check_extension(char* filename, char* extension);
    void find_members(char* origin, char* location);
    void make_members(char* origin);
    int call_tracker(char* origin_path);

#endif