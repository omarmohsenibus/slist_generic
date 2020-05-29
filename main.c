#include "list.h"

char *to_string_char(const struct node *list){
	char *result = NULL;
	if(list != NULL){
		size_t lenght = count(list);
		// [ 2, 4, 5 ]
		//parentesi =2 
		//elementi = count (3)
		//spazi = elementi + 1
		//virgola = elementi - 1
		result = malloc(lenght+1);
		result[lenght] = 0;
		
		size_t i = 0;
		result[i++] = '['
		for(struct node *t = list; t != NULL; t = t->next){
			result[i++] = ' ';
			result[i++] = t->data;
			result[i++] = ',',
		}
		result[i] = ']';
	}
	return list;
}



int main(void) {
	//test: char
	struct node *list = NULL;
	struct node *tmp = NULL;
	
	{
		char a = 'a';
		char b = 'b';
		char _new = 'c';

		list = insert_head(list, &a, sizeof(char));
		list = insert_head(list, &b, sizeof(char));
		list = insert_head(list, &_new, sizeof(char));

		tmp = list;
		printf("\tlista di char: ");
		printf("[");
		while (tmp != NULL) {
			char *data = (char*)tmp->data;
			printf(" %c,", *data);
			tmp = tmp->next;
		}
		printf("]\n");
		const char *head_data = get_head_data(list);
		const char *tail_data = get_tail_data(list);
		printf("Head of the list: %c\n", *head_data);
		printf("Tail of the list: %c\n", *tail_data);
		delete(list);
	}

	//test: int
	{
		int c = 1024;
		int d = -1024;

		list = NULL;
		list = insert_head(list, &c, sizeof(int));
		list = insert_head(list, &d, sizeof(int));

		tmp = list;
		printf("\tlista di int: ");
		printf("[");
		while (tmp != NULL) {
			int *data = (int *)tmp->data;
			printf(" %d, ", *data);
			tmp = tmp->next;
		}
		printf("]\n");
		const int *head_data = get_head_data(list);
		printf("Head of the list: %d\n", *head_data);
		delete(list);
	}
	//test: double
	{
		double e = 8.0;
		double f = 8.2e2;

		list = NULL;
		list = insert_head(list, &e, sizeof(double));
		list = insert_head(list, &f, sizeof(double));

		tmp = list;
		printf("\tlista di double: ");
		printf("[");
		while (tmp != NULL) {
			double *data = (double *)tmp->data;
			printf(" %lf, ", *data);
			tmp = tmp->next;
		}
		printf("]\n");
		const double *head_data = get_head_data(list);
		printf("Head of the list: %lf\n", *head_data);
		delete(list);
	}


	//test: float

	{
		float g = 2.0f;
		float h = 2.2e2f;

		list = NULL;
		list = insert_head(list, &g, sizeof(float));
		list = insert_head(list, &h, sizeof(float));

		tmp = list;
		printf("\tlista di float: ");
		printf("[");
		while (tmp != NULL) {
			float *data = (float *)tmp->data;
			printf(" %f, ", *data);
			tmp = tmp->next;
		}
		printf("]\n");
		const float *head_data = get_head_data(list);
		printf("Head of the list: %f\n", *head_data);

		delete(list);
	}

	//test char * (c string)
	{
		char i[] = "test";
		char l[] = "prova";

		list = NULL;
		list = insert_head(list, &i, strlen(i) + 1);
		list = insert_head(list, &l, strlen(l) + 1);

		tmp = list;
		printf("\tlista di stringhe c: ");
		printf("[");
		while (tmp != NULL) {
			char *data = (char *)tmp->data;
			printf(" %s, ", data);
			tmp = tmp->next;
		}
		printf("]\n");
		const char *head_data = get_head_data(list);
		printf("Head of the list: %s\n", head_data);

		delete(list);
	}

	//test: struct Persona
	{
		struct persona {
			char nome[10];
			int eta;
		};
		struct persona p1 = { "Omar", 19 };
		struct persona p2 = { "Marco", 45 };
		list = NULL;
		list = insert_head(list, &p1, sizeof(struct persona));
		list = insert_head(list, &p2, sizeof(struct persona));

		tmp = list;
		printf("\tlista di struct persona: ");
		printf("[");
		while (tmp != NULL) {
			struct persona *data = (struct persona *)tmp->data;
			printf(" { nome: %s, eta: %d }, ", data->nome, data->eta);
			tmp = tmp->next;
		}
		printf("]\n");
		const struct persona *head_data = get_head_data(list);
		printf("Head of the list: { nome: %s, eta: %d }\n", head_data->nome, head_data->eta);
		delete(list);
	}
	return 0;
}