public class LinkedList implements LinkedListInterface{
	private Link first;
	public int size=0;
	public LinkedList(){
		first=new Link(null);
	}
	public void insert(int value){
		Link newLink=new Link(value);
		Link currentLink=first;
		while(currentLink.nextLink!=null){
			currentLink=currentLink.nextLink;
		}
		currentLink.nextLink=newLink;
		size++;
	}
	public void insert(int value, int position){
		Link newLink=new Link(value);
		Link currentLink=first;
		for (int i=0;i<position ;i++ ) {
			currentLink=currentLink.nextLink;
			if (currentLink==null) {
				System.out.println("Inserting "+value+" at end\n...");
				insert(value);
				size++;
				return;
			}
		}
		Link tempLink=currentLink.nextLink;
		currentLink.nextLink=newLink;
		newLink.nextLink=tempLink;
		size++;
	}
	public void display(){
		Link currentLink=first.nextLink;
		while(currentLink != null){
			System.out.println(" "+currentLink.data);
			currentLink=currentLink.nextLink;
		}
	}
	public Integer search(int value){
		Link currentLink=first.nextLink;
		int position=0;
		while(currentLink!=null && currentLink.data!=value){
			currentLink=currentLink.nextLink;
			position++;
		}
		if (currentLink==null) {
				System.out.println("Value "+value+ " not found");
				return null;
		}
		System.out.println("Found at position "+position);
		return position;
	}
	public void delete(int value){
		Integer position=search(value);
		if (position!=null) {
			Link toBeDeleted=first.nextLink;
			Link previousLink=first;
			for (int i=0;i<position ; i++) {
				previousLink=toBeDeleted;
				toBeDeleted=toBeDeleted.nextLink;
			}
			previousLink.nextLink=toBeDeleted.nextLink;
		}
		
	}

}