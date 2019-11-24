class FunctionTest {
    public static void main(String[] args) {
        int a = 1000000;
        float b = 3.1451f;
        System.out.println("antes:\n\ta="+a+"\tb="+b);
        maisDeUmArgumento(a,b);
        System.out.println("depois:\n\ta="+a+"\tb="+b);
        short neg_cem = -100;
        varios(15, -358.65f, neg_cem, "Hello World!", new Emoji(15));
        variosCat2(3.1415984128653, 10000006516L, "Hello Again...", new Emoji("str ctr"));
        double[] arr = changeArray(10,20,30,40,50,60,70);
        for (double e : arr) {
            System.out.println(e);
        }
    }

    static void maisDeUmArgumento(int a, float b) {
        float temp = b;
        b = a;
        a = (int) temp;
        System.out.println("dentro:\n\ta="+a+"\tb="+b);
    }

    static void varios(int a, float b, short c, String d, Emoji e) {
        float temp = b;
        b = a;
        a = (int) temp;
        System.out.println("dentro:\n\ta="+a+"\tb="+b);
        System.out.println("short="+c+"\nemoji feio? "+e.m1());
        System.out.println(d);
    }

    static void variosCat2(double d, long l, String s, Emoji e) {
        System.out.println("2x="+d+"\nemoji feio? "+e.m1());
        System.out.println(s);
        System.out.println("qual o tamanho do seu? " + l + "\t uau é longo msm!!");
    }

    static double[] changeArray(int... inteiros) {
        double[] q = new double[inteiros.length];
        int i = 0;
        for (int e : inteiros) {
            q[i] = (e - 0.5)/inteiros.length;
            i++;
        }
        return q;
    }
}