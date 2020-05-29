#include "list.h"

bool is_empty(const struct node *list) {
	return list == NULL;
}

size_t count(const struct node *list){
	size_t result = 0;
	
	if(list != NULL){
		const struct node *tmp = list;
		while(tmp != NULL){
			result++;
			tmp = tmp->next;
		}
	}
	
	return result;
}

struct node *insert_head(struct node *list, const void *data, size_t data_size) {
	struct node *new_node = malloc(sizeof(struct node));
	new_node->data = malloc(data_size);

	memcpy(new_node->data, data, data_size);
	new_node->next = list;

	return new_node;
}

void delete(struct node *list) {
	while (list != NULL) {
		struct node *tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
}


void *min_list(const struct node *list, const void *field) {
	return 0;
}
void *max_list(const struct node *list, const void *field) {
	return 0;
}

const void *get_head_data(const struct node *list) {
	void *result = NULL;

	if (list != NULL) {
		result = list->data;
	}

	return result;
}

const void *get_tail_data(const struct node *list) {
	const void *result = NULL;

	if (list != NULL) {
		const struct node *tmp = list;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		result = tmp->data;
	}

	return result;
}