public class Emoji implements Inter {

    public Emoji(String emoji) {
        System.out.println("oie");
    }

    public Emoji(int code) {
        System.out.println(code);
    }

    public static void main(String[] args) {
        Integer meuinteiro = new Integer(52);
        
        String[] emojis = {
            "😋", "😛", "🤑", "🤫", "🤨", "😬"
        };
        int dezao = 10;
        
        for (String s : emojis) System.out.println(s);

        System.out.println(meuinteiro);
    }

    @Override
    public boolean m1() {
        return false;
    }
}