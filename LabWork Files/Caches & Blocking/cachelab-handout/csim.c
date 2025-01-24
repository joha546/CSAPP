// Md Khaled Bin Joha - 0822220105101052

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<getopt.h>
#include "cachelab.h"

// 64-bit variable to hold memory addresses.
typedef unsigned long long int memoryAddress;

// struct to group cache paramenters.
struct cacheParameter
{
    int s, b, E, S, B;

    int hits, misses, evicts;
};

struct setLine{
    int last_used, valid;
    memoryAddress tag;
    char *block;    // it contains garbage value by default.
};

struct cacheSet{
    struct setLine *lines;
};

struct cache{
    struct cacheSet *sets;
};

struct cache initCache(long long numberOfSets, int numberOfLines, long long sizeOfBlocks){
    struct cache newCache;      // declares a new cache structure.
    struct cacheSet set;
    struct setLine line;
    int indexOfSet, indexOfLine;

    newCache.sets = (struct cacheSet*)malloc(sizeof(struct cacheSet) * numberOfSets);

    for(indexOfSet=0; indexOfSet<numberOfSets; indexOfSet++){
        /*
        The function ensures the cache is:

        Allocated with sufficient memory to hold all sets and lines.
        Properly initialized with default metadata (0 for all fields) to prevent undefined behavior.
        */
        //Allocate memory for numberOfLines lines in the set.
        set.lines = (struct setLine*) malloc(sizeof(struct setLine)*numberOfLines);
        // each set will now point to an array of setLine objects.
        // Assign this set to the corresponding position in newCache.sets.
        newCache.sets[indexOfSet] = set;

        for(indexOfLine=0; indexOfLine<numberOfLines; indexOfLine++){
            line.last_used = 0;
            line.valid = 0;
            line.tag = 0;
            line.block = NULL;  // Initialize block to NULL
            set.lines[indexOfLine] = line;
        }
    }

    return newCache;
};

void cleanFunction(struct cache myCache, long long numberOfSets, int numberOfLines, long long sizeOfBlocks){
    // function to clean up everything when done because memory in cache is expensive.

    int indexOfSet;
    for(indexOfSet=0; indexOfSet<numberOfSets; indexOfSet++){
        struct cacheSet set = myCache.sets[indexOfSet];

        if(set.lines != NULL){
            free(set.lines);
        }
    }
    if(myCache.sets != NULL){
        free(myCache.sets);
    }
}

int detectEmptyLine(struct cacheSet exampleSet, struct cacheParameter exampleParameter) {
	// check is whether the line that is matched is empty or not
	
	int numberOfLines = exampleParameter.E;
	int index;
	struct setLine line;

	for (index = 0; index < numberOfLines; index ++) {
		line = exampleSet.lines[index];
		if (line.valid == 0) {    // one line is available
			return index;
		}
	}
	return -1;     // no line is available
}

int detectEvictLine(struct cacheSet exampleSet, struct cacheParameter exampleParameter, int *usedLines){
    // detects if a line is least recently used.

    int numberOfLines = exampleParameter.E;
    int maxFreqUsage = exampleSet.lines[0].last_used;
    int minFreqUsage = exampleSet.lines[0].last_used;
    int minFreqUsage_index = 0;
    int indexOfLine;

    for(indexOfLine=0; indexOfLine<numberOfLines; indexOfLine++){
        if(minFreqUsage>exampleSet.lines[indexOfLine].last_used){
            minFreqUsage_index=indexOfLine;
            minFreqUsage = exampleSet.lines[indexOfLine].last_used;
        }

        if(maxFreqUsage<exampleSet.lines[indexOfLine].last_used){
            maxFreqUsage = exampleSet.lines[indexOfLine].last_used;
        }
    }

    usedLines[0] = minFreqUsage;
    usedLines[1] = maxFreqUsage;
    return minFreqUsage_index;
}

/*
This function was created to test initCache and cleanFunction functions.

void testCacheFunction(){

    printf("Starting test for initCache and cleanFunction.....\n");

    long long numberOfSets = 4;
    int numberOfLines = 2;
    long long sizeOfBlocks = 64;

    struct cache myCache = initCache(numberOfSets, numberOfLines, sizeOfBlocks);

    // validating the initialization.
    printf("Validating the cache initialization.\n");
    for(int i=0; i<numberOfSets; i++){
        struct cacheSet set = myCache.sets[i];
        for(int j=0; j<numberOfLines; j++){
            struct setLine line = set.lines[j];
            if(line.last_used != 0 || line.valid != 0 || line.block != 0){
                printf("Test failed.. Line [%d][%d] not initialized correctly..\n", i, j);
                return;
            }
        }
    }
    printf("Cache initialized correctly....\n");

    printf("Cleaning up the cache...\n");
    cleanFunction(myCache, numberOfSets, numberOfLines, sizeOfBlocks);
    printf("Cache cleaned up..");
}
*/

int main(int argc, char **argv)
{
    // struct cache mycache;
    // struct cacheParameter exampleParameter;

    // printSummary(0, 0, 0);
    testCacheFunction();
    return 0;
}
