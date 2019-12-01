public class Tabuleiro {
    private char[][] tabuleiro;

    public Tabuleiro(int l, int c) {
        this.tabuleiro = new char[l][c];
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                tabuleiro[i][j] = '-';
            }
        }
    }

    public void mudarTabuleiro(int x, int y, Jogador jogador) {
        this.tabuleiro[x][y] = jogador.getSimbolo();
    }

    public void printTabuleiro() {
        for (char[] row : tabuleiro) {
            System.out.print("| ");
            for (char elem : row) {
                System.out.print(elem + " | ");
            }
            System.out.println();
        }
    }
}