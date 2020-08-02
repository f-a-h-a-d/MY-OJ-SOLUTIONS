import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.lang.Math.*;
class Main {
 
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        int tt = in.nextInt();
        int k = 0;
 
        while(k<tt) {
            k++;
            String s1,s2;
            s1 = in.next();
            s2 = in.next();
 
            char c = s2.charAt(0);
            String s3;
            if(c=='-'){
                s3 = s2.substring(1);
                s2 = s3;
            }
 
            BigInteger big = new BigInteger(s1);
            BigInteger big2 = new BigInteger(s2);
            BigInteger zero = new BigInteger("0");
            System.out.printf("Case %d: ",k);
            if(big.mod(big2).equals(zero)){
                System.out.printf("divisible\n");
            }
            else{
                System.out.printf("not divisible\n");
            }
        }
 
    }
}