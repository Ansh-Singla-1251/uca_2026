import java.util.Stack;

public class postfixEvaluate {
    public static void main(String[] args) {
        String ex="231*+9-";
        Stack<Integer>st=new Stack<>();
        for(Character x:ex.toCharArray()){
            if(Character.isDigit(x)==true){
                st.push(x-'0');
            }
            else{
                int a=st.pop();
                int b=st.pop();
                if(x=='+'){
                    st.push(b+a);
                }
                else if(x=='-'){
                    st.push(b-a);
                }
                else if(x=='*'){
                    st.push(b*a);
                }
                else if(x=='/'){
                    st.push(b/a);
                }
            }
        }
        System.out.println(st.pop());
    }
}
