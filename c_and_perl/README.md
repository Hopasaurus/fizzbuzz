Warning, do not try this in production code.

Also it was fun but probably can't be taken much further without getting even more creative.

Have fun!


Run the Perl version:

`perl fizzbuzz.c`

Run the C version:

`gcc -o fizzbuzz fizzbuzz.c && ./fizzbuzz`



And a final note, Perl is faster than C... proof:

```
bash-3.2$ time gcc -o fizzbuzz fizzbuzz.c && ./fizzbuzz > c_ouput.txt

real    0m0.074s
user    0m0.044s
sys     0m0.024s




bash-3.2$ time perl fizzbuzz.pl > pl_output.txt

real    0m0.022s
user    0m0.013s
sys     0m0.006s



bash-3.2$ diff c_ouput.txt pl_output.txt
bash-3.2$

(no output as there are no differences)
```

