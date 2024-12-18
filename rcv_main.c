#include "rcv.h"
int main(int argc, char *argv[]){
    tally_t *tally = NULL;
    if (argc != 2 && argc != 4) {
        return 1;
    }
    if (argc == 4) {
        LOG_LEVEL = atoi(argv[2]);
    }
    
    if(argc == 2) {
        tally = tally_from_file(argv[1]);
    }
    else if (argc == 4){
        tally = tally_from_file(argv[3]);
    }
    if (tally == NULL) {
        printf("Could not load votes file. Exiting with error code 1\n");
        return 1;
    }
    tally_election(tally);
    tally_free(tally);
}