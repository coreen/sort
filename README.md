Run Instructions
----------------
1) Link the tableFill.c file with the sorting algorithm you wish to test
```
> gcc tableFill.c selection.c
```
2) There should now be an a.out file generated as the linked executable
```
> ls
a.out
tableFill.c
selection.c
```
3) Run the executable and follow the command prompt to see the sort in action
```
> ./a.out 
please enter size of the array you want: 5

please enter an integer value to put into an array: 3
please enter an integer value to put into an array: 1
please enter an integer value to put into an array: 0
please enter an integer value to put into an array: 5
please enter an integer value to put into an array: 8

array before selection sort: 
3 1 0 5 8 
array after selection sort: 
0 1 3 5 8
```
4) Remove a.out and relink to see the next sort algorithm
```
> rm a.out
```
