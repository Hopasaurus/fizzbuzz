#include <stdio.h>
#include <string.h>

void fizzBuzz(int n, char* destination) {
    if (n % 3 == 0 && n % 5 == 0) {
        sprintf(destination, "FizzBuzz");
    } else if (n % 3 == 0) {
        sprintf(destination, "Fizz");
    } else if (n % 5 == 0) {
        sprintf(destination, "Buzz");
    } else {
        sprintf(destination, "%d", n);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("please specify destination language, one of: c, perl, c#, c++, bash, python\n");
        return 0;
    }

    if (!strcmp("c", argv[1])) {
        // header
        printf("#include <stdio.h>\nint main() {\n");
        
        char destination[100];
        for(int n=1; n <= 100; ++n) {
            // right now we cheat pretty hard, we don't put the business logic of fizz buzz in the generated code
            // most of the initial point is to get a test framework up and running establishing an interface
            // later we can use the L in SOLID and re-implement this in a different way and still end up with a test around this.
            printf("\tprintf(\"");
            fizzBuzz(n, destination);

            printf("%s", destination);
            printf("\\n\");\n");

        }
        // footer
        printf("}\n");
    }

    if (!strcmp("perl", argv[1])) {
        // header
        printf("#!/usr/bin/env perl\n\n");
        
        char destination[100];
        for(int n=1; n <= 100; ++n) {
            fizzBuzz(n, destination);
            printf("\tprint \"%s\\n\";\n", destination);
        }
        // footer
        printf("\n");
    }

    if (!strcmp("basic", argv[1])) {
        char destination[100];
        for(int n=1; n <= 100; ++n) {
            fizzBuzz(n, destination);
            printf("%d print \"%s\"\n", n * 10, destination);
        }
        // footer
        printf("\n");
    }
}
