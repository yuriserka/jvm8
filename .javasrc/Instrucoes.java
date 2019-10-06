public class Instrucoes {
    private int idade = 20;
    private final double semestre = 6.5;
    private final String professor = "Ladeira";
    public static int nota = 10;

    static void BYTE() {
        byte x = 22;
        byte[] ba = {1,23,4};
        byte y = ba[2];
    }

    static final char CHAR() {
        char c = 'c';
        return c;
    }

    public final String CONSTPOOL() {
        String pp = this.professor;
        double prox_semestre = this.semestre + 0.5;

        return pp;
    }

    public double DOUBLE() {
        double dk = 0;
        double di = (double) 1;
        double df = (double) 2.5f;
        double x = 1.2 + 3.8 - (4.1 * 5.0/2.0);

        return x;
    }

    static float FLOAT() {
        float fk = 0.0f;
        float fi = (float) 4;
        float fd = (float) 45.647684564;

        float x = (1.2f + 2.2f) * 3.2f/4.67f;
        return fk;
    }

    static int INTEGER() {
        int ik = 0;
        ik = 654654654;
        int iff = (int) 7.2f;
        int id = (int) 10.2456;
        int iinc = ik++;
        iinc--;

        int x = 1+2-3*(4/2);

        return x;
    }

    private static long LONG() {
        long lk = 1;
        long li = (long) 980;
        long ld = (long) 6468.864;
        long lf = (long) 2131.34f;

        long x = 32132121313213L+3165165464646L-54654646L*(5313156L/2313131L);

        return x;
    }

    private final Object REFERENCE() {
        Object[] objs = new Object[5];

        return objs[3];
    }

    private final void GOTO() {
        for (int i = 0; i < 1; i++) continue;
        do {} while (false);
        if (professor == null) {
            nota = -1;
        }
        return;
    }

    public static void main(String[] args) {
        String especial = "tenho \ttabs\trs \\:";
        especial += "\\\"hahahahah\\\"";
    }
}