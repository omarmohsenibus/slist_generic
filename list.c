#include "list.h"


bool is_empty(const struct node *list) {
	return list == NULL;
}

int count(const struct node *list) {
	size_t result = 0;
	if (list != NULL) {
		const struct node *tmp = list;
		while (tmp != NULL) {
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

struct node *insert_tail(struct node *list, const void *data, size_t data_size) {
	if (list != NULL) {
		struct node *tmp = list;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		struct node *new_node = malloc(sizeof(struct node));
		new_node->data = malloc(data_size);

		memcpy(new_node->data, data, data_size);
		new_node->next = NULL;
		tmp->next = new_node;
		return list;
	}
	return insert_head(list, data, data_size);
}


struct node *insert_at(int index, struct node *list, const void *data, size_t data_size) {
	struct node *new_node = NULL;
	int lenght = count(list);
	size_t i = 0;

	if (index == 0) return insert_head(list, data, data_size);
	if (index == lenght) return insert_tail(list, data, data_size);

	if (index > 0 && index < lenght) {
		struct node *prev = NULL;
		for (struct node *tmp = list; tmp != NULL; tmp = tmp->next) {
			if (index == i) {
				new_node = malloc(sizeof(struct node));
				new_node->data = malloc(data_size);
				memcpy(new_node->data, data, data_size);

				new_node->next = prev->next;
				prev->next = new_node;
				break;
			}
			i++;
			prev = tmp;
		}
	}
	return list;
}

void delete(struct node *list) {
	while (list != NULL) {
		struct node *tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
}
void delete_head(struct node *list) {
	if (list != NULL) {
		struct node *tmp = list;
		list = tmp->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void delete_at(int index, struct node *list){
	if(list != NULL){
		int n = count(list);
		if(index > -1 && index < n){
			int i = 0;
			for(struct node *tmp = list; tmp != NULL; tmp = tmp->next){
				if(i == index){
					free(tmp->data);
					free(tmp);
					break;
				}
			}
		}
	}
}


void *min_list(const struct node *list, int(*compare)(void *a, void *b)) {
	void *min = NULL;
	if(list != NULL){
		min = list->data;
		for (const struct node *tmp = list; tmp != NULL; tmp = tmp->next) {
			if (compare(min, tmp->data) > 0) {
				min = tmp->data;
			}
		}
	}
	return min;
}
void *max_list(const struct node *list, int(*compare)(void *a, void *b)) {
	void *max = NULL;
	if(list != NULL){
		max = list->data;
		for (const struct node *tmp = list; tmp != NULL; tmp = tmp->next) {
			if (compare(max, tmp->data) < 0) {
				max = tmp->data;
			}
		}
	}
	return max;
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

const void *get_data_at(int index, const struct node *list) {
	void *result = NULL;
	int n = count(list);
	if (list != NULL && index > -1 && index < n) {
		if (index == 0)	return get_head_data(list);
		if (index == n - 1)	return get_tail_data(list);

		int counter = 0;
		for (struct node *tmp = list; tmp != NULL; tmp = tmp->next) {
			if (index == counter) {
				result = tmp->data;
				break;
			}
			counter++;
		}
	}
	return result;

}


struct node *insert_all(struct node *list, size_t data_size, size_t count, ...) {
	va_list arg_pointer;
	va_start(arg_pointer, count);

	if (data_size < 4)	data_size = 4;

	while (count != 0) {
		const void *data = arg_pointer;
		list = insert_head(list, data, data_size);

		arg_pointer = arg_pointer + data_size;
		count--;
	}

	return list;
}

int index_of(const void *data, const struct node *list, int(*compare)(const void *a, const void *b)) {
	int result = -1;
	if (list != NULL && data != NULL) {
		size_t count = 0;
		for (const struct node *tmp = list; tmp != NULL; tmp = tmp->next) {
			if (compare(tmp->data, data) == 0) {
				result = count;
				break;
			}
			count++;
		}
	}
	return result;
}

struct node *filter(const struct node *list, size_t data_size, bool(*compare)(const void *node)) {
	struct node *filtered_list = NULL;
	if (list != NULL) {
		for (const struct node *tmp = list; tmp != NULL; tmp = tmp->next) {
			if (compare(tmp->data)) {
				filtered_list = insert_head(filtered_list, tmp->data, data_size);
			}
		}
	}
	return filtered_list;
}

struct node* find(int index, const struct node *list) {
	struct node *node = NULL;
	int len = count(list);
	if (index >= 0 && index < len) {
		struct node *tmp = list;

		for (int i = 0; i < len; i++) {
			if (index == i) {
				node = tmp;
				break;
			}
			tmp = tmp->next;
		}
	}
	return node;
}


struct node *update_at(int index, struct node *list, const void *data, size_t data_size) {
	struct node *result = list;

	if (list != NULL) {
		void *data_find = find(index, list)->data;
		if (data_find != NULL) {
			data_find = data;
		}
	}
	return result;
}

void sort(struct node **list, int(*cmp)(void *a, void *b), void(*swap)(void *a, void *b), int MODE) {
	if (*list != NULL) {
		struct node *curr = *list;
		struct node *succ = NULL;

		while (curr != NULL) {
			succ = (*list)->next;
			while (succ != NULL) {
				switch (MODE){
					case ASC:
						if (cmp(curr->data, succ->data) > 0) {
							swap(curr->data, succ->data);
						}
						break;
					case DESC:
						if (cmp(curr->data, succ->data) < 0) {
							swap(curr->data, succ->data);
						}
						break;
				}
				succ = succ->next;
			}
			curr = curr->next;
		}
	}
}