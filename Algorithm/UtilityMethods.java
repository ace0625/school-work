//Hyunchan Kim

public class UtilityMethods {

	public static void swapElements(Comparable[] items, int elementIndex_a,
			int elementIndex_b) {
		Comparable temp = items[elementIndex_a];
		items[elementIndex_a] = items[elementIndex_b];
		items[elementIndex_b] = temp;
	}

	public static int getPivot(int left, int right) {
		return left + (int) (Math.random() * ((right - left) + 1));
	}
}
