class BranchTest {
    public static void main(String[] args) {
        int i = 1;
        if (i == 1) {
            System.out.println("i == 1");
        }
        if (i -1 == 0) {
            System.out.println("i - 1 == 0");
        }
        if ((i & 0x1F) > 0) {
            System.out.println("i & 0x1F = " + (i & 0x1F));
        }
        if (((i << 8) & 0x1F) >= 0x4 ) {
            System.out.println("(i << 8) & 0x1F) >= 0x4");
        } else if (((i + 2 >> 8 << 7) < 0xFFF) || (i - (32 ^ 0x3) == 0xFA)) {
            System.out.println("(i + 2 >> 8 << 7) < 0xFFF || i - (32 ^ 0x3)");
        } else {
            System.out.println("else");
        }
        Object o1 = new Object(), o2 = new Object();
        if (o1 == o2) {
            System.out.println("o1 == o2");
        } else {
            o1 = o2;
        }
        if (o1 == o2) {
            System.out.println("agora são iguais mesmo");
        }
        String str = null;
        if (str != null) {
            str = "notNull????";
        }
        System.out.println("str antes = " + str);
        str = new String("KKAKAAKKA");
        o1 = str; 
        // if (o1 instanceof String) {
        //     System.out.println("o1 agora é uma instancia de String");
        // }
        if (o1 == str) {
            System.out.println("o1 e str possuem o mesmo endereço");
        }
        System.out.println("o1 = " + o1);
        System.out.println("str = " + str);
    }
}