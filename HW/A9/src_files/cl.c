#include "cl.h"
#include "j.h"

typedef struct soldier_type{
	char *name;
	struct soldier_type *next;
}soldier;

//Prints out a given node
void print(void *cursor){
	if(cursor == NULL){
		printf("Empty list.\n");
	}
 	else{
		soldier *i = cursor;
		printf("%-10s", i->name);
	}
}

//Inserts a node
void * insert(void *cursor, void *name){

	if (cursor==NULL){
		soldier *s = name;
		s->next=name;
		return s;
	}
	else {
		soldier *t = cursor;
		for(; t->next != cursor; t=t->next);

		t->next = name;
		t->next->next = cursor;
		return name;
	}

}

//Advances to the next node
void *advance(void *cursor){
	soldier *pre = cursor;
 	return (void *)pre->next;
}

//Release a node
void *release(void *cursor){
		soldier *pre = cursor;
		soldier *n = pre->next;
		pre->next = n->next;
		printf("%15s is Dead!\n", n->name);
		free (n->name);
		free (n);
		return pre;	
}