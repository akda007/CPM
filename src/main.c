#include <glib-2.0/glib.h>
#include "argsparser/parser.h"
#include "src/filetracker/tracker.h"

int main(int argc, char* argv[])
{
    // return action(argc, argv);
    call_tracker(argv[1]);
}