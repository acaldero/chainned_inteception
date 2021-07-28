# Chainned Interception
Proof-of-concept example

## Files
 * **i-1.c**: intercepts malloc and print a message before and after execute with "i-1" as prefix
 * **i-2.c**: same as i-1.c, the only difference is it prints the prefix "i-2"
 * **main.c**: calls malloc (without knowning is going to be intercepted).

## Compilation
```bash
 gcc -Wall -g -shared -fPIC -o i-1.so i-1.c -ldl
 gcc -Wall -g -shared -fPIC -o i-2.so i-2.c -ldl
 gcc -Wall -g -o main -c main.c
```

## Execution
```bash
 LD_PRELOAD=./i-2.so:./i-1.so ./main
```

## Results
```bash
acaldero@desktop:~/work/chainned_interception$ ./compile.sh
+ gcc -Wall -g -shared -fPIC -o i-1.so i-1.c -ldl
+ gcc -Wall -g -shared -fPIC -o i-2.so i-2.c -ldl
+ gcc -Wall -g -o main.o -c main.c
+ gcc -Wall -g -o main main.o
+ LD_PRELOAD=./i-2.so:./i-1.so ./main
main: before malloc(10)...
i-2: before malloc(10)...
i-1: before malloc(10)...
i-1:  after malloc(10) = 0x55882c2932a0
i-2:  after malloc(10) = 0x55882c2932a0
main: after malloc(10) = 0x55882c2932a0
```
