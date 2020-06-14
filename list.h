#define _CRT_SECURE_NO_WARNINGS
#if !defined LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>


struct node {
	void *data;
	struct node *next;

};

enum mode {
	ASC, //ascending
	DESC //descending
};

extern struct node *insert_all(struct node *list, size_t data_size, size_t count, ...);
extern struct node *insert_head(struct node *list, const void *data, size_t data_size);
extern struct node *insert_tail(struct node *list, const void *data);
extern struct node *insert_at(int index, struct node *list, const void *data, size_t data_size);

extern struct node *insert_from_bin_file(char *filename);

extern struct node *update_at(int index, struct node *list, const void *data, size_t data_size);

extern void delete_head(struct node *list);
extern void delete_tail(struct node *list);
extern void delete_at(int index, struct node *list, const void *data);
extern void delete(struct node *list);

extern bool is_empty(const struct node *list);
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
extern void *min_list(const struct node *list, int(*compare)(void *a, void *b));
extern void *max_list(const struct node *list, int(*compare)(void *a, void *b));


#endif //LIST_H