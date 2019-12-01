class Triangulo extends Objeto {
    private double base;
    private double altura;

    Triangulo(int x, int y, double b, double h) {
        super(x, y);
        this.base = b;
        this.altura = h;
    }

    @Override
    public double area() {
        return this.base*this.altura/2;
    }

    @Override
    public boolean colidiu(Objeto other) {
        return this.getY() == other.getY();
    }
}