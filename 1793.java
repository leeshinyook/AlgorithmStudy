
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger[] num = new BigInteger[252];
        num[0] = new BigInteger("1");
        num[1] = new BigInteger("1");
        num[2] = new BigInteger("3");
        for(int i = 3; i < 252; i++) {
            num[i] = num[i - 1].add(num[i - 2].multiply(BigInteger.valueOf(2)));
        }
        while(true) {
            String line = br.readLine();
            if(line == null) break;
            int n = Integer.parseInt(line);
            System.out.println(num[n]);
        }
    }
}
