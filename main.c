// This program inserts an entry into a linked list

#include <stdio.h>

// Define Structures
struct entry {
int value;
struct entry *next;
};

// Declare Functions
void insertEntry (struct entry *, struct entry *);
struct entry *printList (struct entry *);

int main(void) {
  
  // Create links
  struct entry linkHead;
  struct entry n1, n2, n3, insert;

  // Set value
  n1.value = 1;
  n2.value = 2;
  n3.value = 3;
  insert.value = 4;

  // Link entries
  linkHead.next = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = (struct entry *) 0;

  insertEntry (&insert, &linkHead);

  printList (linkHead.next);
  
  return 0;
}

// Define Functions
void insertEntry (struct entry *insert, struct entry *after) {
  insert->next = after->next;
  after->next = insert;
}

struct entry *printList (struct entry* current) {
  if (current->next == (struct entry*) 0) {
    printf ("%d\n", current->value);
    return (struct entry*) 0;
  }
  else {
    printf ("%d\n", current->value);
    printList (current->next);
    return (struct entry*) 0;
  }
}