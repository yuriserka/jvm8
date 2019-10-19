import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

interface ListaInteira {
  List<Integer> list = new ArrayList<Integer>();

  void printList();
}

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
    list.stream().map((x) -> x * x).forEach(System.out::println);
  }

  void doidera() {
    ListaInteira obj1 = new ListaInteira() {
      @Override
      public void printList() {
        this.list.forEach(System.out::println);
      }
    };
    obj1.list.add(10);
    obj1.list.add(12);
    obj1.list.add(13);
    obj1.printList();
  }
}
