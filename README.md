# slist_generic
Implementation of single linked list generic in c

### Container
This is the basic element of the list called node.This node contains the data that can be any type of data and the reference to the next node. 
```c
struct node {
	void *data;
	struct node *next;
};
```

### Type of data supported
:heavy_check_mark: Integers types
:heavy_check_mark: Float types
:heavy_check_mark: C strings
:heavy_check_mark: Custom datatype (ex. struct)

