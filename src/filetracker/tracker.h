#ifndef TRACKER_H
#define TRACKER_H

    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <assert.h>
    #include <dirent.h>

    typedef struct dirent dirent;

    void list_files(char* origin);

#endif