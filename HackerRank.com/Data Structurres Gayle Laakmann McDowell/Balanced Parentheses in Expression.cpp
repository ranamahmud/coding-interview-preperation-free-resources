#include <stack>
#include <iostream>

using namespace std;

char TOKENS[3][3] = {{'{','}'},{'[',']'},{'(',')'}};
bool isOpenTerm(char c){
    for(char* array:TOKENS){
        if(array[0] == c)
            return true;
    }
    return false;
}

bool matching(char openTerm, char closeTerm){
    for(char* array:TOKENS){
        if(array[0] == openTerm){
            return array[1] == closeTerm;
        }
    }
    return false;
}
bool isBalanced(string expression){
    stack<char> stack; 
    for(char& ch: expression){
        if(isOpenTerm(ch)){
            stack.push(ch);
        }else{
             if(stack.empty())
							return false;
            char top = stack.top();
					  stack.pop();
            if(!matching(top, ch)){
                return false;
            }
        } 
        
    }

    return stack.empty();
}
int main(){
    string pairs = "(((((({{{{{[[[[[([)])]]]]]}}}}}))))))";
    cout<<isBalanced(pairs)<<endl;

    return 0;
}
