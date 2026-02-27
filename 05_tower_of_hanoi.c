/*
 * Program: Tower of Hanoi
 * Description:
 * This C program solves the Tower of Hanoi puzzle using recursion.
 * Users can specify the number of disks, and the program prints all the moves
 * required to transfer the disks from the source peg to the destination peg
 * using an auxiliary peg. It also calculates the total number of moves.
 * Features:
 * 1. Recursive solution for any number of disks.
 * 2. Prints each move in the format: "Move disk x from peg A to peg B".
 * 3. Calculates total number of moves using 2^n - 1 formula.
 */

#include <stdio.h>
#include <math.h>

void tower(int n, char from_peg, char aux_peg, char to_peg);

void main() {
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);

    tower(n, 'A', 'B', 'C'); // A -> from_peg, B -> aux_peg, C -> to_peg
    printf("\nTotal number of moves = %0.0f\n", pow(2, n) - 1);
}

void tower(int n, char from_peg, char aux_peg, char to_peg) {
    if (n == 1) {
        printf("\nMove disk %d from %c peg to %c peg", n, from_peg, to_peg);
        return;
    }

    // Move n-1 disks from from_peg to aux_peg using to_peg as auxiliary
    tower(n - 1, from_peg, to_peg, aux_peg);

    // Move the nth disk from from_peg to to_peg
    printf("\nMove disk %d from %c peg to %c peg", n, from_peg, to_peg);

    // Move n-1 disks from aux_peg to to_peg using from_peg as auxiliary
    tower(n - 1, aux_peg, from_peg, to_peg);
}

Enter the number of disks: 3
Move disk 1 from A peg to C peg
Move disk 2 from A peg to B peg
Move disk 1 from C peg to B peg
Move disk 3 from A peg to C peg
Move disk 1 from B peg to A peg
Move disk 2 from B peg to C peg
Move disk 1 from A peg to C peg
Total number of moves = 7
