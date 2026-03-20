class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sandwich;
        queue<int> student;
        int c=0;
        for(int i=0; i<students.size(); i++)
        {
            student.push(students[i]);
        }
        for(int i=sandwiches.size()-1; i>=0; i--)
        {
            sandwich.push(sandwiches[i]);
        }
        while(c!=student.size())
        {
            if(student.front()==sandwich.top())
            {
                student.pop();
                sandwich.pop();
                c=0;
            }
            else
            {
                student.push(student.front());
                student.pop();
                c++;
            }
        }
        return c;
    }
};