#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
#include <climits>

#include "Page.h"

/* Checks for referenced pages and increments counters of
    referenced pages. */
void pageTableScan(std::vector<Page> &pages) {
    for (int i = 0; i < pages.size(); i++) {
        if (pages[i].referenced) {
            pages[i].referenced = false;
            pages[i].counter++;
        }
    }
}

/* Simulates the least frequently used page replacement algorithm. 
 * Uses a vector to maintain the unordered list of pages.
 * */
void leastFrequentlyUsed(int numPFrames) {
    std::vector<Page> pages(numPFrames);

    int pageID;
    while(std::cin >> pageID) {
        bool found = false;
        for (int i = 0; i < pages.size(); i++) {
            if (pages[i].id == pageID) {
                /* If we found the page, set it as referenced. */
                pages[i].referenced = true;
                found = true;
            }
        }

        if (found)
            continue;

        /* Else we have a page fault. */
        std::cout << pageID << std::endl;

        pageTableScan(pages);

        Page newPage(pageID);
        /* If the page table is full, get rid of the LFU page. */
        if (pages.size() == numPFrames) {
            int minCount = INT_MAX;
            int minIndex = 0;
            for (int i = 0; i < pages.size(); i++) {
                if (pages[i].counter < minCount) {
                    minCount = pages[i].counter;
                    minIndex = i;
                }
            }

            pages[minIndex] = newPage;
        } else {
            /* Table is not full. Just add page. */
            pages.push_back(newPage);
        }

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

    leastFrequentlyUsed(numPFrames);
}
