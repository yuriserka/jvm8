public class Emoji implements Inter {
    public static void main(String[] args) {
        String[] emojis = {
            "😋", "😛", "🤑", "🤫", "🤨", "😬"
        };
        int dezao = 10;
        
        for (String s : emojis) System.out.println(s);
    }

    @Override
    public boolean m1() {
        return false;
    }
}