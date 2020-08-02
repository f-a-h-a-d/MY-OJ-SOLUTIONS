import java.util.Scanner;
 
class Main {
 
    public static void main(String[] args) {
        Scanner in  = new Scanner(System.in);
        int tt = in.nextInt();
        int k = 0;
 
        while(k<tt) {
            k++;
            int n;
            n = in.nextInt();
            int sum = 0;
            for(int i=0;i<n;i++){
                int x;
                x = in.nextInt();
                if(x>=0){
                    sum += x;
                }
            }
            System.out.printf("Case %d: %d\n",k,sum);
        }
 
    }
}