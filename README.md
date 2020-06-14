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
- [x] Integers types
- [x] Float types
- [x] C strings
- [x] Custom datatype (ex. struct)

### Example
1) List of int
```c
int compare_int(void *a, void *b){
    int *pa = a;
    int *pb = b;

    return *pa - *pb;
}
```
```c
struct node *list = NULL;
int count = 10;
list = insert_all(list, sizeof(int), count, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1);

int *max = max_list(list, compare_int);
int *min = min_list(list, compare_int);
delete(list);
```
Result
```c
list = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ];
max = 10
min = 1
```

2) List of C strings
```c
int compare_cstrings(void *a, void *b){
    char *pa = a;
    char *pb = b;

    return strcmp(pa, pb);
}
```
```c
struct node *list = NULL;

char *data[] = {
    "gatto", "cane", "cavallo", "formica"
}

list = insert_head(list, data[0], 1 + sizeof data[0]);
list = insert_head(list, data[1], 1 + sizeof data[1]);
list = insert_head(list, data[2], 1 + sizeof data[2]);
list = insert_head(list, data[3], 1 + sizeof data[3]);

int *max = max_list(list, compare_cstrings);
int *min = min_list(list, compare_cstrings);
delete(list);
```
Result
```c
list = [ "gatto", "cane", "cavallo", "formica" ];
max = "gatto"
min = "cane"
```

