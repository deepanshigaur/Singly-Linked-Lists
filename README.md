# HW01 - Singly Linked Lists

## Assignment Goals

This assignment expands on your understanding of the abstract view of the C language. We will again use the abstract data type concepts we covered in HW01, but add a linked list data structure. This will highlight the following concepts:

- Use of pointers, especially pointers to structures
- Object oriented C programming (even though C is not an object oriented language)
- A linked list data structure
- Using "assert" to ensure program correctness

These concepts are used in an implementation of a singly linked list. I have provided you with most of the code you will need, including all the functions required to manipulate a single node of the list, as well as most of the functions to manipulate the list itself, and a main function to try out the list.

## Basic Concepts: Singly Linked Lists

A linked list is a data structure that consists of zero or more nodes. A linked list with zero nodes is an *empty* list. Each node in the list carries some information, known as the *payload*. For the purposes of this assignment, the payload will consist of a single integer.

Each node in the linked list points to the next node in the list. For each non-empty list, there is at least one node that is considered the *head* of the list. That node is the node that no other nodes point to. Each list also has a node called the *tail* node of the list. A tail node is a node which points to no other nodes in the list; whose `next` pointer points to `NULL`.

For a list to be valid, the next pointer of each node in the list must point to a node which is not already in the list. In other words, there can be no circles in the list.

A list is a singly linked list if each node has a single pointer to it's next node. Doubly linked lists have pointers both to the next node in the list and to the previous node in the list.

In this assignment, we will keep track of a list by keeping a pointer to the head node of the list. If the pointer to the head node of the list is NULL, the list is empty. Otherwise, the list consists of the node at the head, plus the node that the head's next pointer points to, and so on, until we reach the tail node, whose next pointer is NULL.

It's important to remember that a *list* is a pointer to a *node*, and a *node* is a pointer to a structure that contains a payload and a next pointer. Therefore, a list is really a *pointer to a pointer*! This double indirection is important because it allows us to change the head of the list even though C uses pass-by-copy to pass in parameters to a function. We'll learn more about this later.

## Provided Code

There are several files in this repository already, as follows:

### node.h and node.c

The header file, node.h contains everything you need to use node functions. The node.c file contains the implementation of these functions. The actual implementation of these functions is not terribly important. They all work and work correctly, and you should not edit either the node.h or node.c files.

From an abstract point of view, you can think of a node containing two fields: a payload (an integer value in this case), and a pointer to a "next" node.

Read through node.h and node.c to get familiar with what you can do with a node.

### list.h and list.c

The header file, list.h, contains everything you need to use list functions. The list.c file contains the implementation of these functions. Most of these functions are already provided for you, but you will need to code the `list_insertTail` and `list_insertOrder` function.

Read through list.h and list.c to see what is already provided for you.

Note that functions which loop through a list invoke the `list_valid` function in an assert just to ensure there are no loops in the list. If there are loops in the list, any function which loops through the list will run in an endless loop. That happens often enough, especially when you are debugging complex insert functions, so it's useful to double check.

There is one exception to the use of `list_valid` to check for loops in the list, and that's in the `list_size` function. The `list_valid` function needs to invoke the `list_size` function, so there is a special check in the `list_size` function that limits the size of our linked lists to 1000 - a reasonable limit for this assignment.

### tryList.c

The tryList.c file contains a main function. The main function creates three lists: list1, list2, and list3. Then, reads each command line argument, converts that argument from a character string to an integer value, and inserts that value into all three lists; list1 using `list_insertStart`, list2 using `list_insertEnd`, which you will need to code, and list3 using `list_insertOrder` which you will also need to code. Then it prints each list, and frees each list.

### Makefile

I have provided a Makefile that defines Make variables for the C compiler (CC) and C flags (CFLAGS) to be used for this assignment (and this course.) I have included five explicit make rules:

- `test` : has a dependency on the tryList file, and runs the tryList executable, passing in some command line arguments.
- `gdb` : Runs gdb using the same arguments as `test`.
- `checkMem` : Runs valgrind on tryList using the same arguments as `test`
- `tryList` : Defines how to build the tryList executable file.
- `clean` : removes all the extra files created by the Makefile

## Doing the Assignment

1. Clone the repository on a UNIX machine. See [How to Use GitHub](https://www.cs.binghamton.edu/~tbartens/HowTo/Using_GitHub) for details on cloning, etc.
2. Read through the existing code as well as the explanations in this README file to understand the infrastructure. You can try compiling and running the code, but until you code the `list_insertEnd` and `list_insertOrder` functions, list2 and list3 will be empty.
3. Edit the list.c file to complete the `list_insertEnd` and `list_insertOrder` functions. There are some suggestions on an algorithm to use for these functions in the comments in the list.c file.
4. Build and test the result using the make command. If you code the functions correctly, list2 should get printed in the command line order, and list3 should get printed in numeric order from the lowest payload value at the head of the list to the highest payload value at the tail. If your code is not working correctly, try using gdb to stop your code where it is failing, and step through the code a line at a time to see what is going wrong. See [How to Use GDB](http://www.cs.binghamton.edu/~tbartens/HowTo/Using_gdb) for more on debugging with gdb.
5. Once your code is working, commit and push your results into your master git repository, and get the hash code using `git rev-parse HEAD`. Paste that hash code into the submission area for hw02 in Brightspace.

If you get stuck, and can't figure out how to make progress on this assignment, please contact either the professor or one of the TA's during office hours, or via e-mail. The main purpose of this assignment is to see where there are problems or areas that need more attention... not to make you frustrated, so please let us know if you are confused or can't get something to work.

## Assignment Grading

This homework assignment is worth 10 points. You will get the full 10 points if the TA's can download your repository using the git hash code from Brightspace onto a computer science machine, replace tryList.c, list.h, node.c, node.h, and the Makefile with the original versions of those files, and run `make test`, and get the correct results for list1, list2, and list3. You will receive the following deductions:

- -7 if building tryList causes a compile error.
- -2 if building tryList causes a compiler warning
- -5 if list1 does not print correctly.
- -5 if the `list_insertEnd` and/or `list_insertOrder` functions have not been modified.
- -3 if list2 does not print correctly.
- -3 if list3 does not print correctly.
- -2 for every 24 hours (or part of 24 hours) after the submission date.
