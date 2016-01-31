public class InsertionSort{
	public static void main(String[] args){
		Test test=new Test();
		InsertionSort inrstSort=new InsertionSort();
		int[] inputArray=test.getData();
		inrstSort.sort(inputArray);
		test.printArray(inputArray);
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