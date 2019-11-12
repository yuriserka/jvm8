public class FloatTest {
    public static void main(String[] args) {
        float a,b,c,d,e,f,g,h;
        a = 1.25f;
        b = a - 3.0f;
        c = -b;
        d = c + a;
        e = 15.0f % d;
        f = e / (b*a);
        g = (int)a;
        h = 1.0f+2.0f*3.0f/5.0f%8.0f*9.0f;
        System.out.println((long)a + "\n" + (double)b + "\n" + c + "\n" + d + "\n" + e + "\n" + f + "\n" + g + "\n" + h);
    }
}