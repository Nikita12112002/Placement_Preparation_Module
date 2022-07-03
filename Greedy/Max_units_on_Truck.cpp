class Solution {
public:
    
   static bool comp(vector<int>&a , vector<int>&b)
   {
       return a[1]>b[1];
   }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
        int cap=0 , size=truckSize , units=0 ,i=0;
        while(i<boxTypes.size() && cap<=truckSize)
        {
            if(boxTypes[i][0]<size)
            {
                cap = cap+boxTypes[i][0];
                units=units+(boxTypes[i][0] * boxTypes[i][1]);
                size=size-boxTypes[i][0];
            }
            
            else
            {
                cap=cap+size;
                units=units+(size*boxTypes[i][1]);
                break;
            }
            i++;
        }
        return units;
    }
};