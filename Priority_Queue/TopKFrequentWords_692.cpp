// LEETCODE 692

// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

class Solution {
public:
     class comparator{
         public:
         bool operator()(pair<string,int>&a,pair<string,int>&b)
         {   if (a.second == b.second) {
                   return a.first < b.first;
                   }
             return a.second>b.second;
         }
     };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m1;
     for(auto element:words)
     {
         m1[element]++;
     }   
     priority_queue<pair<string,int>,vector<pair<string,int>>,comparator>p1;
     for(auto i:m1)
     {
         p1.push(i);
         if(p1.size()>k)
           p1.pop();
     }
     vector<string>ans;
     while(!p1.empty())
     { 
       ans.push_back(p1.top().first);
       p1.pop();
     }
     reverse(ans.begin(),ans.end());
   return ans;
    }

};