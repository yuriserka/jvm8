class Esfera extends Objeto {
    private double raio;

    Esfera(int x, int y, double r) {
        super(x, y);
        this.raio = r;
    }

    @Override
    public double area() {
        return 3.14159*this.raio*this.raio;
    }

    @Override
    public boolean colidiu(Objeto other) {
        return this.getX() == other.getX();
    }
}