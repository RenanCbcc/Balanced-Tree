import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.Nullable;

public class Tree< Σ extends Hospital > {

    private Node<Σ> root;

    public Tree(){
        root = new Node<Σ>();
    }

    /**
     * This process can be done by recursion, however for simplicity it is currently implemented iteratively.
     * @param object
     * @return
     */
    // ----------------------------------------------------------------------
    public Σ find(Σ object){
        Node<Σ> current = root;
        int index;
        while (true){
            if((index = current.findItem(object)) != -1){
                return (Σ) current.getItem(index); // Found it.
            }else if(current.isLeaf()){
                return null; //Cannot find it.
            }else{
                current = getNextChild(current,object);
            }
        }

    }

    // ----------------------------------------------------------------------
    /**
     * This method verify whether is necessary go to left or right.
     * @param current
     * @param object
     * @return
     */
    @Nullable
    @Contract(pure = true)
    private Node<Σ> getNextChild(Node<Σ> current, Σ object) {
        //Assumes the Node is not full, empty or leaf.
        int items = current.getNumberOftems();
        for(int i = 0; i<= items; i++){
            if(object.getTicket()<current.getItem(i).getTicket())
            {
                return current.getChild(i);
            }
        }
        return null;
    }

    // ----------------------------------------------------------------------
    public void insert(Σ object){
        Node<Σ> current = root;
        while (true){
            if (current.isFull()){
                split(current);
                current = current.getParent(); //Back up
                current =getNextChild(current,object);
            } else if(current.isLeaf()){
              break;
              //Node is full, not lef, going to a lower level.
            }else{
                current = getNextChild(current,object);
            }
        }

        current.insertItem(object);
    }

    // ----------------------------------------------------------------------
    /**
     * @param current
     */

    private void split(Node<Σ> current) {
        //Assumes Node is full
        Σ middle,last; // The cells of content are arranged like this (First/middle/Last) inside every Node.
        Node<Σ> parent, childTwo, childThree;
        int index;

        last = current.removeItem();
        middle = current.removeItem();
        childTwo = current.disconnectChild(2);
        childThree = current.disconnectChild(3);

        Node<Σ> newRightNode = new Node<Σ>();

        if(current == root){
            root = new Node<Σ>();
            parent = root;
            root.connectChild(0,current);
        }else{
            parent = current.getParent();
        }
        index = parent.insertItem(middle);
        int n = parent.getNumberOftems();

        for(int i = n-1; i>index; i--){ //Start on right.
            Node<Σ> temp = parent.disconnectChild(i);
            parent.connectChild(i+1,temp);
        }
        parent.connectChild(index+1,newRightNode);
        newRightNode.insertItem(last);
        newRightNode.connectChild(0,childTwo);
        newRightNode.connectChild(0,childThree);

    }

    // ----------------------------------------------------------------------
    public void displayTree(Node<Σ> current,int level, int index){
        System.out.println("Level: "+level+"Child number: "+index+ " ");
        current.displayNode();
        int numberOfItems = current.getNumberOftems();
        for(int i = 0; i< numberOfItems; i++){
            Node<Σ> next = current.getChild(i);
            if(next != null){
                displayTree(next,level+1,i);

            }else {
                return;
            }
        }
    }
    // ----------------------------------------------------------------------
}
