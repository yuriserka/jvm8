public class Methodparams {
    private String met1(final double a, double b) {
        boolean ok = b > 0.75 && a >= 5.0;
        if (ok) {
            return "Aprovado";
        }
        return "Vish...";
    }

    public static void main(String javalatte[]) {
        TwoArgInterface plusOperation = (a, b) -> a + b;
        System.out.println("Sum of 10, 34 : " + plusOperation.operation(10, 34));
    }
}

interface TwoArgInterface {
    public int operation(final int a, final int b);
}