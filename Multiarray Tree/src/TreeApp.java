
public class TreeApp {
    public static void main(String[] args){

        Tree<Patient> tree = new Tree<Patient>();
        tree.insert(new Patient("Paula Kevin",Severity.HIGH,1));
        tree.insert(new Patient("Maeva Leevi",Severity.EXTREMELY,10));
        tree.insert(new Patient("Andreas Reinhild",Severity.LITTLE,13));
        tree.insert(new Patient("Eli Jeremy",Severity.MINIMUM,7));
        tree.insert(new Patient("Taimi Luuk",Severity.MEDIUM,14));
        tree.insert(new Patient("Jordaan Chantal",Severity.LITTLE,3));
        tree.insert(new Patient("Justus Damian",Severity.EXTREMELY,18));
        tree.insert(new Patient("Patrice Decima",Severity.LITTLE,25));
        tree.insert(new Patient("Danièle Reinhold",Severity.HIGH,21));
        System.out.print("");

    }
}
