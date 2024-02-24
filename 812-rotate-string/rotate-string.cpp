class Solution {
public:
    bool rotateString(string s, string goal) {
     queue<char> q1, q2;

     for( int i=0; i<s.size() ; i++) {
         q1.push(s[i]);
     }

     for( int i=0; i<goal.size() ; i++) {
         q2.push(goal[i]);
     }

    int size = goal.size()-1;
    while(size != 0){
        if(q1 == q2)
          return true;

        char c = q2.front();
        q2.pop();
        q2.push(c);

        size--;
    }
    return false;
    }
};