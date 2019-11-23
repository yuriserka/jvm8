public class IntegerTest {
    public static void main(String[] args) {
        int a,b,c,d,e;
        a = (byte) 50;
        b = a - 40;
        c = -b;
        d = c + a;
        e = 100 % d;
        System.out.println((long)a + "\n" + (float)b + "\n" + c + "\n" + d + "\n" + (short)e);
        double f = (double)(e / (b*a));
        float g = (float)a;
        System.out.println(f + "\n" + g);
        double h = 10+2*3/5%8*9;
        int l = a++;
        l += d;
        System.out.println(h + "\n" + l + "\na atualizado = " + a);
        int m = 4/2;
        int n = 32 & 0x1F, k = 89 | 23 + l - a;
        System.out.println(m + "\n\t" + n + "\n" + k);
        l += 20;
        h -= l;
        System.out.println("loucura com o L = " + l + " e H = " + h + "...");
        System.out.println((long)a + "\n" + (float)b + "\n" + c + "\n" + d + "\n" + (short)e + "\n" + f + "\n" + (char)(g + 15) + "\n" + h + "\n" + (c << 4 & 0x1F ^ (a >> b) | 0x20) + "\n" + l);
    }
}