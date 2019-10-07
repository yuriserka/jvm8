import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Lambida {
  public static void foo() {
    List<String> list = new ArrayList<String>();
    list.add("Hello");
    list.add("World");
    list.forEach( s -> { System.out.println(s); } );
  }
  
  public static void main(String[] args) {
    foo();
  }
}
