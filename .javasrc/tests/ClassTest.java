public class ClassTest {
    public static void main(String[] args) {
        Numerais nums = new Numerais();
        System.out.println("Field Numerais.d = " + nums.d);

        int um_mais_um_pouco = nums.getUm() + 357;
        // o javac n compila se for privado...
        // System.out.println("Nums.str = " + nums.str);
        um_mais_um_pouco++;
        System.out.println("somando com local var = " + um_mais_um_pouco);
        System.out.println("construtor custom = " + new Numerais(200).getUm());

        Numerais num2 = new Numerais();
        num2.setInteger(86451);
        System.out.println("set = " + num2.getUm());

        Pessoa p = new Pessoa();
        System.out.println("pessoa linda de nome = " + p.getNome());
        p.setNome("joão Kleber");
        System.out.println("pessoa linda de nome = " + p.getNome());
        
        System.out.println("nacionalidade da pessoa linda = " + p.nacionalidade);
        p.nacionalidade = "Canadense";
        System.out.println("nacionalidade da pessoa linda depois de fazer o passaporte = " + p.nacionalidade);

        System.out.println("indo pro xops comprar pastel KKK");
        p.realizarCompra(5.50);
    }
}