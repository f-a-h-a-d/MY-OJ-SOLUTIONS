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
 
            int[] a = new int[3];
 
            for(int i=0;i<3;i++){
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
 
            if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]){
                System.out.printf("Case %d: yes\n",k);
            }
            else{
                System.out.printf("Case %d: no\n",k);
            }
        }
 
    }
}