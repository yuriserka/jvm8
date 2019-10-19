public final class localvar {
    void instanceMethod(short argS, long argL) {
        int localI = argS;
        long localLong = argL;
    }

    static int staticMethod() {
        return 100;
    }

    int shared(boolean b) {
        if (b) {
            int i = 100;
            return i;
        } else {
            int j = 200;
            return j;
        }
    }
}