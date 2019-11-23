public class DoubleTest {
    public static void main(String[] args) {
        double a,b,c,d,e,f,g,h;
        a = 1.25;
        b = a - 3.0;
        c = -b;
        d = c + a;
        e = 15.0 % d;
        f = e / (b*a);
        g = (int)a;
        h = 1.0+2.0*3.0/5.0%8.0*9.0;
        System.out.println((long)a + "\n" + (float)b + "\n" + c + "\n" + d + "\n" + e + "\n" + f + "\n" + g + "\n" + h);
    }
}