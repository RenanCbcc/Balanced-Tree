package tow_three_four_tree;

public class Node<Σ> {
	private static final int ORDER = 4;
	private int numItems;
	private Node<Σ> parent;
	private Node<Σ>[] childArray;
	private Σ[] itemArray;

	// ----------------------------------------------------------------------
	@SuppressWarnings("unchecked")
	public Node() {
		childArray = (Node<Σ>[]) new Object[ORDER - 1];
		itemArray = (Σ[]) new Object[ORDER - 1];
	}

	// ----------------------------------------------------------------------
	/**
	 * Connects child to this Node.
	 * 
	 * @param childNum
	 * @param child
	 */
	public void connectChild(int index, Node<Σ> child) {
		childArray[index] = (Node<Σ>) child;
		if (child != null) {
			child.parent = this;
		}
	}

	// ----------------------------------------------------------------------
	/**
	 * Disconnect child from its Nodes and returns it.
	 */
	public Node<Σ> disconnectChild(int index) {
		Node<Σ> temp = (Node<Σ>) childArray[index];
		childArray[index] = null;
		return temp;
	}

	// ----------------------------------------------------------------------
	public Node<Σ> getChild(int index) {
		return (Node<Σ>) childArray[index];
	}

	// ----------------------------------------------------------------------
	public Node<Σ> getParent() {
		return parent;
	}

	// ----------------------------------------------------------------------
	public boolean isLeaf() {
		return (childArray[0] == null) ? true : false;
	}

	// ----------------------------------------------------------------------
	public int getNumberOftems() {
		return numItems;
	}

	// ----------------------------------------------------------------------
	public Node<Σ> getItem(int index) {
		return childArray[index];
	}

	// ----------------------------------------------------------------------
	public boolean isFull() {
		return numItems == (ORDER - 1) ? true : false;
	}

	// ----------------------------------------------------------------------
	public int findItem(Σ object) {
		for (int i = 0; i <= ORDER; i++) {
			if (itemArray[i] == null) {
				break;
			} else if (itemArray[i] == object) {
				return i;
			}

		}
		return -1;
	}

	// ----------------------------------------------------------------------
	//ERRO HERE
	public int insertItem(Σ object) {
		// assumes node is not full
		numItems++;
		int newKey = ((Object) object).getTicket();

		for (int i = ORDER - 2; i >= 0; i--) {
			if (itemArray[i] == null) {
				continue; // Go left one cell.
			} else {
				int itsKey = ((Object) itemArray[i]).getTicket();
				if (newKey < itsKey) {
					itemArray[i + 1] = itemArray[i]; // Shift to right.
				} else {
					itemArray[i + 1] = object;
					return i + 1;
				}
			}
		}

		itemArray[0] = object;
		return 0;
	}

	// ----------------------------------------------------------------------
	public boolean isEmpty() {
		return itemArray[0] == null ? true : false;
	}
	
	// ----------------------------------------------------------------------
	public Σ removeItem() {
		if (isEmpty()) {
			System.out.println("The node is currently empty.");
		}
		
		Σ temp = itemArray[numItems-1];
		itemArray[numItems-1] = null;
		numItems--;
		return temp;
	}
	
	// ----------------------------------------------------------------------
	public void displayNode(){ //Format /24/56/74
		for(int i=0; i<numItems; i++){
			System.out.println(itemArray[i]);
		}
		System.out.println("/");
	}
}
