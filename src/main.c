// TODO
// - check memory allocations for leaks

#define REPL_ENABLED // Comment this out to disable the repl
#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>

#include "parse.h"
#include "rational.h"

struct Parser create_parser(char* filename);

#ifdef REPL_ENABLED
void repl() {
    char buffer[BUFFER_SIZE];

    int go_on = 1;
    while (go_on) {
        printf("REAL: ");

        if (!fgets(buffer, BUFFER_SIZE, stdin)) {
            printf("Error while reading from stdin.\n");
        }

        if (buffer[0] == '\n') {
            go_on = 0;
            break;
        }

        struct Expr* expr = parse_from_str(buffer);
        print_expr(expr);
        destroy_expr(expr);
        printf("\n\n");
    }

    free(buffer);
}
#endif

void interpret_file(char* file_name) {
    printf("%s\n", file_name);
    struct Expr* expr = parse_from_file(file_name);
    print_expr(expr);
    destroy_expr(expr);
}

// If called with a file, run it, else start a REPL
int main(int argc, char *argv[]) {
    printf("----------\nRealScript\n----------\n\n");
    if (argc > 1) {
        // There is at least one parameter
        // interpret_file(argv[1]);

        // string_to_alint("283,756,238,567") should give back 231 150 48 17 66
        // struct Alint* alint1 = string_to_alint("308023895");
        struct Alint* alint1 = string_to_alint("22123895");
        // struct Alint* alint1 = string_to_alint("256");
        // struct Alint* alint2 = string_to_alint("350108375");
        struct Alint* alint2 = string_to_alint("4765");
        // debug_print_alint(alint1);
        debug_print_alint(div_alint(alint1, alint2)); // should give 64643
    } else {
        #ifdef REPL_ENABLED
        // There are no arguments, start a REPL
        repl();
        #else
        printf("Error: no filename provided.\n");
        #endif
    }
    return 0;
}

