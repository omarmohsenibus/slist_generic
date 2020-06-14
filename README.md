# slist_generic
Implementation of single linked list generic in c



this is the [documentation](https://omarmohsenibus.github.io/slist_generic/index.html) of the data structure. 


### Container
This is the basic element of the list called node.This node contains the data that can be any type of data and the reference to the next node. 
```c
struct node {
	void *data;
	struct node *next;
};
```
### Type of data supported
[x] Integers types
[x] Float types
[x] C strings
[x] Custom datatype (ex. struct)

### Example
