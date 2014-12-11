#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>

#include "Page.h"

/* Simulates the least recently used page replacement algorithm. 
 * Uses a deque to maintain the queue of pages, with the most
 * recently used page at the front of the deque.
 * */
void leastRecentlyUsed(int numPFrames) {
    std::deque<Page> pages(numPFrames);

    int pageID;
    while(std::cin >> pageID) {
        bool found = false;
        for (int i = 0; i < pages.size(); i++) {
            if (pages[i].id == pageID) {
                /* If we found the page, move it to the front of the queue. */
                pages.erase(pages.begin() + i);
                Page newPage(pageID);
                pages.push_front(newPage);
                found = true;
                break;
            }
        }

        if (found)
            continue;

        /* Else we have a page fault. */
        std::cout << pageID << std::endl;

        /* If the page table is full, get rid of the last page. */
        if (pages.size() == numPFrames)
            pages.pop_back();

        /* Add to front of queue. */
        Page newPage(pageID);
        pages.push_front(newPage);

        //std::cout << "Adding page " << newPage.id << std::endl;
        //printPages(pages);
    }
}

int main(int argc, char **argv) {
    /* Should be given a single command-line argument for the number of available page frames. */
    if (argc != 2) {
        std::cout << "Provide a single command-line argument for the number of page frames available." << std::endl;
        return 0;
    }

    int numPFrames = atoi(argv[1]);

    leastRecentlyUsed(numPFrames);
}
