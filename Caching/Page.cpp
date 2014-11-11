#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/* Simple class to encapsulate page IDs and referenced bits. */
class Page {
public:
    int id;    
    bool referenced;

    Page() {
	/* Invalid page ID. */
	this->id = -1;
	this->referenced = false;
    }

    Page(int id) {
	this->id = id;
	this->referenced = true;
    }

    Page &operator=(const Page &other) {
	if (this == &other)
	    return *this;

	this->id = other.id;
	this->referenced = other.referenced;

	return *this;
    }
};

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
