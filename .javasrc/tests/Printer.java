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

        imprimir(16320);
        imprimir((byte)0x1F);
        imprimir('x');
        imprimir((short)10);
        imprimir(true);
        imprimir(3.1516532);
        imprimir(1.1618f);
        imprimir(161532165312L);
        imprimir("str sem dar o new String kkk");
    }

    private static void imprimir(byte a) {
        System.out.println("byte = " + a);
    }

    private static void imprimir(int a) {
        System.out.println("int = " + a);
    }

    private static void imprimir(char a) {
        System.out.println("char = " + a);
    }

    private static void imprimir(short a) {
        System.out.println("short = " + a);
    }

    private static void imprimir(boolean a) {
        System.out.println("bool = " + a);
    }

    private static void imprimir(double a) {
        System.out.println("double = " + a);
    }

    private static void imprimir(float a) {
        System.out.println("float = " + a);
    }

    private static void imprimir(long a) {
        System.out.println("long = " + a);
    }

    private static void imprimir(String a) {
        System.out.println("str = " + a);
    }
}