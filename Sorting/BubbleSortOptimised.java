import java.util.*;
import static java.lang.System.*;

class BubbleSortOptimised {

	/* Algorithm: Bubble Sort
	   1. Take input array
	   2. While n > 0:
	          currentIndex = -1
	          for (int i = 0; i < n - 1; i++)
		          if arr[i] > arr[i + 1]
				      currentIndex = i
			  if (currentIndex == -1)
			      break
		      swap(arr[currentIndex], arr[currentIndex + 1])
		      n = currentIndex
	 */

	public static void performBubbleSort(int[] arr) {
		int n = arr.length, temp, newn;

		while (n > 0) {
			newn = 0;
			
			for (int i = 0; i < n - 1; i++)
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					newn = i + 1;
				}

			n = newn;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(in);
		String[] line = sc.nextLine().split(" ");
		int[] arr = new int[line.length];
		int i = 0;

		for (String x: line)
			arr[i++] = Integer.parseInt(x);


		performBubbleSort(arr);

		out.println(Arrays.toString(arr));

	}
}