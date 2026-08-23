import java.util.Stack;
public class balancedParenthesis {

    public static void main(String[] args) {
        String test="[()]{}{()()}";
        // String test="[()";
        Stack<Character>st=new Stack<>();
        for(Character x:test.toCharArray()){
            if(x=='[' || x=='{' || x=='('){
                st.push(x);
            }
            else{
                if(st.isEmpty()){
                    System.out.println("false");
                    return;
                }
                if((x==')' && st.peek()=='(')||(x=='}' && st.peek()=='{')||(x==']' && st.peek()=='[')){
                    st.pop();
                }
                else{
                    System.out.println("false");
                    return;
                }
            }
        }
        if(!st.isEmpty()){
            System.out.println("false");
            
        }
        else{
            System.out.println("true");
        }
    }
}