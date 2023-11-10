#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function prototypes
void startGame();
void enterRoom(char* room);
void handleInput(char* input);
// Room structure
typedef struct {
    char name[20];
    char description[100];
} Room;
// Define the rooms
Room kitchen = {"Kitchen", "You are in a small kitchen. There is a table and some chairs."};
Room bedroom = {"Bedroom", "You are in a cozy bedroom. There is a bed and a wardrobe."};
Room livingRoom = {"Living Room", "You are in a spacious living room. There is a sofa and a TV."};
Room bathroom = {"Bathroom", "You are in a clean bathroom. There is a sink and a bathtub."};
int main() {
    startGame();
    return 0;
}
void startGame() {
    printf("Welcome to the Text Adventure Game!\n");
    printf("You wake up in a strange house. You need to find a way out.\n");
    printf("Type 'help' for instructions.\n\n");
    enterRoom("kitchen");
}
void enterRoom(char* room) {
    if (strcmp(room, "kitchen") == 0) {
        printf("%s\n", kitchen.description);
    } else if (strcmp(room, "bedroom") == 0) {
        printf("%s\n", bedroom.description);
    } else if (strcmp(room, "living room") == 0) {
        printf("%s\n", livingRoom.description);
    } else if (strcmp(room, "bathroom") == 0) {
        printf("%s\n", bathroom.description);
    } else {
        printf("Invalid room.\n");
        return;
    }
    char input[20];
    printf("Enter a command: ");
    scanf("%s", input);
    handleInput(input);
}
void handleInput(char* input) {
    if (strcmp(input, "help") == 0) {
        printf("Commands: go [room], quit\n");
    } else if (strcmp(input, "quit") == 0) {
        printf("Game over. Thanks for playing!\n");
        exit(0);
    } else if (strncmp(input, "go ", 3) == 0) {
        char nextRoom[20];
        strcpy(nextRoom, input + 3);
        enterRoom(nextRoom);
    } else {
        printf("Invalid command.\n");
    }
}