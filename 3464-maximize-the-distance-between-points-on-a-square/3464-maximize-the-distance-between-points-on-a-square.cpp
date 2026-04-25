class Solution {
public:
    typedef long long ll;

    bool Check(vector<ll>& res, int side, int k, int dist){
        int n = res.size();
        ll peri = 1ll*side*4;

        for(int i = 0; i < n; i++){
            ll curr = res[i];
            int count = 1;
            int lastIdx = i;

            while(count < k){
                // greedy find
                auto it = lower_bound(res.begin(), res.end(), curr + dist); // find next point with value >= curr+dist
                if(it == res.end()) break;

                lastIdx = it-res.begin();  // keeping track of last index i am at
                curr = *it; // value of currDistance
                count++; // number of nodes
            }

            if(count == k && peri - (res[lastIdx] - res[i]) >= dist){ // second condition is the wrap around, because we take first 4 points but didn't consider distance between last point and first point.. since it's a square so a wrap around will be there
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> res;

        // conversion to 1D .. basic intuition -> Aggressive cows in a circular graph
        for(auto &p : points){
            int x = p[0];
            int y = p[1];

            if(x == 0){
                res.push_back(y);
            } else if(y == side){
                res.push_back((ll)side + x);
            } else if(x == side){
                res.push_back((ll)3*side-y);
            } else {
                res.push_back((ll)4*side - x);
            }
        }
        sort(res.begin(), res.end());

        ll left = 1;
        ll right = (1ll*4*side);

        ll ans = 0;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(Check(res, side, k, mid)){
                ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return ans;
    }
};