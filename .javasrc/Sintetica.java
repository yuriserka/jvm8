public final class Sintetica {
   public static void main(final String[] args) {
      Sintetica.NestedClass nested = new Sintetica.NestedClass();
      System.out.println("String: " + nested.highlyConfidential);
   }

   private static final class NestedClass {
      private String highlyConfidential = "Don't tell anyone about me";
      private int highlyConfidentialInt = 42;
      private double highlyConfidentialDouble = 3.14159;
      private boolean highlyConfidentialBoolean = true;
   }
}