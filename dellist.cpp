#include "dellist.h"
#include "structures.h"

#include <iostream>

using namespace std;

void dellist(player * button) {
    player* current= button;
    player* next;

    while (current != NULL) {
        next = current->next;  // Save the next pointer
        delete current;  // Delete the current node
        current = next;  // Move to the next node
    }
}
