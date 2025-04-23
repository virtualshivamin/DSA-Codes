#include <stdio.h>

// Function to solve Tower of Hanoi puzzle
void hanoi(int disks, char fromRod, char helperRod, char toRod) {
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", fromRod, toRod);
        return;
    }
    hanoi(disks - 1, fromRod, toRod, helperRod);
    printf("Move disk %d from %c to %c\n", disks, fromRod, toRod);
    hanoi(disks - 1, helperRod, fromRod, toRod);
}

int main() {
    int totalDisks;

    printf("Enter number of disks: ");
    scanf("%d", &totalDisks);

    hanoi(totalDisks, 'A', 'B', 'C');

    return 0;
}
