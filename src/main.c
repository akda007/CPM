#include <glib-2.0/glib.h>
#include <stdio.h>

#include "argsparser/parser.h"
#include "filetracker/tracker.h"
#include "workingdirectory/directory.h"
#include "dirtools/tools.h"

int init() {
    char buffer[1024];
    getDirectory(buffer, sizeof(buffer));

    if(containsFile(buffer, "MEMBERS")) {
        printf("The directory was already initialized!\n");
        return -1;
    }

    int ret = call_tracker(buffer);

    gitInit(buffer);

    return ret;
};

int build() {
    printf("Build called");

    return 0;
};

int run() {
    printf("Run called");

    return 0;
};


int main(int argc, char* argv[])
{
    // printf("build: 0x%x\n", build);
    // printf("init: 0x%x\n", init);
    // printf("run: 0x%x\n", run);


    Config cfg;

    cfg.build = build;
    cfg.init = init;
    cfg.run = run;
    
    setConfig(cfg);
    parseArgs(argc, argv);

    
    
    // return action(argc, argv);
    // call_tracker(argv[1]);



    return 0;
    
}