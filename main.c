#include "list.h"

typedef struct persona {
	char nome[10];
	char cognome[10];
	char eta;
	char categoria[20];
} persona;

bool filter_fun(const void *node_data) {
	const struct persona *data = node_data;
	return data->eta < 18 && strcmp(data->categoria, "uno") == 0;
}


int main(void) {
	struct node *list = NULL;
	struct node *filtered_list = NULL;

	persona p1 = { "omar", "mohseni", 19, "uno" };
	persona p2 = { "filippo", "niki", 20, "due" };
	persona p3 = { "alberto", "biki", 14, "uno" };
	persona p4 = { "michele", "tiki", 29, "uno" };
	persona p5 = { "riccardo", "kimi", 10, "due" };

	list = insert_head(list, &p1, sizeof(persona));
	list = insert_head(list, &p2, sizeof(persona));
	list = insert_head(list, &p3, sizeof(persona));
	list = insert_head(list, &p4, sizeof(persona));
	list = insert_head(list, &p5, sizeof(persona));

	persona pmod = { "khema", "carlo", 21, "tre" };
	list = update_at(2, list, &pmod, sizeof(persona));
	


	struct node *tmp = filtered_list;
	printf("filtered_list : [\n");
	while (tmp != NULL) {
		const struct persona *data = tmp->data;
		printf("\t{%s, %s, %d}\n", data->nome, data->cognome, data->eta);
		tmp = tmp->next;
	}
	printf("]");

	delete(list);
	delete(filtered_list);
	return 0;
}