import java.util.Scanner;
 
class Main {
 
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        int tt = in.nextInt();
        int k = 0;
        int a, b;
        while(k<tt) {
            k++;
 
            a = in.nextInt();
            b = in.nextInt();
            System.out.printf("Case %d: %d\n",k,a+b);
        }
 
    }
}