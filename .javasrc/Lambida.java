import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

public class Lambida {
  public static void foo() {
    List<String> list = new ArrayList<String>();
    list.add("Hello");
    list.add("World");
    list.forEach(System.out::println);
  }
  
  public static void main(String[] args) {
    foo();
  }

  void nonStaticfunc() {
    List<Integer> list = new ArrayList<Integer>();
    list.add(10);
    list.add(12);
    list.add(13);
    list.add(140);
    list.add(103);
    list.stream().map((x) -> x*x).forEach(System.out::println);
  }
}
