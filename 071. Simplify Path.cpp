71. Simplify Path
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: path = "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
  
class Solution {
public:
/*
Loop every char in the path. Prepare a stack, extract element from path to the stack.
利用栈的特性，如果sub string element
1. 等于“/”，跳过，直接开始寻找下一个element
2. 等于“.”，什么都不需要干，直接开始寻找下一个element
3. 等于“..”，弹出栈顶元素，寻找下一个element
4. 等于其他，插入当前elemnt为新的栈顶，寻找下一个element

最后，再根据栈的内容，重新拼path。这样可以避免处理连续多个“/”的问题。
*/    
    string simplifyPath(string path) {
        vector<string> stack;     
        int i=0;   
        while(i< path.size())  {   
             while(path[i] =='/' && i< path.size()) i++; //skip the begining '////'  
             if(i == path.size())   break;   
             int start = i;   
             while(path[i]!='/' && i< path.size()) i++; //decide the end boundary  
             int end = i-1;   
             string element = path.substr(start, end-start+1);   
             if(element == "..") {   
                  if(stack.size() >0)   
                  stack.pop_back();   
             }   
             else if(element!=".")   
             stack.push_back(element);      
        }   
        if(stack.size() ==0) return "/";   
        string simpPath;   
        for(int i =0; i<stack.size(); i++)   
        simpPath += "/" + stack[i];   
        return simpPath;   

    }
};
  
  
