import java.util.Scanner;

public class Test{
	public static void main(String[] args) {
		InsertionSort insrtSort=new InsertionSort();
		Scanner scan=new Scanner(System.in);
		System.out.print("Input Size:");
		int size=scan.nextInt();
		int[] unsrtArr=new int[size];
		System.out.println("Input the elements");

		for(int i=0;i<size;i++){
			unsrtArr[i]=scan.nextInt();
		}
		insrtSort.sort(unsrtArr);
		for(int i : unsrtArr){
			System.out.print(i+" ");
		}
	}
}