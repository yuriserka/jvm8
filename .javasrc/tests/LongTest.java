public class LongTest {
    public static void main(String[] args) {
        long b,c,d,e;
        int a = (int) 50L;
        b = a - 40L;
        c = -b;
        d = c + a;
        e = 1000000000000000L % (d*111111111111L);
        System.out.println((long)a + "\n" + (float)b + "\n" + c + "\n" + d + "\n" + e);
        double f = (double)(e / (b*a));
        float g = (float)a;
        System.out.println(f + "\n" + g);
        double h = (double)((1000000000000L+26565120L*3553211L)/(5122322233323L%8000000000000L*900000000L));
        long l = (long)(c*1000000000000000L << 5000000000000000000L) | (long)1335131313313135L << 10000000000000000L;
        l += d;
        System.out.println(15 + "\n" + l + "\n" + a);
        long m = 4000000000000L/200000000000L;
        int n = 32 & 0x1F, k = 89 | 23 + (int)(l - a);
        System.out.println(m + "\n\t" + n + "\n" + k);
        l += 20;
        h -= l;
        System.out.println("loucura com o L = " + l + " e H = " + h + "...");
        System.out.println((long)a + "\n" + (float)b + "\n" + c + "\n" + d + "\n" + (short)e + "\n" + f + "\n" + (char)(g + 15) + "\n" + h + "\n" + (c << 4 & 0x1F ^ (a >> b) | 0x20) + "\n" + l);
    }
}