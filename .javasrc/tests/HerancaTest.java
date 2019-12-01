class HerancaTest {
    public static void main(String[] args) {
        // Objeto o = new Objeto();
        Objeto e = new Esfera(1, 1, 5);
        Objeto t = new Triangulo(2, 2, 10, 6);

        System.out.println("Area da esfera = " + e.area());
        System.out.println("Area do triangulo = " + t.area());
        System.out.println("Esfera colidiu com Triangulo = " + e.colidiu(t));
    }
}