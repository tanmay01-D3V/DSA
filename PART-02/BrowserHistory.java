import java.util.Scanner;

public class BrowserHistory {
    private final String[] stack;
    private int top = -1;

    BrowserHistory(int capacity) { stack = new String[capacity]; }

    boolean isEmpty() { return top == -1; }
    boolean isFull()  { return top == stack.length - 1; }

    void visit(String page) {
        if (isFull()) { System.out.println("History is full. Cannot visit more pages."); return; }
        stack[++top] = page;
        System.out.println("Visited: " + page);
    }

    void back() {
        if (isEmpty()) { System.out.println("History is empty. Cannot go back."); return; }
        System.out.println("Closed: " + stack[top--]);
        current();
    }

    void current() {
        if (isEmpty()) System.out.println("No current page.");
        else System.out.println("Current page: " + stack[top]);
    }

    void display() {
        if (isEmpty()) { System.out.println("History is empty."); return; }
        for (int i = top; i >= 0; i--)
            System.out.println(stack[i] + (i == top ? "  <- TOP" : i == 0 ? "  <- BOTTOM" : ""));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("History capacity: ");
        BrowserHistory h = new BrowserHistory(Integer.parseInt(sc.nextLine().trim()));
        int ch;
        do {
            System.out.print("\n1.Visit 2.Back 3.Current 4.Display 5.Is empty 0.Exit\nChoice: ");
            ch = Integer.parseInt(sc.nextLine().trim());
            switch (ch) {
                case 1: System.out.print("Page: "); h.visit(sc.nextLine().trim()); break;
                case 2: h.back(); break;
                case 3: h.current(); break;
                case 4: h.display(); break;
                case 5: System.out.println("Empty: " + h.isEmpty()); break;
            }
        } while (ch != 0);
    }
}