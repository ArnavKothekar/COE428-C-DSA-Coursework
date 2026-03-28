#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// State Struct
typedef struct State {
    char name;
    struct State *next0;
    struct State *next1;
    bool deleted;
} State;

int main(int argc, char * argv[])
{
    // Initialize States
    State states[8];
    for (int i = 0; i < 8; i++) {
        states[i].name = 'A' + i;
        states[i].deleted = false;
    }

    // State Transitions
    states[0].next0 = &states[3]; 
    states[0].next1 = &states[1]; // A -> D, B
    
    states[1].next0 = &states[2]; 
    states[1].next1 = &states[7]; // B -> C, H
    
    states[2].next0 = &states[4]; 
    states[2].next1 = &states[5]; // C -> E, F
    
    states[3].next0 = &states[6]; 
    states[3].next1 = &states[3]; // D -> G, D
    
    states[4].next0 = &states[7]; 
    states[4].next1 = &states[3]; // E -> H, D
    
    states[5].next0 = &states[1]; 
    states[5].next1 = &states[0]; // F -> B, A
    
    states[6].next0 = &states[5]; 
    states[6].next1 = &states[2]; // G -> F, C
    
    states[7].next0 = &states[0]; 
    states[7].next1 = &states[4]; // H -> A, E

    // Set Starting State B and Print Initial Message
    State *current = &states[1]; 
    printf("%c\n", current->name);

    char line[100];
    
    // Command Loop
    while (fgets(line, sizeof(line), stdin)) {
		
		// No input given (0 character input)
        if (line[0] == '\n') continue;
        char cmd = line[0];

        // Transitions (1 character input)
        if (cmd == '0') {
            current = current->next0;
            printf("%c\n", current->name);
        } 
        else if (cmd == '1') {
            current = current->next1;
            printf("%c\n", current->name);
        }
        
        // Changing State Connections (ex. c0 A)
        else if (cmd == 'c') {
            int inputVal;
            char targetName;
            if (sscanf(line, "c %d %c", &inputVal, &targetName) == 2) {
                State *target = &states[targetName - 'A'];
                if (inputVal == 0) current->next0 = target;
                else current->next1 = target;
            }
        }
        
        // Print Current State Table
        else if (cmd == 'p') {
            for (int i = 0; i < 8; i++) {
                if (!states[i].deleted) {
                    printf("%c %c %c\n", states[i].name, states[i].next0->name, states[i].next1->name);
                }
            }
        }
        
        // Garbage/Delete Shared Logic
        else if (cmd == 'g' || cmd == 'd') {
			
            // Find Reachable States
            bool reachable[8] = {false};
            reachable[current->name - 'A'] = true;
            bool changed = true;
            while (changed) {
                changed = false;
                for (int i = 0; i < 8; i++) {
                    if (reachable[i] && !states[i].deleted) {
                        int n0 = states[i].next0->name - 'A';
                        int n1 = states[i].next1->name - 'A';
                        if (!reachable[n0]) { reachable[n0] = true; changed = true; }
                        if (!reachable[n1]) { reachable[n1] = true; changed = true; }
                    }
                }
            }
            
			// Garbage Command Logic
            if (cmd == 'g') {
                bool garbageFound = false;
                for (int i = 0; i < 8; i++) {
                    if (!states[i].deleted && !reachable[i]) {
                        if (!garbageFound) printf("Garbage: ");
                        printf("%c", states[i].name);
                        garbageFound = true;
                    }
                }
                if (!garbageFound) printf("No garbage");
                printf("\n");
            }
            
            // Delete Command Logic
            else if (cmd == 'd') {
                char targetName = '\0';
                if (sscanf(line, "d %c", &targetName) == 1) {
                    // Delete Specific
                    int idx = targetName - 'A';
                    if (idx >= 0 && idx < 8 && !reachable[idx] && !states[idx].deleted) {
                        states[idx].deleted = true;
                        printf("Deleted.\n");
                    } else {
                        printf("Not deleted.\n");
                    }
                } else {
                    // Delete All Garbage
                    bool deletedAny = false;
                    for (int i = 0; i < 8; i++) {
                        if (!states[i].deleted && !reachable[i]) {
                            if (!deletedAny) printf("Deleted: ");
                            printf("%c", states[i].name);
                            states[i].deleted = true;
                            deletedAny = true;
                        }
                    }
                    if (!deletedAny) printf("No states deleted.\n");
                    else printf("\n");
                }
            }
        }
    }

    exit(0);
}
