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
 
            int x1,x2,y1,y2;
            x1 = in.nextInt();
            y1 = in.nextInt();
            x2 = in.nextInt();
            y2 = in.nextInt();
 
            int n;
            n = in.nextInt();
            System.out.printf("Case %d:\n",k);
            for(int i=0;i<n;i++){
                int a,b;
                a = in.nextInt();
                b = in.nextInt();
 
                if(a>= x1 && a<=x2 && b>=y1 && b<=y2){
                    System.out.printf("Yes\n");
                }
                else{
                    System.out.printf("No\n");
                }
            }
        }
 
    }
}