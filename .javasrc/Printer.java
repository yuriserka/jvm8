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

        printInt(16320);
        printByte((byte)0x1F);
        printChar('x');
        printShort((short)10);
        printBool(true);
        printDouble(3.1516532);
        printFloat(1.1618f);
        printLong(161532165312L);
        printString("str sem dar o new String kkk");
    }

    private static void printByte(byte a) {
        System.out.println("byte = " + a);
    }

    private static void printInt(int a) {
        System.out.println("int = " + a);
    }

    private static void printChar(char a) {
        System.out.println("char = " + a);
    }

    private static void printShort(short a) {
        System.out.println("short = " + a);
    }

    private static void printBool(boolean a) {
        System.out.println("bool = " + a);
    }

    private static void printDouble(double a) {
        System.out.println("double = " + a);
    }

    private static void printFloat(float a) {
        System.out.println("float = " + a);
    }

    private static void printLong(long a) {
        System.out.println("long = " + a);
    }

    private static void printString(String a) {
        System.out.println("str = " + a);
    }
}