import java.util.Scanner;
import java.lang.Math.*;
class Main {
 
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        int tt = in.nextInt();
        int k = 0;
 
        while(k<tt) {
            k++;
 
            double r = in.nextDouble();
            double a = (r+r)*(r+r)*1.0 + 10e-9;
            double x = 2 * Math.acos(0.0) * r * 1.0 * r + 10e-9;
 
            double ans = (a - x)+1e-9;
            System.out.printf("Case %d: %.2f\n",k,ans);
        }
 
    }
}