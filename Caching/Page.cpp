#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Page.h"

/* Simple class to encapsulate page IDs and referenced bits. */
Page::Page() {
    /* Invalid page ID. */
    this->id = -1;
    /* Invalid counter. */
    this->counter = -1;
    this->referenced = false;
}

Page::Page(int id) {
    this->id = id;
    this->counter = 0;
    this->referenced = true;
}

Page& Page::operator=(const Page &other) {
    if (this == &other)
        return *this;

    this->id = other.id;
    this->counter = other.counter;
    this->referenced = other.referenced;

    return *this;
}

/* Naively implementing table as an array for simplicity. */
bool tableContainsPage(const std::vector<Page> &pages, const int pageID) {
    for (int j = 0; j < pages.size(); j++) {
	if (pages[j].id == pageID)
	    return true;
    }

    return false;
}

/* Used for debugging. */
void printPages(const std::vector<Page> &pages) {
    std::cout << "Pages:\t";
    for (int i = 0; i < pages.size(); i++) {
	std::cout << pages[i].id << '\t';
    }
    std::cout << std::endl;
}
