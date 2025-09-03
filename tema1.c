#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char elem;
    struct list *next;
    struct list *prev;
} *TList;

TList initList() {
    TList sentinel = malloc(sizeof(struct list));
    sentinel->next = sentinel->prev = NULL;
    return sentinel;
}
TList createNode (char elem){
    TList node = malloc(sizeof(struct list));
    node->prev = NULL;
    node->next = NULL;
    node->elem = elem;
    return node;
}

TList MOVE_LEFT (TList sentinel, TList mecanic){
    if(mecanic->prev == sentinel)
        mecanic = sentinel->prev;
    else 
        mecanic = mecanic->prev;
    return mecanic;
}

TList MOVE_RIGHT (TList sentinel, TList mecanic){
    if(mecanic->next != sentinel){
        mecanic = mecanic->next;
        return mecanic;
    }
    TList node = createNode('#');
    mecanic->next = node;
    node->prev = mecanic;
    node->next = sentinel;
    sentinel->prev = node;
    mecanic = node;
    return mecanic;
}

TList WRITE (TList mecanic, char elem){
    mecanic->elem = elem;
    return mecanic;
}

TList CLEAR_CELL (TList sentinel, TList mecanic){
    TList tmp = mecanic;
    if(mecanic->prev != sentinel){
        mecanic->prev->next = mecanic->next;
        mecanic->next->prev = mecanic->prev;
        mecanic = mecanic->prev;
        free(tmp);
        return mecanic;
    }
    if(mecanic->prev == sentinel && mecanic->next != sentinel){
        mecanic->prev->next = mecanic->next;
        mecanic->next->prev = mecanic->prev;
        mecanic = sentinel->prev;
        free(tmp);
        return mecanic;
    }
    if(mecanic->prev == sentinel && mecanic->next == sentinel){
        mecanic->elem = '#';
        return mecanic;
    }
    return mecanic;
}

TList CLEAR_ALL (TList sentinel, TList mecanic){
    TList iter = sentinel->next;
    TList tmp = iter;;
    while(iter != sentinel){
        tmp = iter;
        iter = iter->next;
        free(tmp);
    }
    mecanic = createNode('#');
    mecanic->prev = sentinel;
    mecanic->next = sentinel;
    sentinel->next = mecanic;
    sentinel->prev = mecanic;
    return mecanic;
    
}

TList INSERT_LEFT(TList sentinel, TList mecanic, char elem, FILE *out){
    if(mecanic->prev == sentinel){
        fprintf(out,"ERROR\n");
        return mecanic;
    }
    TList node = createNode(elem);
    node->prev = mecanic->prev;
    mecanic->prev->next = node;
    node->next = mecanic;
    mecanic->prev = node;
    mecanic = node;
    return mecanic;
}

TList INSERT_RIGHT(TList sentinel, TList mecanic, char elem){
	(void)sentinel;
    TList node = createNode(elem);
    node->prev = mecanic;
    node->next = mecanic->next;
    mecanic->next->prev = node;
    mecanic->next = node;
    mecanic = node;
	return mecanic;
}

void SHOW_CURRENT (TList mecanic, FILE *out){
    fprintf(out,"%c\n", mecanic->elem);
}

TList SEARCH (TList sentinel, TList mecanic, char *sir, FILE *out){
    TList iter = mecanic;
    TList tmp = mecanic;
    int ok = 0;
    int i = 0;
    if(iter->elem == sir[0]){
        i = 1;
        //verifica primul element verificat est chiar sir[0]
    }else{
        i = 0;
        }   
    iter = iter->next;
    while(iter != mecanic){
        if(iter == sentinel)
            iter = sentinel->next;
        if(iter == mecanic)
            break;
        if(iter->elem == sir[0] && i == 0){
            tmp = iter;
            i++;
            //tmp retine a doua pozitie a lui sir[0] pentru a ne putem intoarce acolo daca sirul pe care il verifica momentan nu e bun
        }else
            if(iter->elem == sir[0] && i != 0)
                tmp = iter;
            else
                if(iter->elem == sir[i] && i > 0)
                    i++;
                else
                    if(iter->elem != sir[i] && tmp == mecanic)
                        i = 0;
                    else
                        if(iter->elem != sir[i] && tmp != mecanic){
                            iter = tmp;
                            i = 1;
                            tmp = mecanic;
                        }
        if(i == (int)strlen(sir)){
            ok = 1;
            break;
        }
        iter = iter->next;
    }
    if(ok == 1){
        while(mecanic != tmp){
            mecanic = mecanic->next;
        }
        // printf("%c ", mecanic->elem);
        return mecanic;
    }else{
        fprintf(out, "ERROR\n");
        return mecanic;
    }
    
}



TList SEARCH_RIGHT (TList sentinel, TList mecanic, char *sir, FILE *out){
    TList iter = mecanic;
    TList tmp = mecanic;
    int ok = 0;
    int i = 0;
    if(iter->elem == sir[0]){
        i = 1;
    }else{
        i = 0;
        }
    iter = iter->next;
    while(iter != mecanic && iter != sentinel){
        if(iter->elem == sir[0] && i == 0){
            tmp = iter;
            i++;
            //tmp retine a doua pozitie a lui sir[0] pentru a ne putem intoarce acolo daca sirul pe care il verifica momentan nu e bun
        }else{
            if(iter->elem == sir[0] && i != 0)
                tmp = iter;
            else
                if(iter->elem == sir[i] && i > 0)
                    i++;
                else
                    if(iter->elem != sir[i] && tmp == mecanic)
                        i = 0;
                    else
                        if(iter->elem != sir[i] && tmp != mecanic){
                            iter = tmp;
                            i = 1;
                            tmp = mecanic;
                        }
			}
            if(i == (int)strlen(sir)){
                ok = 1;
                break;
            }
            iter = iter->next;
            }
    if(ok == 1){
        for(int j = 0; j < (int)strlen(sir)-1; j++)
            tmp = tmp->next;
        mecanic = tmp;
        return mecanic;
    }else{
        fprintf(out, "ERROR\n");
        return mecanic;
    }
}

TList SEARCH_LEFT (TList sentinel, TList mecanic, char *sir, FILE *out){
    TList iter = mecanic;
    TList tmp = mecanic;
    int ok = 0;
    int i = 0;
    if(iter->elem == sir[0]){
        i = 1;
        //daca sirul cautat incepe de la mecanic sau nu
    }else{
        i = 0;
        }
    iter = iter->prev;
    while(iter != mecanic && iter != sentinel){
        if(iter->elem == sir[0] && i == 0){
            tmp = iter;
            i++;
            //tmp retine a doua pozitie a lui sir[0] pentru a ne putem intoarce acolo daca sirul pe care il verifica momentan nu e bun
        }else{
            if(iter->elem == sir[0] && i != 0){
                tmp = iter;
            }
                if(iter->elem == sir[i] && i > 0){
                    i++;
                }
                else
                    if(iter->elem != sir[i] && tmp == mecanic){
                        i = 0;
                    }
                    else
                        if(iter->elem != sir[i] && tmp != mecanic){
                            iter = tmp;
                            i = 1;
                            tmp = mecanic;
                            //iter se intoarce la tmp daca
                        }
			}
            if(i == (int)strlen(sir)){
                ok = 1;
                break;
            }
            iter = iter->prev;
            }
    if(ok == 1){
        for(int j = 0; j < (int)strlen(sir)-1; j++)
            tmp = tmp->prev;
        mecanic = tmp;
        return mecanic;
    }else{
        fprintf(out, "ERROR\n");
        return mecanic;
    }
}



typedef struct QueueNode{
	char *comanda;
	struct QueueNode *next;
	struct QueueNode *prev;
}QueueNode;

typedef struct Queue{
	QueueNode *first;
	QueueNode *last;
	long size;
}Queue;

Queue* createQueue(void){
		Queue *q = malloc(sizeof(Queue));
		q->first = q->last = NULL;
		q->size = 0;
		return q;
} 

int isQueueEmpty(Queue *q){
	if(q == NULL || q->first == NULL)
		return 1;
	return 0;
    //daca coada e goala sau nu
}

void enqueue(Queue *q, char* comanda){
	QueueNode *iter = malloc(sizeof(QueueNode));
    int lungime = strlen(comanda);
    iter->comanda = malloc((lungime + 1) * sizeof(char));
	strcpy(iter->comanda, comanda);
	if(q->first == NULL){
		q->first = iter;
		q->last = iter;
		q->size = 1;
		q->first->prev = q->first->next = NULL;
		return;
	}
	q->last->next = iter;
	iter->prev = q->last;
	q->last = iter;
	q->size ++;
    //se baga in coada
}

char* front(Queue* q){
	return q->first->comanda;
    //returneaza prima comanda
}

void dequeue(Queue* q){
    //scot din coada
	if(q == NULL || q->first == NULL)
		return;
	if(q->first == q->last){
		q->size = 0;
        free(q->first->comanda);
	    free(q->first);
		q->first = q->last = NULL;
		return ;
	}
	QueueNode *iter = q->first;
	q->first = q->first->next;
	q->first->prev = NULL;
    free(iter->comanda);
	free(iter);
	q->size --;
	return;
}

void destroyQueue(Queue *q){
	if(q == NULL)
		return;
	if(q->first == NULL){
		free(q);
		return;
	}
	QueueNode *iter = q->first;
	QueueNode *temp = q->first;
	while(iter != NULL){
		iter = iter->next;
        free(temp->comanda);
		free(temp);
		temp = iter;
	}
	free(q);
	q->size = 0;
    //distrug coada
}


Queue * EXECUTE(Queue *q, TList sentinel, TList *copy_mecanic, FILE *out){
    TList mecanic = *copy_mecanic;
	if( strcmp(q->first->comanda, "MOVE_LEFT") == 0){
		mecanic = MOVE_LEFT(sentinel, mecanic);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	if( strcmp(q->first->comanda, "MOVE_RIGHT") == 0){
		mecanic = MOVE_RIGHT(sentinel, mecanic);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	if ( strcmp (q->first->comanda, "CLEAR_CELL") == 0){
		mecanic = CLEAR_CELL(sentinel, mecanic);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}

	if ( strcmp (q->first->comanda, "CLEAR_ALL" )== 0 ){
		mecanic = CLEAR_ALL(sentinel, mecanic);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	char *cuvant;
	cuvant = strtok(q->first->comanda, " ");
	if( strcmp(cuvant, "WRITE") == 0){
		cuvant = strtok(NULL, " ");
		mecanic = WRITE(mecanic, cuvant[0]);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	if( strcmp(cuvant, "SEARCH") == 0){
		cuvant = strtok(NULL, " ");
		mecanic = SEARCH(sentinel, mecanic , cuvant, out);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	if( strcmp(cuvant, "SEARCH_LEFT") == 0){
		cuvant = strtok(NULL, " ");
		mecanic = SEARCH_LEFT(sentinel, mecanic , cuvant, out);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	if( strcmp(cuvant, "SEARCH_RIGHT") == 0){
		cuvant = strtok(NULL, " ");
		mecanic = SEARCH_RIGHT(sentinel, mecanic , cuvant, out);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	if( strcmp(cuvant, "INSERT_RIGHT") == 0){
		cuvant = strtok(NULL, " ");
		mecanic = INSERT_RIGHT(sentinel, mecanic , cuvant[0]);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
	if( strcmp(cuvant, "INSERT_LEFT") == 0){
		cuvant = strtok(NULL, " ");
		mecanic = INSERT_LEFT(sentinel, mecanic , cuvant[0], out);
		dequeue(q);
        *copy_mecanic = mecanic;
		return q;
	}
    *copy_mecanic = mecanic;
    // comenzile care au un singur cuvant se baga in coada direct, restul fac cu strtok pentru a imi da seama ce sir/ caracter trebuie sa adaug/caut
	return q;
}


Queue * SWITCH (Queue *q) {
	QueueNode *iter = q->first;
	QueueNode *inv = q->last;
	char *aux;
	int i = 1;
	if(q->size == 0 || q->size == 1)
		return q;
	while(i <= q->size/2){
		aux = iter->comanda;
		iter->comanda = inv->comanda;
		inv->comanda = aux;
		iter = iter->next;
		inv = inv->prev;
		i++;
	}
    //inverseaza ordinea din coada
	return q;
}

void SHOW (TList sentinel, TList mecanic, FILE *out){
    TList iter = sentinel->next;
    while(iter!= sentinel){
        if(iter == mecanic) {
            fprintf(out,"|%c|",iter->elem);
        }
        else {
            fprintf(out,"%c",iter->elem);
        }
        iter = iter->next;
    }
    fprintf(out,"\n");

}

int main(){
    TList sentinel = initList();
    TList mecanic = createNode('#');
    mecanic->prev = sentinel;
    mecanic->next = sentinel;
    sentinel->next = mecanic;
    sentinel->prev = mecanic;
    Queue *q = createQueue();
    char s[255];
    int N; 
    FILE *in = fopen("tema1.in", "rt");
	FILE *out = fopen("tema1.out", "wt");
    fscanf(in, "%d", &N);
    // numar comenzi citite
	fgets(s, 255, in);
    for (int i = 0; i < N; i++) {
        fgets(s, 255, in);
        if(!feof(in))
            s[strlen(s) - 1] = '\0';
		if(strcmp(s, "SHOW_CURRENT") == 0) {
			SHOW_CURRENT(mecanic, out);
            // se execcuta direct
        } else if(strcmp(s, "SHOW") == 0) {
			SHOW(sentinel, mecanic, out);
            //se executa direct
        } else if(strcmp(s, "SWITCH") == 0) {
			SWITCH(q);
            //se inverseaza ordinea la coada
        } else if(strcmp(s, "EXECUTE") == 0) {
		    EXECUTE(q, sentinel, &mecanic, out);
            // se executa comanda
        } else {
            enqueue(q, s);
            // se baga in coada comanda
        }
	} 
    destroyQueue(q);
    mecanic = CLEAR_ALL(sentinel, mecanic);
    free(mecanic);
    free(sentinel);
    fclose(in);
    fclose(out);
    return 0;
}