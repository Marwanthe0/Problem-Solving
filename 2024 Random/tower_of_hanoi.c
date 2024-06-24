#include <stdio.h>

// Function to move disks
void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg);
    printf("Move disk %d from peg %c to peg %c\n", n, from_peg, to_peg);
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
}

int main() {
    int n;
    scanf("%d",&n); // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are names of pegs
    return 0;
}
