class ArrayTest {
    public static void main(String[] args) {
        int[] inteiros = {0, 10, 20, 30, 40, 50};
        double[] reais = {0.01, 0.02, 0.03, 0.04, 0.05};
        float[] quantis = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
        long[] enormes = {1000000000000000L, 2000000000000000L, 30000000000000L};
        String[] autores = {"Gabriel Castro", "Cláudio Barros", "Matheus Breder", "Yuri Serka"};
        char[] alfabeto = {'a', 'b', 'c', 'd'};
        byte[] code = {0xA, 0x6, 0x03, 0x04, 0x6C};
        short[] bermudas = {1000, 2000, 3000, 4000, 5112, 8961};
        Emoji[] emojis = {new Emoji(10), new Emoji("será q da?")};

        System.out.println(emojis[0].m1());

        System.out.println(inteiros[2]);
        System.out.println(reais[4]);
        System.out.println(quantis[3]);
        System.out.println(enormes[1]);
        System.out.println(autores[3]);
        System.out.println(alfabeto[1]);
        System.out.println(bermudas[5]);

        System.out.println("Bytecode:\n0: bipush " + code[1] + "\n2: iconst_0\n3: iconst_1\n4: idiv");

        for (String a : autores) {
            System.out.println(a);
        }

        modificar(autores);

        System.out.println("Qual o autor no index 0?? " + autores[0]);

        System.out.println("Testando array 3D");
        int[][][] test = {
            {
                {1, -2, 3},
                {2, 3, 4}
            },
            {
                {-4, -5, 6, 9},
                {1},
                {2, 3}
            }
        };

        for (int[][] array2D : test) {
            for (int[] array1D : array2D) {
                for(int item : array1D) {
                    System.out.println(item);
                }
            }
        }
    }

    static void modificar(String[] arr) {
        arr[0] = "Albert Einstein";
    }
}