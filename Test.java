import java.util.Scanner;

public class Test{
	public int[] getData(){
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
		return unsrtArr;
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
}