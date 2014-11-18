#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Page.h"

/* Simulates a random page replacement algorithm. 
 * Uses a vector to maintain the unordered list of pages.
 * */
void random(int numPFrames) {
    std::vector<Page> pages(numPFrames);

    int pageID;
    while(std::cin >> pageID) {
        /* Do nothing if page is found. */
        if (tableContainsPage(pages, pageID))
            continue;

        /* Else we have a page fault. */
        std::cout << pageID << std::endl;

        Page newPage(pageID);
        int i = rand() % numPFrames;
        pages[i] = newPage;
        
        //std::cout << "Adding page " << newPage.id << std::endl;
        //printPages(pages);
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    /* Should be given a single command-line argument for the number of available page frames. */
    if (argc != 2) {
        std::cout << "Provide a single command-line argument for the number of page frames available." << std::endl;
        return 0;
    }

    int numPFrames = atoi(argv[1]);

    random(numPFrames);
}
