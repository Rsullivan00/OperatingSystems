#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/* Simulates the least recently used page replacement algorithm. 
 * Uses a vector to maintain the queue of pages, with the most
 * recently used page at the back of the vector.
 * */
void leastRecentlyUsed(int numPFrames) {
    std::vector<Page> pages(numPFrames);

    int pageID, i = 0;
    while(std::cin >> pageID) {
	if (tableContainsPage(pages, pageID))
	    continue;

	/* Else we have a page fault, so we want to replace a page. */
	std::cout << pageID << std::endl;

	while(pages[i].referenced == true) {
	    /* Set referenced value to false. */
	    pages[i].referenced = false;
	    i = (i+1) % numPFrames;
	}

	/* Iterator is pointing to a non-referenced page. */
	Page newPage(pageID);
	pages[i] = newPage;
	//std::cout << "Adding page " << newPage.id << std::endl;
	//printPages(pages);
    }
}

int main(int argc, char **argv) {
    /* Should be given a single command-line argument for the number of available page frames. */
    int numPFrames = atoi(argv[1]);

    leastRecentlyUsed(numPFrames);
}
