#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>

#define GROUND_HEIGHT 2
#define JUMP_HEIGHT 5

int dinoPosition = 5;

void drawGame() {
    system("cls"); 

    for (int i = 0; i < GROUND_HEIGHT; i++) {
        printf("\n");
    }

    for (int i = 0; i < dinoPosition; i++) {
        printf(" ");
    }
    printf("Ã¢â€“Â²\n");

    for (int i = 0; i < 30 - dinoPosition; i++) {
        printf(" ");
    }
    printf("Ã¢â€“Ë†Ã¢â€“Ë†");
}

int main() {
    char key;
    int isJumping = 0;

    srand(time(NULL));

    while (1) {
        drawGame();

        if (kbhit()) {
            key = getch();
            if (key == ' ' && !isJumping) {
                isJumping = 1;
            }
        }

        if (isJumping) {
            dinoPosition += 2;
            if (dinoPosition >= 20) {
                isJumping = 0;
            }
        } else {
            dinoPosition -= 2;
            if (dinoPosition <= 5) {
                dinoPosition = 5;
            }
        }

        // Randomly spawn obstacles
        if (rand() % 10 == 0) {
            printf("\n\n");
            for (int i = 0; i < 30 - dinoPosition; i++) {
                printf(" ");
            }
            printf("Ã¢â€“Ë†Ã¢â€“Ë†");
        }

        // Simulate gravity by adding a delay
        
    }

    return 0;
}
