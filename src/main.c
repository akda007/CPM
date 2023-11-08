#include <glib-2.0/glib.h>
#include "argsparser/parser.h"

#include <stdio.h>

int init() {
    printf("Init called");

    return 0;
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

    return 0;
}