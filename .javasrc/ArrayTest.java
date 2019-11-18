class ArrayTest {
    public static void main(String[] args) {
        int[] inteiros = {0, 10, 20, 30, 40, 50};
        double[] reais = {0.01, 0.02, 0.03, 0.04, 0.05};
        float[] quantis = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
        long[] enormes = {1000000000000000L, 2000000000000000L, 30000000000000L};
        String[] autores = {"Gabriel Castro", "Cláudio Barros", "Matheus Breder", "Yuri Serka"};
        
        System.out.println(inteiros[2]);
        System.out.println(reais[4]);
        System.out.println(quantis[3]);
        System.out.println(enormes[1]);
        System.out.println(autores[3]);

        for (String a : autores) {
            System.out.println(a);
        }
    }
}