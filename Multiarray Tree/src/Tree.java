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
            }
        }
    }

    // ----------------------------------------------------------------------
    /**
     * @param current
     */

    private void split(Node<Σ> current) {
        //Assumes Node is full
        Σ middle,last;
        Node<Σ> parent, childTwo, childThree;
        int index;

        last = current.removeItem();
        middle = current.removeItem();
        childTwo = current.disconnectChild(2);
        childThree = current.disconnectChild(3);


    }

    // ----------------------------------------------------------------------
    // ----------------------------------------------------------------------
    // ----------------------------------------------------------------------
    // ----------------------------------------------------------------------


}
