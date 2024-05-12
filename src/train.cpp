// Copyright 2021 NNTU-CS
#include <iostream>
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage *newCage = new Cage;
    newCage->light = light;

    if (!first) {
        first = newCage;
        first->next = first;
        first->prev = first;
    } else {
        Cage *lastCage = first->prev;
        lastCage->next = newCage;
        newCage->prev = lastCage;
        newCage->next = first;
        first->prev = newCage;
    }

    countOp++;
}

int Train::getLength() {
    if (!first)
        return 0;

    int length = 0;
    Cage *current = first;
    do {
        length++;
        current = current->next;
    } while (current != first);

    std::cout << "Length: " << length << std::endl;
    return length;
}

int Train::getOpCount() {
    std::cout << "Count of operations: " << countOp << std::endl;
    return countOp;
}
