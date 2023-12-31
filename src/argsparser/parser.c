#include <stdio.h>
#include <stdlib.h>
#include "args.h"

//Docs -> http://www.dmulholl.com/docs/args/master/

int action(int argc, char** argv) {
    // Instantiate a new ArgParser instance.
    ArgParser* parser = ap_new_parser();
    if (!parser) {
        exit(1);
    }

    printf("teste");

    // Register the program's helptext and version number.
    ap_set_helptext(parser, "Usage: Work in progress...");
    ap_set_version(parser, "1.0");

    // Register a flag and a string-valued option.
    ap_add_flag(parser, "a");
    ap_add_str_opt(parser, "b", "default");

    // Parse the command line arguments.
    if (!ap_parse(parser, argc, argv)) {
        exit(1);
    }

    // This debugging function prints the parser's state.
    ap_print(parser);

    // Free the parser's memory.
    ap_free(parser);
}