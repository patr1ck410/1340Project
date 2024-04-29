#include "dellist.h"
#include "structures.h"

#include <iostream>

using namespace std;

void dellist(player *button) {

     if (button == nullptr) {
        return;
    }

    player* last = button;
    while (last->next != button) {
        last = last->next;
    }
    // Update the next pointer of the last node
    last->next = (button)->next;

    // Delete the first node
    player* temp = button;
    button = (button)->next;
    free(temp);

    // Update the button pointer if necessary
    if (button == temp) {
        // If there was only one node, set button to null
        button = nullptr;
    }
}
