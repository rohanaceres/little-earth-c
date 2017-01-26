#include <stdio.h>
#include <stdlib.h>

#include "keyvaluepair.h"

int main() {
    char * ceres = { 'c', 'e', 'r', 'e', 's' };
    char * samir = { 's', 'a', 'm', 'i', 'r' };
    char * flora = { 'f', 'l', 'o', 'r', 'a' };

    LinkedList list = newLinkedList();

    list->display(list);

    list->add(list, 1, ceres);
    list->display(list);

    list->add(list, 2, samir);
    list->display(list);

    list->add(list, 3, flora);
    list->display(list);

    list->remove(list, 3);
    list->display(list);
}
