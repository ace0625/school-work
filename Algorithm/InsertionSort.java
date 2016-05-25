//Hyunchan Kim
public class InsertionSort implements Sorter {

	public void sort(Comparable[] items, int cutoff) {
		insertionSort(items);
	}
	private void insertionSort(Comparable[] items) {
		for (int i = 1; i < items.length; i++) {
			int swappingIndex = i;
			Comparable currentItem = items[i];
			while ((swappingIndex > 0)
					&& (items[swappingIndex - 1].compareTo(currentItem) > 0)) {
				items[swappingIndex] = items[swappingIndex - 1];
				swappingIndex--;
			}
			items[swappingIndex] = currentItem;
		}
	}
}
