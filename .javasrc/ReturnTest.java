public class ReturnTest {

    private static int last_index;
        
    public static void main(String[] args) {
        printInt(100);
        System.out.println("retorno de uma função " + returnInt());
        // ainda não funciona por causa do getStatic
        // System.out.println(getLastIndex());
    }

    private static int returnInt() {
        int x = 10;
        return x;
    }

    private static void printInt(int a) {
        System.out.println("Você me enviou R$ " + a + ",00. Obrigado!");
    }

    private static int getLastIndex() {
        return last_index++;
    }
}