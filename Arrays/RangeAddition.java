import java.util.*;

public class Main {

    public static int[] getModifiedArray(int length, int[][] queries) {
        int [] arr = new int[length];
        for(int q[] : queries)
        {
            arr[q[0]] += q[2];
            if(q[1] != length-1)
                arr[q[1]+1] -= q[2];
        }
        for(int i=1; i<length; i++)
        {
            arr[i] += arr[i-1];
        }
        return arr;
    }


    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        
        int length = scn.nextInt();

        int nq = scn.nextInt();
        
        int[][] queries = new int[nq][3];

        for(int q = 0; q < nq; q++) {
            queries[q][0] = scn.nextInt();
            queries[q][1] = scn.nextInt();
            queries[q][2] = scn.nextInt();
        }


        int[] res = getModifiedArray(length, queries);

        for(int i = 0; i < res.length; i++) {
            System.out.print(res[i] + " ");
        }
    }
}
