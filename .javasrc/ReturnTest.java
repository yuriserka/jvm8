public class ReturnTest {

    public static void main(String[] args) {
        System.out.println("retorno int = " + returnInt());
        System.out.println("retorno byte = " + returnByte());
        System.out.println("retorno char = " + returnChar());
        System.out.println("retorno short = " + returnShort());
        System.out.println("retorno bool = " + returnBool());
        System.out.println("retorno double = " + returnDouble());
        System.out.println("retorno float = " + returnFloat());
        System.out.println("retorno long = " + returnLong());
        System.out.println("retorno str = " + returnString());

        for (int k : getInteiros()) {
            System.out.println("index="+k);
        }

        String[] n = getNomes("Putz");
        n[0] = "Foi alterado";
        for (int i = 0; i < n.length; i++) {
            System.out.println(n[i]);
        }
    }

    private static int returnInt() {
        int x = 10/2;
        return x;
    }

    private static byte returnByte() {
        byte x = 0x2f;
        return x;
    }

    private static char returnChar() {
        char x = '!';
        return x;
    }

    private static short returnShort() {
        short x = 16000;
        return x;
    }

    private static boolean returnBool() {
        boolean x = false;
        return x;
    }

    private static double returnDouble() {
        double x = 3.654651312;
        return x;
    }

    private static float returnFloat() {
        float x = (float)(7845/59);
        return x;
    }

    private static long returnLong() {
        long x = 111111111100000L;
        return x;
    }

    private static String returnString() {
        String x = "sem dar o new String() hein";
        return x;
    }
    
    private static int[] getInteiros() {
        return new int[]{0,1,2,3,5,1,2,5,1,2,5,4,1};
    }

    private static String[] getNomes(String lindo) {
        return new String[]{"A", "B", "C", "O +" + lindo + "???"};
    }

}