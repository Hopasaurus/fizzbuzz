
// ****** this is the test "framework" just enough to get going.
// arrg global state... the worst!!! 
int successCount = 0;
int failCount = 0;

void success(char* message) {
    successCount += 1;
    printf("Pass: %s\n", message);
}

void fail(char* message, char* actual, char* expected) {
    failCount += 1;
    printf("FAIL: %s\n\tExpected:%s\n\tActual: %s\n", message, expected, actual);
}

void int_equal(int actual, int expected, char* message) {
    if(actual == expected) 
        return success(message);
    
    char actualStr[40];
    char expectedStr[40];
    sprintf(actualStr, "%d", actual);
    sprintf(expectedStr, "%d", expected);
    fail(message, actualStr, expectedStr);
}

void str_equal(char* actual, char* expected, char* message) {
    if(strcmp(actual, expected) == 0)
        return success(message);
    fail(message, actual, expected);
}

int summary() {
    printf("Test summary\nPass: %d\nFail: %d\n", successCount, failCount);
    if (failCount == 0) 
        printf("No failures\n");
    else
        printf("!!! Failed tests detected !!!\n");
    printf("================================================\n");
    return failCount;
}

void test_the_tests() {
    int_equal(1, 1, "should pass");
    int_equal(1, 2, "should fail");
    str_equal("hi", "hi", "string compare should pass for identical strings");
    str_equal("hi", "bye", "string compare should fail for non-identical strings");
}

