public class Methodparams {
    private String met1(final double a, double b) {
        boolean ok = b > 0.75 && a >= 5.0;
        if (ok) {
            return "Aprovado";
        }
        return "Vish...";
    }

    private String met1(final double... reais) {
        if (reais[0] == 0.0) {
            return "Zerinho";
        }
        return "ta no eixo";
    }

    public static void main(String args[]) {
        TwoArgInterface plusOperation = (a, b) -> a + b;
        System.out.println("Sum of 10, 34 : " + plusOperation.operation(10, 34));
    }
}

interface TwoArgInterface {
    public int operation(final int x, final int y);
}