public class Jogo {
    static Tabuleiro tab = new Tabuleiro(3, 3);
    static Jogador[] jogadores = {new Jogador('o'), new Jogador('x')};

    public static void main(String[] args) {
        System.out.println("Jogadores em campo:");
        System.out.println(jogadores[0].getSimbolo()+"\tVS\t"+jogadores[1].getSimbolo());
        
        int vez_jogador = 0;
        
        jogar(vez_jogador++, 0, 0);
        jogar(vez_jogador++, 0, 1);
        jogar(vez_jogador++, 1, 2);
        jogar(vez_jogador++, 2, 1);
        jogar(vez_jogador++, 1, 1);
    }

    static void jogar(int vez_jogador, int x, int y) {
        System.out.println("Vez do Jogador: " + jogadores[vez_jogador % jogadores.length].getSimbolo());
        tab.mudarTabuleiro(x, y, jogadores[vez_jogador % jogadores.length]);
        tab.printTabuleiro();
    }
}