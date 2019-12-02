class ExceptionTest {
    public static void main(String[] args) throws Exception {
        Exception ex = new Exception("Ola mundo");
        try {
            int x = 1, y = 2;
            double h = x/y;
            System.out.println("half = " + h);
            throw ex;
        } catch (final Exception e) {
            System.out.println("peguei");
        }
        testa();
    }

    static void testa() throws Exception {
        throw new Exception("sai de outra funçõa");
    }
}