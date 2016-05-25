//Hyunchan Kim
public class QuickSort implements Sorter {

	public void sort(Comparable[] items, int cutoff) {
		quickSort(items, 0, items.length - 1);
	}

	private void quickSort(Comparable[] items, int left, int right) {
		if (left < right) {

			int pivot = partition(items, left, right);
			if (pivot - 1 > left) {
				quickSort(items, left, pivot - 1);
			}
			if (pivot + 1 < right) {
				quickSort(items, pivot + 1, right);
			}
		}
	}

	private int partition(Comparable[] items, int first, int last) {
		int pivot = (int) Math.floor(UtilityMethods.getPivot(first, last));
		UtilityMethods.swapElements(items, pivot, first);
		Comparable pivotElement = items[first];
		int swapPosition = first + 1;
		for (int currentElement = swapPosition; currentElement <= last; currentElement++) {
			if (items[currentElement].compareTo(pivotElement) < 0) {
				UtilityMethods
						.swapElements(items, swapPosition, currentElement);
				swapPosition++;
			}
		}
		UtilityMethods.swapElements(items, first, swapPosition - 1);
		return swapPosition - 1;
	}
}