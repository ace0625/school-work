//Hyunchan Kim

public class ShellSort implements Sorter {
	public void sort(Comparable[] items, int cutoff) {
		if (items.length > 1) {
			shellSort(items);
		}
	}

	private void shellSort(Comparable[] items) {
		for (int gap = items.length / 2; gap > 0; gap = gap == 2 ? 1
				: (int) (gap / 2.2))
			for (int i = gap; i < items.length; i++) {
				Comparable temp = items[i];
				int j;
				for (j = i; j >= gap && temp.compareTo(items[j - gap]) < 0; j -= gap) {
					items[j] = items[j - gap];
				}
				items[j] = temp;
			}
	}
}
