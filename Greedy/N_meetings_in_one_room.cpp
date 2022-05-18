 int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
       vector<pair<int,int>>v;
       
        int count=1;
        
        for(int i=0 ;i<n;i++)
        {
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int starting=v[0].second;
        int ending=v[0].first;
        for(int i=1 ;i<n ;i++)
        {
            if(v[i].second>ending)
            {
              count++;
              ending=v[i].first;
            }
        }
        return count;
    }
};