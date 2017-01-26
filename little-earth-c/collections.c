#include "collections.h"

// definitions
void
linkedlist_add(LinkedList self, int key, void * value);
void
linkedlist_remove(LinkedList self, int toRemove);
void
linkedlist_display(LinkedList self);
void *
linkedlist_getValue(LinkedList self, int key);

// construction
LinkedList newLinkedList(void) {
    LinkedList self = (LinkedList) abstract_malloc(sizeof(TLinkedList));

    self->head = null;
    self->last = null;
    self->length = 0;
    self->add = &linkedlist_add;
    self->remove = &linkedlist_remove;
    self->display = &linkedlist_display;
    self->getValue = &linkedlist_getValue;

    return self;
}

// declarations
// declarations
void
linkedlist_add(LinkedList self, int key, void * value) {
    // Create new node
    KeyValuePair newNode = newKeyValuePair(key, value);

    // If list is empty, head and last point to the new node
    if (self->length == 0) {
        self->head = newNode;
        self->last = newNode;
    }
    // If list is not empty, last next points to the new node
    // and new node previous points to the last. New node turns
    // into the last of the list.
    else {
        // New node previous points to the last:
        newNode->previous = self->last;

        // Last next points to the new node:
        self->last->next = newNode;

        // New node turns into the last of the list:
        self->last = newNode;
    }

    // Increment list lencth
    self->length++;
}
void
linkedlist_remove(LinkedList self, int toRemove) {
    if (self->head == null) {
        printf("Lista vazia, nada a remover.");
    }

    // Iterate through list until find the node that contains
    // the same ID to delete:
    KeyValuePair item = self->head;

    while (item != null && item->key != toRemove) {
        item = item->next;
    };

    // If nothing was f ound, return:
    if (item == null) {
        printf ("Item to with ID %d not found!", toRemove);
        return;
    }

    // If it is a match, delete the node with the corresponding
    // ID:
    if (item->key == self->head->key) {
        self->head = self->head->next;
    }
    else {
        item->previous->next = item->next;
    }

    if (item->key == self->last->key) {
        self->last = item->previous;
    }
    else {
        item->next->previous = item->previous;
    }

    // ... And releases it's memory:
    abstract_free(item);
    self->length--;
}
void
linkedlist_display(LinkedList self) {
    if (self->head == null) {
        printf("Lista vazia.\n");
    }

    printf("Number of items: <%d>\n", self->length);

    KeyValuePair currentItem = self->head;
    for (int i = 0; i < self->length; i++) {
        if (currentItem != null) {
            printf("[<%d>, <%p>]\n", currentItem->key, currentItem->value);
        }
        currentItem = currentItem->next;
    }
}
void *
linkedlist_getValue(LinkedList self, int key) {
    if (self->head == null) {
        printf("Lista vazia.\n");
    }

    KeyValuePair item = self->head;

    while (item != null && item->key != key) {
        item = item->next;
    };

    // If nothing was found, return:
    if (item == null) {
        printf ("Item to with ID %d not found!", key);
        return;
    }

    // If there is a match, return the corresponding value:
    return item->value;
}
