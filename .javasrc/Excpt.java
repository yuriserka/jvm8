public class Excpt {
    public static void main(String[] args) {
        String s = null;
        try {
            s = s + null;
        } catch(NullPointerException e) {
            e.printStackTrace();
        }
    }
}