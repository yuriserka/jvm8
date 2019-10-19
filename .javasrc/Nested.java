public class Nested {
    private class Inner {
        public int getX() {
            return this.x;
        }

        private int x;
    }

    public class Inner2 {
        public int y;
    }

    public final float getX() {
        return 1.0f;
    }

    @Deprecated
    private void deprecated() {
        System.out.println("Pode usar n kkk");
    }
}