public class ReturnTest {

    private static int last_index;
        
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
        
        // ainda não funciona por causa do getStatic
        // System.out.println(getLastIndex());
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

    private static int getLastIndex() {
        return last_index++;
    }
}