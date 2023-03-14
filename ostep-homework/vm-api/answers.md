## Chapter 15 answers

### Question 1
Segmentation fault (core dumped)

### Question 2
Program received signal SIGSEGV, Segmentation fault.
0x000055555555519f in main () at null.c:9
9	    printf("%d", *p);

### Question 3
Invalid read of size 4
at 0x10919F: main (null.c:9)
Address 0x0 is not stack'd, malloc'd or (recently) free'd

### Question 4
gdb: no error
valgrind: informs as memory leak, corresponds with 10 * int = 10 * 4 = 40 bytes

### Question 5
Valgrind: invalid write of size 4, as well as memory leak error
Program is not correct as int array of size 100 is of length 25 ints. Unsure why it did not raise an error.

### Question 6
Valgrind: invalid read of size 4, interesting that it tells you which line it was alloc'ed then free'd.

### Question 7
I'm not allowed to assign a pointer to an int array. Compiler raises this error at compile time.

### Question 8






