// import java.io.BufferedReader;
// import java.io.InputStreamReader;
// import java.io.IOException;
// import java.util.Stack;

// class Bracket {
//     Bracket(char type, int position) {
//         this.type = type;
//         this.position = position;
//     }

//     boolean Match(char c) {
//         if (this.type == '[' && c == ']')
//             return true;
//         if (this.type == '{' && c == '}')
//             return true;
//         if (this.type == '(' && c == ')')
//             return true;
//         return false;
//     }

//     char type;
//     int position;
// }

// class check_brackets {
//     public static void main(String[] args) throws IOException {
// InputStreamReader input_stream = new InputStreamReader(System.in);
// BufferedReader reader = new BufferedReader(input_stream);
// String text = reader.readLine();

//         Stack<Bracket> s = new Stack<Bracket>();
//         for (int position = 0; position < text.length(); ++position) {
//             char next = text.charAt(position);

//             if (next == '(' || next == '[' || next == '{') {
//                 // Process opening bracket, write your code here
//                 if (next == '(') {
//                     s.push(new Bracket(')', position));
//                 }
//                 if (next == '[') {
//                     s.push(new Bracket(']', position));
//                 }
//                 if (next == '{') {
//                     s.push(new Bracket('}', position));
//                 }
//             }

//             if (next == ')' || next == ']' || next == '}') {
//                 // Process closing bracket, write your code here
//                 Bracket b = new Bracket(next, position);
//                 if (!s.isEmpty() && s.lastElement() == b) {
//                     s.pop();
//                 } else {
//                     System.out.println(position);
//                 }
//             }
//         }

//         // Printing answer, write your code here
//         System.out.println("Success");
//     }
// }

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class check_brackets {
    public static Stack<Character> stk = new Stack<>();

    public static boolean validate(String str) throws IOException {
        int toBeMatched = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(' || str.charAt(i) == '{' || str.charAt(i) == '[') {
                if (str.charAt(i) == '(') {
                    stk.push(')');
                }
                if (str.charAt(i) == '{') {
                    stk.push('}');
                }
                if (str.charAt(i) == '[') {
                    stk.push(']');
                }
                toBeMatched = i;
            } else if (str.charAt(i) == ')' || str.charAt(i) == '}' || str.charAt(i) == ']') {
                if (!stk.empty() && stk.lastElement() == str.charAt(i)) {
                    stk.pop();
                    toBeMatched--;
                } else {
                    System.out.println(i + 1);
                    return false;
                }
            }
            if (i == str.length() - 1) {
                if (!stk.empty()) {
                    System.out.println(toBeMatched + 1);
                    return false;
                }
            }
        }
        System.out.println("Success");
        return true;
    }

    public static void main(String[] args) throws IOException {
        // String str = "foo(bar[i);";
        // String str = "{[}";
        // String str = "{";
        // String str = "[](()";
        // String str = "foo(bar);";
        // String str = "{[]}";
        // String str = "[](){}";
        InputStreamReader input_stream = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input_stream);
        String str = reader.readLine();
        validate(str);
    }
}