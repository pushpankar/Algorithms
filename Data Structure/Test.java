public class Test{
	public static void main(String[] args) {
		LinkedList ll=new LinkedList();
		ll.insert(1);
		ll.insert(4);
		ll.insert(9);
		ll.insert(5);
		ll.insert(1);
		ll.insert(4);
		ll.insert(199,0);
		ll.insert(8,8);
		ll.display();
		System.out.println("Done and length is "+ll.size);

		ll.search(199);
		ll.search(8);
		ll.search(4);
		ll.search(27);

		ll.delete(9);
		ll.delete(199);
		ll.display();
	}
}