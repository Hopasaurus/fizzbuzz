#include <stdio.h>
#include <string.h>

#include "test.h"
#include "fizzbuzz.h"

int main() {

    //test_the_tests();

    // 700 should be enough...but lets be safe we got lots o memory.
    char destination[65535];

    // (char*, int) fills in a single value

    fizzBuzz(destination, 1);
    str_equal(destination, "1", "Given 1 put '1' into the destination");

    fizzBuzz(destination, 3);
    str_equal(destination, "Fizz", "Given 3 put 'Fizz' into the destination");

    fizzBuzz(destination, 5);
    str_equal(destination, "Buzz", "Given 5 put 'Buzz' into the destination");

    fizzBuzz(destination, 15);
    str_equal(destination, "FizzBuzz", "Given 15 put 'FizzBuzz' into the destination");


    // (char*, int, int) fills in a range of values
    fizzBuzzRange(destination, 1, 20);
    str_equal(destination,
              "1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\nFizzBuzz\n16\n17\nFizz\n19\nBuzz\n",
              "1-20 should 'Do The Right Thing(r)' ;-) ");
    


    return summary();
}


