class SwitchTest {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            int x = 1 + i << (4 ^ 5 >> i);
            int y = x % 10;
            switch (x) {
                case 2:
                    System.out.println(x);
                    break;
                case 128:
                    System.out.println(x);
                    break;
                case 144:
                    System.out.println(x);
                    break;
                default:
                    System.out.println("defualt, x = " + x);
                    break;
            }
            switch (y) {
                case 0:
                    System.out.println("zerin");
                    break;
                case 1:
                    System.out.println("umzin");
                    break;
                case 2:
                    System.out.println("doiszin");
                    break;
                case 3:
                    System.out.println("treszin");
                    break;
                case 4:
                    System.out.println("quatrin");
                    break;
                case 11:
                    System.out.println("cinquin");
                    break;
                case 6:
                    System.out.println("seiszin");
                    break;
                case 7:
                    System.out.println("setin");
                    break;
                case 8:
                    System.out.println("oitin");
                    break;
                case 9:
                    System.out.println("novin");
                    break;
                default:
                    System.out.println("is that possible ?????");
                    break;
            }
            System.out.println();
        }
    }
}