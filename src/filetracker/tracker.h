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

    void list_files(char* origin);
    int call_tracker(char* origin_path);

#endif