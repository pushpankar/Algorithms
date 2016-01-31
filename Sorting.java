public abstract class Sorting{
/**Getting input for sorting and starting the method*/
	public void init(Sorting sorting) {
		Test test=new Test();
		int[] inputArray=test.getData();
		sorting.sort(inputArray);
		//finally printing the sorted array
		test.printArray(inputArray);
	}
	public abstract void sort(int[] unsortedArray);
}