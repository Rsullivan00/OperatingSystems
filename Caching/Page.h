#ifndef __Page_H
#define __Page_H

#include <vector>

class Page {
public:
    int id;    
    bool referenced;
    int counter;

    Page();
    Page(int id);
    Page &operator=(const Page &other);
};

/* Naively implementing table as an array for simplicity. */
bool tableContainsPage(const std::vector<Page> &pages, const int pageID);

/* Used for debugging. */
void printPages(const std::vector<Page> &pages);

#endif
