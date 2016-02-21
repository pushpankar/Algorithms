public class InsertionSort extends Sorting{
	public static void main(String[] args){
		InsertionSort insertSort=new InsertionSort();
		insertSort.init(insertSort);
	}
	public void sort(int[] unsorted){
		Test test=new Test();
		for (int i=1;i<unsorted.length; i++ ) {
			//This first loop picks up an element starting from pos=1 to end
			int j=i;
			//Then it compares and swaps with all previous elements until it finds a smaller element.
			//The size of the sorted array keeps on increasing i.e. it is stable.
			while(j>0 && unsorted[j]<unsorted[j-1] ){
				test.swap(unsorted,j,j-1);
				j--;
			}
		}
	}
	
}