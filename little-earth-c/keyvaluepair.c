#include "keyvaluepair.h"
#include "abstract.h"

// definitions
void
keyvaluepair_add(LinkedList self, int key, void * value);
void
keyvaluepair_remove(LinkedList self, int toRemove);
void
keyvaluepair_display(LinkedList self);

// construction
LinkedList newLinkedList(void) {
    LinkedList self = (LinkedList) abstract_malloc(sizeof(TLinkedList));

    self->head = null;
    self->last = null;
    self->length = 0;
    self->add = &keyvaluepair_add;
    self->remove = &keyvaluepair_remove;
    self->display = &keyvaluepair_display;

    return self;
}
KeyValuePair newKeyValuePair(int key, void * value) {
    KeyValuePair self = (KeyValuePair) abstract_malloc(sizeof(TKeyValuePair));

    self->next = null;
    self->previous = null;
    self->key = key;
    self->value = value;

    return self;
}

// declarations
void
keyvaluepair_add(LinkedList self, int key, void * value) {
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
keyvaluepair_remove(LinkedList self, int toRemove) {
    if (self->head == null) {
        printf("Lista vazia, nada a remover.");
    }

    // Iterate through list until find the node that contains
    // the same ID to delete:
    KeyValuePair item = self->head;

    while (item != null && item->key != toRemove) {
        item = item->next;
    };

    // If nothing was found, return the fundtion:
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
keyvaluepair_display(LinkedList self) {
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
