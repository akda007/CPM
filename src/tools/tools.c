#include "tools.h"

#include <dirent.h>
#include <stdio.h>

bool createMakefile(char * dir) {
    char buff[1024];

    strcpy(buff, dir);
    strcat(buff, "/Makefile");

    FILE *makefile = fopen(buff, "w");

    if (!makefile) {
        printf("Unable open the Makefile");

        return false;
    }

    //print TARGET = {config.target}
    fprintf(makefile, "TARGET = teste.exe\n");

    fprintf(makefile, MAKEFILE_TEXT);

    return true;
}

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

