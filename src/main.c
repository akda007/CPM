#include <glib-2.0/glib.h>
#include "argsparser/parser.h"
#include "src/filetracker/tracker.h"

int main(int argc, char* argv[])
{
    // return action(argc, argv);

    assert(argc > 1);

    LinkedList *headers, *impls;
    headers = init_list();
    impls = init_list();

    find_members(argv[1]);

    printf("Número de headers: %d\n", headers->length);
    printf("Número de implementações: %d\n", impls->length);

    return 0;
}