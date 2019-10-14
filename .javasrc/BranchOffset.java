public class BranchOffset {
  public static void main(String[] args) {
    for (int i = 8700; i <= 8750; i++) {
    	String s = "vou pra constant pool";
      	int dec_num, rem;
        String hexdec_num="";
        
        /* hexadecimal number digits */
        char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        dec_num = i;
		
        while(dec_num > 0) {
            rem = dec_num % 16;
            hexdec_num = hex[rem] + hexdec_num;
            dec_num = dec_num / 16;
        }
      
        System.out.println("Hexadecimal number is: " + hexdec_num);
      	String unicode_char = Character.toString((char)Integer.parseInt(hexdec_num, 16));
      	System.out.println("Unicode character is: " + unicode_char);	
    }
  }
}