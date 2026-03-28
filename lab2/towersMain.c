#include <stdio.h>
#include <stdlib.h>
#include "towers.h"

int main(int argc, char **argv)
{
	/*Default Nums*/
    int n = 3;
    int from = 1;
    int dest = 2;
    
    /*Only Number of Disks Provided*/
    if (argc == 2) {
		n = atoi(argv[1]);
		if (n <= 0) {
			fprintf(stderr, "Error\n");
			return 1;
		}
	}
	
	/*Number of Disks, Start, and End Points provided*/
	else if (argc == 4) {
		n = atoi(argv[1]);
		from = atoi(argv[2]);
		dest = atoi(argv[3]);
		
		if (n <= 0 || from < 1 || from > 3 || dest < 1 || dest > 3 || from == dest) {
			fprintf(stderr, "Error\n");
			return 1;
		} 
	} else if (argc != 1){
        fprintf(stderr, "Error\n");
		return 1;
    }
    
    towers(n, from, dest);
    exit(0);
}

