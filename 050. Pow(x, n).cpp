50. Pow(x, n)
  
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
  
class Solution {
public:
    //Recursive to optimize: 2^7= (2^3)*(2^3)*2 = 8*8*2 = 128
    double myPow(double x, int n) {
        if(n==0)return 1;  
        if(n==1)return x;  
        double temp = myPow(x,abs(n/2));  
        if(n>0){  
            if(n&1)return temp*temp*x;  
            else return temp*temp;  
        }else{  
            if(n&1)return 1.0/(temp*temp*x);  
            else return 1.0/(temp*temp);  
        }  

        //Exceed time limit
        /*
        double res = 1;
        if(n >= 0){
            for(int i = 0; i < n; i++) res*=x; 
        }else{
            int m = -n;
            for(int i = 0; i < m; i++) res*=x; 
            res = 1.0/res;
        }
        return res;*/
    }
};
