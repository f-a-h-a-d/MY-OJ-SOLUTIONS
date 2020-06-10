import java.io.*;

import java.lang.*;

import java.math.BigInteger;

import java.util.Scanner;


class Main {
    
   
	
public static void main (String[] args) {

	    
	  BigInteger a,b,c,k;

	   	  a = new BigInteger("11");

	    	  k = new BigInteger("0");

	    
	  Scanner in = new Scanner(System.in);

	    
	    String input;

	    
	    while(in.hasNext())
{

	        
	        input = in.next();

	        
	        b = new BigInteger(input);

	        
	        int d = b.compareTo(k);

	        
	        if(d==0)break;

				c = b.mod(a);
	        
	        
				int r = c.compareTo(k);

	        
	        if(r==0){
	      
	           
				System.out.println(input + " is a multiple of 11.");

	      		}
	       
 			else{
	           
	           
			System.out.println(input +  " is not a multiple of 11.");

	        }
	        
	    
	}
	    
	    
	   
	
	}

}