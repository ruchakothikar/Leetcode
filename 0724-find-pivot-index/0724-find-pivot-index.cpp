class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      std::vector<int> rightsum;
      std::deque<int> leftsum;
      rightsum.push_back(0);
      leftsum.push_front(0);
        for(int i=1; i<nums.size();i++)
      {
        rightsum.push_back(rightsum[i-1]+nums[i-1]);
      }
        for(int i=nums.size()-2; i>=0;i--)
      {
        leftsum.push_front(leftsum.front()+nums[i+1]);
      }
      for(int i=0;i<nums.size();i++)
      {
        if(rightsum[i]==leftsum.front())
        {return i;}
        leftsum.pop_front();
      }
      return -1;
    //end of program
    }
};

//run a loop through array to calculate right sums and store in array 1
//run a loop through array to calculate left sums and store in array 2
//run a loop, compare array 1 with array 2
//if they match, i is the index















/*
 vector<int> leftsum;
       std::stack<int> rightsum;
        leftsum.push_back(0);
        rightsum.push(0);
        //making leftsum array
        for(int i=1; i<nums.size(); i++)
        {
                leftsum.push_back(leftsum[i-1] + nums[i-1]);
        }
        //making rightsum array
         for(int i=nums.size()-2; i>=0; i--)
        {
                rightsum.push(rightsum.top()+ nums[i+1]);
        }
        //comparing left and right sum arrays to find equidistant pivot
         for(int i=0; i<nums.size();i++)
        {
                if(leftsum[i]==rightsum.top())
                    {
                        return i;
                    }
                    rightsum.pop();
        }
        return -1;

*/