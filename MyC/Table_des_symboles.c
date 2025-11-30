/*
 *  Table des symboles.c
 *
 *  Created by Janin on 12/10/10.
 *  Copyright 2010 LaBRI. All rights reserved.
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Table_des_symboles.h"

/* bit  type handling */

  


/* Attribute types */

attribute new_attribute () {
  attribute r;
  r  = malloc (sizeof (struct ATTRIBUTE));
  if (r==NULL) {printf("Failed Malloc\n"); exit(-1);}
  r -> type_var = malloc(sizeof(list));
  if (r -> type_var==NULL) {printf("Failed Malloc\n"); exit(-1);}
  r -> type_var -> size = 0;
  r -> type_var -> head = NULL;
  return r;
};

void free_attribute(attribute a){
  if(a == NULL) return;
  if(a -> type_var == NULL) return free(a);
  while(a -> type_var -> head){
  node *n = a -> type_var -> head;
  a -> type_var -> head = n -> next;
  free(n);
  }
  free(a -> type_var);
  free(a);
}



attribute makeSymbol(int type, int offset, int depth)
{
  attribute r = new_attribute();
  r -> type = type;
  r -> offset = offset;
  r -> depth = depth;
  return r;
}



/* The storage structure is implemented as a linked chain */

/* linked element def */

typedef struct elem {
	char * symbol_name;
	attribute symbol_value;
	struct elem * next;
} elem;

/* linked chain initial element */
static elem * storage=NULL;

static elem * storage_fun=NULL;

/* get the symbol value of symb_id from the symbol table */
attribute get_symbol_value(char * symb_id) {
	elem * tracker=storage;

	/* look into the linked list for the symbol value */
	while (tracker) {
	  if (! strcmp(tracker -> symbol_name, symb_id))
	    return tracker -> symbol_value;  
	  tracker = tracker -> next;
	}
    
	/* if not found does cause an error */
	fprintf(stderr,"Erreur : symbole %s absent de la table des symboles\n",
		symb_id);
	return NULL;
};

attribute get_symbol_value_fun(char * symb_id) {
	elem * tracker=storage_fun;

	/* look into the linked list for the symbol value */
	while (tracker) {
	  if (! strcmp(tracker -> symbol_name, symb_id))
	    return tracker -> symbol_value;  
	  tracker = tracker -> next;
	}
    
	/* if not found does cause an error */
	fprintf(stderr,"Erreur : symbole %s absent de la table des symboles\n",
		symb_id);
	return NULL;
};



/* add the symbol symb_id with given value */
attribute set_symbol_value(char * symb_id,attribute value) {

	elem * tracker;	
	tracker = malloc(sizeof(elem));
	tracker -> symbol_name = symb_id;
	tracker -> symbol_value = value;
	tracker -> next = storage;
	storage = tracker;
	return storage -> symbol_value;
}

/* add the symbol symb_id with given value */
attribute set_symbol_value_fun(char * symb_id,attribute value) {

	elem * tracker;	
	tracker = malloc(sizeof(elem));
	tracker -> symbol_name = symb_id;
	tracker -> symbol_value = value;
	tracker -> next = storage_fun;
	storage_fun = tracker;
	return storage_fun -> symbol_value;
}


extern int current_offset;

void remove_symbols_at_depth(int d) {
elem *tracker = storage;
elem *prev = NULL;

while (tracker) {
    if (tracker->symbol_value->depth == d) {
        // remove this element
        elem *to_delete = tracker;
        if (prev == NULL) {
            storage = tracker->next;
        } else {
            prev->next = tracker->next;
        }
        tracker = tracker->next;

        free_attribute(to_delete->symbol_value);
        free(to_delete);
    }
    else {
        prev = tracker;
        tracker = tracker->next;
    }
}
 tracker = storage_fun;
prev = NULL;

while (tracker) {
    if (tracker->symbol_value->depth == d) {
        // remove this element
        elem *to_delete = tracker;
        if (prev == NULL) {
            storage_fun = tracker->next;
        } else {
            prev->next = tracker->next;
        }
        tracker = tracker->next;

        free_attribute(to_delete->symbol_value);
        free(to_delete);
    }
    else {
        prev = tracker;
        tracker = tracker->next;
    }

}
}
