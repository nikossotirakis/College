#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char Name[50];
    int Age;
    int GameCount;
    int GoalCount;
} Player;

Player *stats(Player players[], int size) {
    Player *player = malloc(2 * sizeof(Player)); 

    if (player == NULL) return NULL;

    *(player + 0) = players[0];
    *(player + 1) = players[0];

    for (int i = 0; i < size; i++) {
        if (players[i].GoalCount > player[0].GoalCount) {
            player[0] = players[i];
        }

        if ((players[i].GoalCount / players[i].GameCount) > (player[0].GoalCount / player[0].GameCount)) {
            player[1] = players[i];
        }
    }

    return player;
}

int main(void) {
    int size = 0;
    Player arr[size];

    printf("Enter the array size: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter the name, age, games and goals of the player: ");
        scanf("%s%d%d%d", &arr[i].Name, &arr[i].Age, &arr[i].GameCount, &arr[i].GoalCount);
    }

    Player *topPlayers = stats(arr, size);

    free(topPlayers);

    return 0;
}