import java.util.*;
import java.lang.Math;
import static java.lang.System.*;
  
class MaximumSumWithDistanceK { 
  
    static int maxSum(int arr[], int N, int k) { 
        // MS[i] is going to store maximum sum 
        // subsequence in subarray from arr[i] 
        // to arr[n-1] 
        int MS[] = new int[N];
  
        // We fill MS from right to left. 
        MS[N - 1] = arr[N - 1]; 
        for (int i = N - 2; i >= 0; i--) { 
            if (i + k >= N) 
                MS[i] = Math.max(arr[i], MS[i + 1]); 
            else
                MS[i] = Math.max(arr[i] + MS[i + k], MS[i + 1]); 
        } 
  
        return MS[0]; 
    } 
  
    public static void main(String[] args) { 
        Scanner sc = new Scanner(in);
        String[] line = sc.nextLine().split(" ");
        int n = line.length, k, i = 0;
        int[] arr = new int[n];

        for (String s: line)
            arr[i++] = Integer.parseInt(s);

        k = Integer.parseInt(sc.nextLine());
        out.println(maxSum(arr, n, k));
    } 
}