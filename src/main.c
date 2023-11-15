#include <glib-2.0/glib.h>
#include <stdio.h>

#include "argsparser/parser.h"
#include "filetracker/tracker.h"
#include "workingdirectory/directory.h"
#include "tools/tools.h"

char buffer[1024];

int init(ArgParser *parser) {
    // ap_print(parser);


    if(containsFile(buffer, SAVE_FILE)) {
        printf("The project was already initialized!\n");
        return -1;
    }

    char *name = ap_get_str_value(parser, "p");
    char *make = ap_get_str_value(parser, "m");
    char *ext =  ap_get_str_value(parser, "e");

    printf("Initializing %s...\n", name);
    int ret = call_tracker(buffer, name, make, ext);

    //Todo save config inside the repo

    if (!ap_found(parser, "no-git")) {
        gitInit(buffer);
    }

    return ret;
};


int build(ArgParser *parser) {
    if(!containsFile(buffer, SAVE_FILE)) {
        printf("Project not found!\n");
        return -1;
    }

    printf("Build started!\n");

    char buffer[1024];
    getDirectory(buffer, sizeof(buffer));

    if(containsFile(buffer, "Makefile")) {

    } else {
        createMakefile(buffer);
    }

    char * make = retrieve_config("config", "make");
    // printf("Found config %s\n",make);
    int exit_code = system(make);

    free(make);

    if (exit_code != 0){
        return -1;
    }

    printf("\nBuild process completed!\n\n");
    return 0;
};

int run(ArgParser *parser) {
    char *target = retrieve_config("config", "target");
    char *extension = retrieve_config("config", "extension");

    target = realloc(target, strlen(target) + strlen(extension) + 1);

    strcat(target, extension);

    free(extension);

    if (!containsFile(buffer, target)) {
        if(build(parser) == -1){
            printf("Unable to run the project\n");
            free(target);
            return -1;
        }
    }

    if (!containsFile(buffer, target)) {
        printf("%s: Program not found!\n", target);
        free(target);
        return -1;
    }

    printf("Running the program now...\n\n\n");

    int exit_code = system(target);

    printf("\n\n(Program exited with the code %d)...\n", exit_code);

    free(target);
    return 0;
};


int main(int argc, char* argv[])
{
    // printf("build: 0x%x\n", build);
    // printf("init: 0x%x\n", init);
    // printf("run: 0x%x\n", run);
    getDirectory(buffer, sizeof(buffer));


    Config cfg;

    cfg.build = build;
    cfg.init = init;
    cfg.run = run;
    
    setConfig(cfg);
    parseArgs(argc, argv);

    return 0;
    
}