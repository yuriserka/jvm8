public class Switch {
    private static void enumSwitch() {
        final DayOfWeek day = DayOfWeek.FRIDAY;
        int result = 0;
        switch (day) {
            case MONDAY:
                result = 1;
                break;
            case TUESDAY:
                result = 2;
                break;
            case WEDNESDAY:
                result = 3;
                break;
            case THURSDAY:
                result = 4;
                break;
            case FRIDAY:
                result = 5;
                break;
            case SATURDAY:
                result = 6;
                break;
            case SUNDAY:
                result = 7;
                break;
        }
    }
}

enum DayOfWeek {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
}