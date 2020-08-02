import java.lang.reflect.Array;
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
 
            int a,b;
            a = in.nextInt();
            b = in.nextInt();
 
            int r = Math.abs(a - b) + Math.abs(0 - a);
 
            System.out.printf("Case %d: %d\n",k,r*4 + 19);
        }
 
    }
}