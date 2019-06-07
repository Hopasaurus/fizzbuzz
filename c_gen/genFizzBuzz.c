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
            printf("\tprint \"");
            fizzBuzz(n, destination);

            printf("%s", destination);
            printf("\\n\";\n");

        }
        // footer
        printf("\n");
    }
}
