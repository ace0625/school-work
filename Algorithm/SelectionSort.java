//Hyunchan Kim

public class SelectionSort implements Sorter {

	private int smallestIndex = 0;

	private int counter;

	@Override
	public void sort(Comparable[] items, int cutoff) {

		if (items.length > 1) {
			selectionSort(items);
		}
	}

	private void selectionSort(Comparable[] items) {
		counter = 0;
		while (counter < items.length - 1) {
			smallestIndex = counter;
			for (int j = counter + 1; j < items.length; j++) {

				if (items[j].compareTo(items[smallestIndex]) < 0) {
					smallestIndex = j;
				}
			}
			if (smallestIndex != counter) {
				UtilityMethods.swapElements(items, counter, smallestIndex);
			}
			counter++;
		}
	}
}
