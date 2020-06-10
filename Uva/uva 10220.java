import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main (String[] args) {
		
		    BigInteger one,b,k,c,sum,x,n;
		    
		    c = new BigInteger("1");
		    one = new BigInteger("1");
		    sum = new BigInteger("1");
		
		    Scanner in = new Scanner(System.in);
		    String input;
		    
		    while(in.hasNext())
		    {
		        input = in.next();
		        
		        BigInteger a = new BigInteger(input);
		        
		        while(true)
		        {
		            int r = c.compareTo(a);
		            
		             if(r==0)
           			break;
		            
		           x = c.add(one);
		           
		           c = x;
		            
		           n = sum.multiply(c);
		           sum = n;
		          
		        }
		        
		        String ADD;
		        
		         ADD = "" + sum;
		         
		        int sum1=0;
		        for(int i=0;i<ADD.length();i++)
		        {
		            sum1 += ADD.charAt(i)-'0';
		        }
		        
		        System.out.println(sum1);
		    }
		
		    
		}
}
