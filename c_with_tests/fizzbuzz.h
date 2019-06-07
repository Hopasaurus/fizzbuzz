
void fizzBuzz(char* destination, int value) {
    if (value % 3 == 0) {
        if (value % 5 == 0) {
            sprintf(destination, "FizzBuzz");
        } else {
            sprintf(destination, "Fizz");
        }
    } else if (value % 5 == 0) {
        sprintf(destination, "Buzz");
    } else {
        sprintf(destination, "%d", value);
    }
}

void fizzBuzzRange(char* destination, int start, int end) {
    destination[0] = 0;
    char foo[200];
    for(int i = start; i <= end; ++i) {
        //fizzBuzz(destination + strlen(destination), i);
        fizzBuzz(foo, i);
        strcat(destination, foo);
        strcat(destination, "\n");
    }
}

