/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (43.93%)
 * Likes:    933
 * Dislikes: 870
 * Total Accepted:    97.3K
 * Total Submissions: 221.5K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space p1, p2, p3 and p4, return
 * true if the four points construct a square.
 * 
 * The coordinate of a point pi is represented as [xi, yi]. The input is not
 * given in any order.
 * 
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * p1.length == p2.length == p3.length == p4.length == 2
 * -10^4 <= xi, yi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if((p2[1]-p1[1])*(p3[1]-p2[1])!=(p3[0]-p2[0])*(p1[0]-p2[0])){
            return false;
        }
        if((p4[1]-p1[1])*(p3[1]-p4[1])!=(p3[0]-p4[0])*(p1[0]-p4[0])){
            return false;
        }
        int d1=(p2[1]-p1[1])*(p2[1]-p1[1])+(p2[0]-p1[0])*(p2[0]-p1[0]);
        int d2=(p3[1]-p4[1])*(p3[1]-p4[1])+(p3[0]-p4[0])*(p3[0]-p4[0]);
        if(d1!=d2){
            return false;
        }
        int d3=(p2[1]-p3[1])*(p2[1]-p3[1])+(p2[0]-p3[0])*(p2[0]-p3[0]);
        int d4=(p1[1]-p4[1])*(p1[1]-p4[1])+(p1[0]-p4[0])*(p1[0]-p4[0]);
        if(d3!=d4){
            return false;
        }
        if(d1!=d4){
            return false;
        }
        return true;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2 || p2==p3 || p3==p4 || p1==p4 || p2==p4 || p1==p3){
            return false;
        }
        if(isSquare(p1,p2,p3,p4) || isSquare(p1,p2,p4,p3) || isSquare(p1,p3,p4,p2) || 
        isSquare(p1,p3,p2,p4) || isSquare(p1,p4,p3,p2) || isSquare(p1,p4,p2,p3)){
            return true;
        }
        return false;
    }
};
// @lc code=end

