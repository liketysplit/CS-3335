#include "j.h"
#include "cl.h"

//Node Structure
typedef struct soldier_type{
	char *name;
	struct soldier_type *next;
}soldier;

//Node Creation
soldier *create(const char *name){
	soldier *s;
	if((s= malloc(sizeof(soldier)))==NULL){
		printf("Out of memory on heap.\n");
		return NULL;
	}
	if((s->name= calloc(10, sizeof(char)))==NULL){
		printf("Out of memory on heap.\n");
		return NULL;
	}
	strcpy(s->name, name);
	s->next = NULL;	
	return s;
}



int main(){

	void *start = NULL;
	void *cursor = NULL;
	soldier *n;
	char name[80];
	int kill;
	int countOfSoldiers = 0;

	//Read in all of the nodes
	for (; fgets(name, sizeof(name), stdin) != NULL ;){
		name[strlen(name)-1]='\0';
		if( (n=create(name))==NULL)
			return 1;
		if(countOfSoldiers==0)
			start = insert(start,n);
		if(countOfSoldiers!=0)
			cursor = insert(start,n);
		countOfSoldiers++; 		
	} 

	//Print out all of the nodes in the CLL
	int tempNum = countOfSoldiers;
	soldier *temp = cursor;
	while(tempNum != 0){
		print(temp);
		temp=temp->next;
		tempNum--;
	}

	//Reset the input via Cntrl D
  	fseek(stdin,0,SEEK_END);

  	//Get the release order
	printf("\nWhat kill order do you want? ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1]='\0';
	kill = atoi(name);


	//Release by the given order
	int count;
	while (countOfSoldiers!= 0){
		count =0;
		while(count < kill){
			if(count == kill-1 ){
				release(cursor);
				countOfSoldiers--;
				count++;
			}
			else{
				count++;
				cursor = (void *)advance(cursor);
			}

		}
	}
	
	return 0;
}
