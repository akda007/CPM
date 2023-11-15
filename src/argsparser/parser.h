#ifndef PARSER_H
#define PARSER_H

#include "args.h"

#define MAIN_HELPTEXT "Usage: cpm [option] (args...)\n\n" \
                      "Options\n" \
                      "\tinit\n" \
                      "\tbuild\n" \
                      "\trun\n\n" \
                      "Args: \n" \
                      "\t-h, --help: Show option help text."

#define INIT_HELPTEXT "Usage: cpm init (args...)\n\n" \
                      "Args:\n" \
                      "\t-p, --project-name:\t\t Sets the project name(default: project)\n" \
                      "\t-m, --make-program:\t\t Sets the make executable name(default: make)\n" \
                      "\t-e, --extension:   \t\t Sets the executable extension(default: exe)\n" \
                      "\t--no-git:          \t\t Dont initilizes a git repository"

#define RUN_HELPTEXT "Usage: cpm run\n" \
                     "\tRuns the project, and builds\n"\
                     "\tit if the executable dont exists."

#define BUILD_HELPTEXT "Usage: cpm build\n" \
                       "\tBuild the project and creates\n"\
                       "\tthe Makefile if it does'nt exists."

typedef int (*argscallback_t)(ArgParser *parser);

 typedef struct {
    argscallback_t init;
    argscallback_t build;
    argscallback_t run;    
 } Config;


 void setConfig(Config cfg);
 void parseArgs(int argc, char ** argv);

#endif