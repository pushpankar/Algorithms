public class SelectionSort extends Sorting{
	public static void main(String[] args){
		SelectionSort selectnSort=new SelectionSort();
		selectnSort.init(selectnSort);
	}
	public void sort(int[] unsortedArr){
		//Create an instance of Test class to take input from user
		Test test=new Test();
		for(int i=0;i<unsortedArr.length;i++){
			//This loop iterates over all the elements from 0
			int min=i;
			for(int j=i+1;j<unsortedArr.length;j++){
				//Here i am finding the lowest element in the remaining unsorted loop 
				if (unsortedArr[min]>unsortedArr[j]) {
					min=j;
				}
			}
			//Swaping the lowest element from the first element, thus increaing the size of the sorted array by 1.
			test.swap(unsortedArr,min,i);
		}
	}
}