#include "tools.h"

#include <dirent.h>
#include <stdio.h>


bool containsFile(char * dir, const char * file) {
    DIR *wdir = opendir(dir);
    struct dirent * d;

    if (!wdir) {
        printf("Unable to open directory!");
        return false;
    }

    while ((d = readdir(wdir)) != NULL) {
        if (strcmp(file, d->d_name) == 0) {
            return true;
        }
    }

    return false;
}

