class Pessoa {

    private String nome;
    private int idade;
    private static String nacionalidade = "valor padrao";
    public double[] moedas = new double[]{0.05, 0.1, 0.25, 0.5, 0.75, 0.9, 1.0};

    public Pessoa() {
        this.nome = "anonimo";
    }

    public Pessoa(String nome, int idade) {
        this.setNome(nome);
        this.setIdade(idade);
    }

    void realizarCompra(double valor) {
        double total = 0.0;
        for (double d : this.moedas) {
            total += d;
        }
        if (total < valor) {
            System.out.println("Pse man... vai ficar sem");
            return;
        }
        System.out.println("Transação aprovada");
    }

    static void mudarNacionalidade(String n) {
        nacionalidade = n;
    }

    static String getNacionalidade() {
        return nacionalidade;
    }

    void setNome(String nome) {
        this.nome = nome;
    }

    String getNome() {
        return this.nome;
    }

    void setIdade(int idade) {
        if (idade <= 0) {
            System.out.println("Vc tem idade negativa seu arrombado???");
            // depois por pra lançar exceção
            return;
        } else {
            this.idade = idade;
        }
    }

    int getIdade() {
        return this.idade;
    }
}