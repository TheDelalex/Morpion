#include <stdio.h>

/*Le jeu de morpion (ou tic-tac-toe) se joue généralement sur une grille de 3*3 cases ou de 5*5
    cases.*/
/*C'est au joueur de choisir la taille de son plateau entre 3x3 et 5x5*/

int choixTaille() {
    int n;
    printf("Choisissez la taille du tableau (3-5): ");
    scanf("%d", &n);
    if(n != 3 && n != 5) {
        printf("Taille invalide. Veuillez choisir entre 3 et 5. \n");
    }
}

int afficherGrille(char board[5][5], int n) {
    for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%c", board[i][j]);
                if(j < n - 1) printf("|");
            }
            printf("\n");
            if(i < n - 1) {
                for(int k = 0; k < n; k++) {
                    printf("-");
                    if(k < n - 1) printf("+");
                }
                printf("\n");
            }
        }
}

int CheckWin(char board[5][5], int n, char currentPlayer){
    int win = 0;
    for(int i = 0; i < n; i++) {
        if(board[i][0] == currentPlayer) {
            int rowWin = 1;
            for(int j = 1; j < n; j++) {
                if(board[i][j] != currentPlayer) {
                    rowWin = 0;
                    break;
                }
            }
            if(rowWin) win = 1;
        }
            if(board[0][i] == currentPlayer) {
                int colWin = 1;
                for(int j = 1; j < n; j++) {
                    if(board[j][i] != currentPlayer) {
                        colWin = 0;
                        break;
                    }
                }
                if(colWin) win = 1;
            }
        }
        if(board[0][0] == currentPlayer) {
            int diagWin = 1;
            for(int i = 1; i < n; i++) {
                if(board[i][i] != currentPlayer) {
                    diagWin = 0;
                    break;
                }
            }
            if(diagWin) win = 1;
        }
        if(board[0][n-1] == currentPlayer) {
            int diagWin = 1;
            for(int i = 1; i < n; i++) {
                if(board[i][n-1-i] != currentPlayer) {
                    diagWin = 0;
                    break;
                }
            }
            if(diagWin) win = 1;
        }
    return win;
}

int main() {
    // Choix de la taille du tableau
    int n;
    while (n != 5 && n != 3) n = choixTaille();

    // Initialisation du tableau
    char board[5][5] = {{' '}};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = ' ';
        }
    }

    char currentPlayer = 'X';
    int moves = 0;
    while(moves < n * n) {
        int row, col;
        printf("Joueur %c, entrez votre coup (ligne et colonne): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if(row-1 < 0 || row-1 >= n || col-1 < 0 || col-1 >= n || board[row-1][col-1] != ' ') {
            printf("Coup invalide. Essayez à nouveau.\n");
            continue;
        }
        board[row-1][col-1] = currentPlayer;
        moves++;

        afficherGrille(board, n);

        // Vérifier les conditions de victoire
        int win = 0;
        if (moves >= (2 * n - 1)) win = CheckWin(board, n, currentPlayer);

        if(win) {
            printf("Joueur %c gagne!\n", currentPlayer);
            return 0;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    printf("Match nul!\n");
    return 0;
}      


   

