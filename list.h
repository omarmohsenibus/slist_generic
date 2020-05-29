#if !defined LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct node {
	void *data;
	struct node *next;
};

enum mode {
	ASC, //ascending
	DESC //descending
};

extern struct node *insert_head(struct node *list, const void *data, size_t data_size);
extern struct node *insert_tail(struct node *list, const void *data);
extern struct node *insert_at(int index, struct node *list, const void *data);

extern void delete_head(struct node *list);
extern void delete_tail(struct node *list);
extern void delete_at(int index, struct node *list, const void *data);
extern void delete(struct node *list);

extern bool is_empty(const struct node *list);

extern const void *get_head_data(const struct node *list);
extern const void *get_tail_data(const struct node *list);
extern const void *get_data_at(int index, const struct node *list);


extern const void *find(const struct node *list, const void *field, int(*cmp)(void *, void *));
extern struct node *filter(const struct node *list, const void *field, int(*cmp)(void *, void *));
extern struct node *reverse(const struct node *list);
extern struct node *sort(struct node *list, int MODE);

extern void *min_list(const struct node *list, const void *field);
extern void *max_list(const struct node *list, const void *field);



#endif //LIST_H