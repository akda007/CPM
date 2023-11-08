#ifndef PARSER_H
#define PARSER_H

#define INIT_HELPTEXT "Usage: init"
#define RUN_HELPTEXT "Usage: run"
#define BUILD_HELPTEXT "Usage: build"

typedef int (*argscallback_t)();

 typedef struct {
    argscallback_t init;
    argscallback_t build;
    argscallback_t run;    
 } Config;


 void setConfig(Config cfg);
 void parseArgs(int argc, char ** argv);

#endif