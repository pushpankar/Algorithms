public class InsertionSort{
	public void sort(int[] unsorted){
		for (int i=1;i<unsorted.length; i++ ) {
			System.out.println("Test data "+i +" "+unsorted.length);
			int j=i;
			while(j>0 && unsorted[j]<unsorted[j-1] ){
				System.out.println("IN WHILE "+j);
				swap(unsorted,j,j-1);
				System.out.println("IN WHILE2 "+j);
				j--;
			}
		}
	}
	private void swap(int[] arr,int pos1,int pos2){
		int temp=arr[pos2];
		arr[pos2]=arr[pos1];
		arr[pos1]=temp;
	}
}