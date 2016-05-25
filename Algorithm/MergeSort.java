//Hyunchan Kim

public class MergeSort implements Sorter {

	public void sort(Comparable[] items, int cutoff) {

		if (items.length > 1) {

			Comparable[] tempArray = new Comparable[items.length];

			mergeSort(items, tempArray, 0, items.length - 1);
		}
	}

	private static void mergeSort(Comparable[] items, Comparable[] temp,
			int left, int right) {
		if (left < right) {
			int centre = (int) Math.floor(left + right) / 2;
			mergeSort(items, temp, left, centre);
			mergeSort(items, temp, centre + 1, right);
			merge(items, temp, left, centre, right);
		}
	}

	private static void merge(Comparable[] items, Comparable[] temp,
			int firstIndex, int centre, int lastIndex) {
		for (int i = firstIndex; i <= lastIndex; i++) {
			temp[i] = items[i];
		}
		int currentLeftIndex = firstIndex;
		int currentRightIndex = centre + 1;
		int i = firstIndex;
		while (currentLeftIndex <= centre && currentRightIndex <= lastIndex) {
			if (temp[currentLeftIndex].compareTo(temp[currentRightIndex]) < 0) {
				items[i] = temp[currentLeftIndex];
				currentLeftIndex++;
				i++;
			} else {
				items[i] = temp[currentRightIndex];
				currentRightIndex++;
				i++;
			}
		}
		while (currentLeftIndex <= centre) {
			items[i] = temp[currentLeftIndex];
			currentLeftIndex++;
			i++;
		}
		while (currentRightIndex <= lastIndex) {
			items[i] = temp[currentRightIndex];
			currentRightIndex++;
			i++;
		}
	}
}