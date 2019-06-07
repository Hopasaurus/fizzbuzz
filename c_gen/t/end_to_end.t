#!/usr/bin/env perl

use strict;
use warnings;

use File::Slurp;
use JSON;

my $commandFile = './t/test_commands.json';
my $commandFileText = read_file($commandFile);
my $commands = decode_json $commandFileText;

my $commandCount = scalar @{$commands};
print "1..$commandCount\n";

#build gen fizz buzz:
`gcc -o genFizzBuzz genFizzBuzz.c`;

for my $item (@{$commands}) {
    `./genFizzBuzz $item->{language} > fb.$item->{language}`;
    `$item->{build}` if defined $item->{build};
    `$item->{run} | cmp t/FizzBuzz_golden.txt -`;
    my $returnCode = $?;
    `rm fb.$item->{language}`;
    `$item->{cleanup}` if defined $item->{cleanup};
    my $r = $returnCode == 0 ? "ok" : "not ok";

    # language can't be a number or it will break tap
    print "$r - $item->{language} produces valid output\n";
}

`rm genFizzBuzz`;
