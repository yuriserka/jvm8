abstract class Objeto implements Collider {
    private int pos_x;
    private int pos_y;
    private static int id;

    public Objeto(int x, int y) {
        this.pos_x = x; 
        this.pos_y = y; 
        id++;
    }

    public int getX() {
        return this.pos_x;
    }

    public int getY() {
        return this.pos_y;
    }

    public abstract double area();
}