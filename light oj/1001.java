//Md Fahad

import java.util.Scanner;
 
class Main {
 
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        int tt = in.nextInt();
        int k = 0;
        int a;
        while(k<tt) {
            k++;
 
            a = in.nextInt();
            int val1,val2;
            int x = a & 1;
            if(x==1){
                val1 = (int)Math.ceil(a/2.0);
                val2 = a - val1;
            }
            else {
                val1 = a/2;
                val2 = a/2;
            }
            System.out.printf("%d %d\n",val1,val2);
        }
 
    }
}