public class Jogador {

    private final char simbolo;
    private int score;

    public Jogador() {
        this.simbolo = 'd';
    }

    public Jogador(char simbolo) {
        this.simbolo = simbolo;
        this.score = 0;
    }

    public final char getSimbolo() {
        return this.simbolo;
    }
}