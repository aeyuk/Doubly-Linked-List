# Doubly-Linked-List

## Description
This program builds a doubly-linked list class implemented in C++.

## Operations
The class dList supports the following operations:

Function call       | Description
------------------- | -------------------
dList()        | Default constructor. Should create an empty list.
void addFront(int, char)        | Creates a new node at the front of the list.
void addBack(int, char) | Creates a new node at the back of the list.
node *search(int) | Searches the list for the occurrence of the int parameter in the list and returns a pointer to the node containing that key.
void find(char)| Outputs all keys that have the type equal to the character parameter. Should start at the front of the list and output the keys in list order.
void moveFront(node *) | Moves the node pointed to by the parameter to the front of the list.
void moveBack(node *) | Moves the node pointed to by the parameter to the back of the list.
void out(int, char = ‘f’) | Outputs the first k elements of the list, where k is the int parameter. The char parameter can be either ‘f’ or ‘b’. ‘f’ is the default value. If the char is ‘f’ the output starts at the front of the list. If the char is ‘b’, start at the end of the list and work backwards.
void sort() | Should perform a O(n lg n) time sorting algorithm on the items in the list. The list should be in increasing order based on the integer key after this operation.

## Downloading and Compiling
Clone the repository from terminal, or download the zip and extrac the files.
```bash
git clone https://github.com/aeyuk/Doubly-Linked-List.git
```

Build the project using `make` and execute using `./dList`
