import java.io.UnsupportedEncodingException;

public class BranchOffset {
  public static void main(String[] args) {
    int i = 8700;
    for (; i <= 9000; i++) {
      if (i % 4 == 0 && i % 5 == 0) {
        continue;
      } else {
        if (i % 3 != 0 && i % 7 == 0) {
          i++;
        }
      }
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
    
      System.out.println("Hexadecimal number is: 0x" + hexdec_num);
      try {
        String out = new String(Character.toString((char)Integer.parseInt(hexdec_num, 16)).getBytes(), "UTF-8");
        System.out.printf("unicode era pra ser = %s%n", out);
      } catch(final UnsupportedEncodingException uee) {
        uee.printStackTrace();
        break;
      } catch (final NumberFormatException nfe) {
        nfe.printStackTrace();
        break;
      }
    }
    System.out.println("só printa o unicode se for copiado e colado... => ∑");
    System.out.println("integral dupla ctrl+c ctrl+v => ∬ sin(x)cos(y)∂x∂y");
  }
}