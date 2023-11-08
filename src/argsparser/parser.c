#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "args.h"

//Docs -> http://www.dmulholl.com/docs/args/master/

Config config;

int callbackFunctions(char *cmd_name, ArgParser *cmd_parser) {
     

     
    if (strcmp(cmd_name, "build") == 0) {
        config.build();
        
        return 0;
    }

    if (strcmp(cmd_name, "init") == 0) {
        config.init();
        
        return 0;
    }

    if (strcmp(cmd_name, "run") == 0) {
        config.run();
        
        return 0;
    }

    return 0;
}

void setConfig(Config cfg) {
    config = cfg;
}

void parseArgs(int argc, char ** argv) {
    
    ArgParser *parser = ap_new_parser();

    if (!parser) {
        exit(2);
    }

    ap_set_helptext(parser, "Usage: cpm [options]");
    ap_set_version(parser, "1.0");

    ArgParser *cmd_init = ap_new_cmd(parser, "init");
    ArgParser *cmd_build = ap_new_cmd(parser, "build");
    ArgParser *cmd_run = ap_new_cmd(parser, "run");

    ap_set_helptext(cmd_init, INIT_HELPTEXT);
    ap_set_helptext(cmd_init, BUILD_HELPTEXT);
    ap_set_helptext(cmd_init, RUN_HELPTEXT);

    ap_set_cmd_callback(cmd_init, callbackFunctions);
    ap_set_cmd_callback(cmd_build, callbackFunctions);
    ap_set_cmd_callback(cmd_run, callbackFunctions);

    if (!ap_parse(parser, argc, argv) ) {
        exit(2);
    }

    // ap_print(parser);

    ap_free(parser);
}

// int print_teste(char *cmd_name, ArgParser* cmd_parser) {
//     puts("Teste-----");
//     ap_print(cmd_parser);
//     puts("----");

//     char *text = ap_get_str_value(cmd_parser, "str");
//     printf("STRING; %s\n", text);

//     return 0;
// }

// int action(int argc, char** argv) {
//     // Instantiate a new ArgParser instance.
//     ArgParser* parser = ap_new_parser();
//     if (!parser) {
//         exit(1);
//     }

//     // Register the program's helptext and version number.
//     ap_set_helptext(parser, "Usage: Work in progress...");
//     ap_set_version(parser, "1.0");

//     ArgParser* cmd_parser = ap_new_cmd(parser, "teste");
//     if (!cmd_parser) {
//         exit(1);
//     }

//     ap_set_helptext(cmd_parser, "Usage: teste [args].....");
//     ap_add_str_opt(cmd_parser, "str s", "default");
//     ap_add_flag(cmd_parser, "xx x");

//     ap_set_cmd_callback(cmd_parser, print_teste);

//     // Parse the command line arguments.
//     if (!ap_parse(parser, argc, argv)) {
//         exit(1);
//     }

//     // This debugging function prints the parser's state.
//     ap_print(parser);

//     // Free the parser's memory.
//     ap_free(parser);
// }