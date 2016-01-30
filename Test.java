import java.util.Scanner;

public class Test{
	public static void main(String[] args) {
		//Create a object of this class since we can not call non static method from a static method.
		Test test=new Test();
		//keeping it interactive while reading  input from user
		System.out.print("Input Size:");
		//Getting the size of array
		Scanner scan=new Scanner(System.in);
		int size=scan.nextInt();

		int[] unsrtArr=new int[size];
		System.out.println("Input the elements");

		for(int i=0;i<size;i++){
			unsrtArr[i]=scan.nextInt();
		}
		//Here i am calling the sorting method
		/*@ToDo: IMPLEMENT A BETTER DESIGN PATTERN FOR IMPLEMENTING ALL SORTING ALGO BY USING THIS TEST CLASS*/
		InsertionSort insrtSort=new InsertionSort();
		insrtSort.sort(unsrtArr);

		//test.sort();
		
		test.printArray(unsrtArr);
		
	}
	//This method prints all the elements of an array
	public void printArray(int[] arr){
		for(int i : arr){
			System.out.print(i+" ");
		}
	}
	public void swap(int[] arr,int pos1,int pos2){
		int temp=arr[pos2];
		arr[pos2]=arr[pos1];
		arr[pos1]=temp;
	}
	//public abstract void sort();
}