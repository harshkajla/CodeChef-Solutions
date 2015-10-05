import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
public class Main {
	private static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
	private static int t,n;
	private static String str, shuffled;
	private static BigInteger ANS = BigInteger.ZERO, SUM = BigInteger.ZERO;
	
	private static void findsum(BigInteger[] input, int n, String str) {
		BigInteger A = new BigInteger(str);
		BigInteger sum = BigInteger.ZERO;
		
		for(int i=0;i<n;i++)
			sum = sum.add(A.mod(input[i]));
		
		if((sum.compareTo(SUM) < 0)|| SUM.equals(BigInteger.ZERO)){
			SUM = sum;
			ANS = A;
		}
	}
	
	private static void findLCyclic(BigInteger[] input, int n, String str){
		
		//displacing to the left
		for(int i = 1; i < str.length()-1; i*=2) {
			String newstr = str.substring(i) + str.substring(0,i);
			findsum(input, n, newstr);
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		//accepting T.
		t = Integer.parseInt(stdin.readLine());
		
		for(int i=0;i<t;i++) {
			
			//accepting A.
			str = stdin.readLine();
			
			ANS = BigInteger.ZERO;
			SUM = BigInteger.ZERO;
			
			n = Integer.parseInt(stdin.readLine());
			StringTokenizer tokenizer = new StringTokenizer(stdin.readLine());
			BigInteger inp[] = new BigInteger[n];
			
			for(int j=0;j<n;j++)
				inp[j] = new BigInteger(tokenizer.nextToken());
			
			//once with original string.
			findsum(inp, n, str);
			findLCyclic(inp, n, str);
			
			//then with reverse of string
			findsum(inp, n, new StringBuffer(str).reverse().toString());
			
			//ASC sorted string
			char[] chars = str.toCharArray();
			Arrays.sort(chars);
			String sorted = new String(chars);
			findsum(inp, n, sorted);
			
			//DESC sorted string
			sorted = new StringBuffer(sorted).reverse().toString();
			findsum(inp, n, sorted);
			
			findLCyclic(inp, n, sorted);
			
			//now with different shufflings.
			int index1 = str.length()/3;
			int index2 = index1<<1;
			String half1 = str.substring(0,index1);
			String half2 = str.substring(index1,index2);
			String half3 = str.substring(index2);
			
			for(int j=0;j<120;j++) {
				
				//shuffled string
				String temp = shuffleString(half1);
				String tem = shuffleString(half2);
				String te = shuffleString(half3);
				//half1 = temp;
				//half2 = tem;
				
				shuffled = temp + tem + te;
				findsum(inp, n, shuffled);
				
				//then reverse of shuffled string
				shuffled = te + tem + temp;
				findsum(inp, n, shuffled);			
			}
			
			//can also check with displaced string. left/right shift it in
			//cyclic order and then check.
			
			System.out.println(ANS);
		}
		
	}
	
	public static String shuffleString(String string)
	{
	  List<String> letters = Arrays.asList(string.split(""));
	  Collections.shuffle(letters);
	  String shuffled = "";
	  for (String letter : letters) {
	    shuffled += letter;
	  }
	  return shuffled;
	}
	
	public static String shuffle(String input){
        List<Character> characters = new ArrayList<Character>();
        for(char c:input.toCharArray()){
            characters.add(c);
        }
        StringBuilder output = new StringBuilder(input.length());
        while(characters.size()!=0){
            int randPicker = (int)(Math.random()*characters.size());
            output.append(characters.remove(randPicker));
        }
        return output.toString();
    }
}
