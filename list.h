/**
 * @file list.h
 * @author Omar Mohseni
 * @date 14 Jun 2020
 * @brief File containing the data structure and the declaration of the function that permit to handle single linked list.
 */


#define _CRT_SECURE_NO_WARNINGS
#if !defined LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>


/**
 * @brief Basic node element
 *
 * This struct is the basic element what form a single linked list.It contains the info 
 * field and the reference to the next item of the list.
 */
struct node {
	void *data; /**< This is the info field . */
	struct node *next; /**< This is the reference field . */
};

/**
 * @brief Method of sorting list
 *
 */
enum mode {
	ASC, /**< ascending */
	DESC /**< descending */
};

extern struct node *insert_all(struct node *list, size_t data_size, size_t count, ...);


/**
 * @brief Insert a new node at the head
 *
 * This function allocate a new node in the heap memory.
 * Then it fills the info field with the data passed to the function
 * At the end it links the new node to the previous list and returns the list
 * @param list @p (struct @p node*)  Pointer to a struct node that rappresent the list
 * @param data @p (void*) Pointer to a void that point to an area of heap memory that contains the data to insert
 * @param data_size @p (size_t) size of data
 * @return 
 * - @p (struct @p node*) Pointer to the head of the list
 * @note When you use C strings add the terminator in the count of the data_size
 * @code{.c} 
 * char name[] = "Luca";
 * struct node *list = insert_head(list, name, 1 + strlen(name));
 * @endcode
 * @warning Always return the result of the function to the list pointer because you lose the reference to that area of memory.
 */
extern struct node *insert_head(struct node *list, const void *data, size_t data_size);
extern struct node *insert_tail(struct node *list, const void *data);
extern struct node *insert_at(int index, struct node *list, const void *data, size_t data_size);

extern struct node *insert_from_bin_file(char *filename);

extern struct node *update_at(int index, struct node *list, const void *data, size_t data_size);

/**
 * @brief delete all list elements
 * 
 * This function deletes all list elements  
 * @param list @p (struct @p node*)  Pointer to a struct node that rappresent the list
 * */
extern void delete(struct node *list);
/**
 * @brief delete head
 * 
 * This function deletes the head of the list  
 * @param list @p (struct @p node*)  Pointer to a struct node that rappresent the list
 * */
extern void delete_head(struct node *list);
/**
 * @brief delete tail
 * 
 * This function deletes the tail of the list  
 * @param list @p (struct @p node*)  Pointer to a struct node that rappresent the list
 * */
extern void delete_tail(struct node *list);
/**
 * @brief delete at the position
 * 
 * This function deletes the node that it's at @param index position  
 * @param list @p (struct @p node*)  Pointer to a struct node that rappresent the list
 * @param index @p (int) Indicate the position of the element that have to be deleted
 * */
extern void delete_at(int index, struct node *list);


/**
 * @brief list empty
 * 
 * This function tests if the list is empty  
 * @param list @p (struct @p node*)  Pointer to a struct node that rappresent the list
 * @return 
 * 	- @brief @p true if the list is empty
 * 	- @brief @p false if the list isn't empty
 */
extern bool is_empty(const struct node *list);

/**
 * @brief count item's list
 * 
 * This function count how many elements are in the list  
 * @param list @p (const @p struct @p node*)  Const pointer to a struct node that rappresent the list
 * @return
 * - @brief @p zero if the list is empty
 * - @brief @p major @p then @p zero if the list isn't empty
 */
extern int count(const struct node *list);

extern const void *get_head_data(const struct node *list);
extern const void *get_tail_data(const struct node *list);
extern const void *get_data_at(int index, const struct node *list);

extern int index_of(const void *data, const struct node *list, int(*compare)(const void *a, const void *b));
extern int last_index_of(const void *data, const struct node *list);

extern struct node *find(int index, const struct node *list);
extern struct node *filter(const struct node *list, size_t data_size, bool(*compare)(const void *node));
extern struct node *reverse(const struct node *list);
extern void sort(struct node **list, int(*cmp)(void *a, void *b), void(*swap)(void *a, void *b), int MODE);

/**
 * @brief Calculate the min of the list
 * 
 * This function returns the min of the list.The user pass a function pointer to the function
 * that rappresent the criteria that two memory object are compared.
 * @p Example
 * Let's define this structure
 * @code{.c}
 * struct persona { char name[20], int age};
 * @endcode
 * Then fill the list of struct persona
 * @code{.c}
 * 
 * struct persona p1 = { "omar", 19 };
 * struct persona p2 = { "valerio", 29};
 * 
 * list = insert_head(list, &p1, sizeof(struct persona));
 * list = insert_head(list, &p2, sizeof(struct persona));
 * @endcode
 * Let's define the function that compares two struct persona (ex. compare by the age)
 * @code{.c}
 * int compare_persona(void *a, void *b){
 * 	struct persona *pa = a;
 * 	struct persona *pb = b;
 * 	return pa->age - pb->age;
 * }
 * @endcode
 * And if we call the function 
 * @code{.c}
 * struct persona max = min_list(list, compare_persona); 
 * @endcode  
 * The result is:
 * @verbatim
 * @p max = { "omar", 19 }
 * @endverbatim
 * @param list @p (const @p struct @p node*)  Const pointer to a struct node that rappresent the list
 * @return
 * - @brief @p NULL if the list is empty
 * - @brief @p void* if the list isn't empty
 */
extern void *min_list(const struct node *list, int(*compare)(void *a, void *b));

/**
 * @brief Calculate the max of the list
 * 
 * This function returns the max of the list.The user pass a function pointer to the function
 * that rappresent the criteria that two memory object are compared.
 * @p Example
 * Let's define this structure
 * @code{.c}
 * struct persona { char name[20], int age};
 * @endcode
 * Then fill the list of struct persona
 * @code{.c}
 * 
 * struct persona p1 = { "omar", 19 };
 * struct persona p2 = { "valerio", 29};
 * 
 * list = insert_head(list, &p1, sizeof(struct persona));
 * list = insert_head(list, &p2, sizeof(struct persona));
 * @endcode
 * Let's define the function that compares two struct persona (ex. compare by the age)
 * @code{.c}
 * int compare_persona(void *a, void *b){
 * 	struct persona *pa = a;
 * 	struct persona *pb = b;
 * 	return pa->age - pb->age;
 * }
 * @endcode
 * And if we call the function 
 * @code{.c}
 * struct persona max = max_list(list, compare_persona); 
 * @endcode  
 * The result is:
 * @verbatim
 * @p max = { "valerio", 29 }
 * @endverbatim
 * @param list @p (const @p struct @p node*)  Const pointer to a struct node that rappresent the list
 * @return
 * - @brief @p NULL if the list is empty
 * - @brief @p void* if the list isn't empty
 */
extern void *max_list(const struct node *list, int(*compare)(void *a, void *b));


#endif //LIST_H