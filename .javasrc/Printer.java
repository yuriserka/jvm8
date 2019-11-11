public class Printer {
    public static void main(String[] args) {
        long longo = 10000L;
        char interrogacao = '?';
        boolean tu_eh = false;
        String nome = "Ladeira";
        double nota = 99.97;
        float vel = 120.15f;
        byte b = 127;
        short s = 10;
        Object obj = new Object();
        System.out.println("Bodia " + nome + ", por acaso o append só concatena de 2 em 2" + interrogacao);
        System.out.println("Se sim, então tiramos nota " + nota);
        System.out.println(nome + " eu te odeio " + longo + "%");
        System.out.println("Tu eh gay mano" + interrogacao + " " + tu_eh);
        System.out.println("vim pra UnB voando a " + vel + " km/h");
        System.out.println("esse short foi R$" + s + ".00 testando o byte " + b);
        System.out.println("endereco do obj = " + obj);
    }
}