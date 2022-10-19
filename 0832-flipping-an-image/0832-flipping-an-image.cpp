class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for(int i=0;i<n;i++) {
            int low=0, high=n-1;
            while(low <= high) {
                if(image[i][low]==0) image[i][low]=1;
                else image[i][low]=0;
                
                if(high != low) {
                    if(image[i][high]==0) image[i][high]=1;
                    else image[i][high]=0;  
                }
                
                
                swap(image[i][low], image[i][high]);
                low++;
                high--;
            }
        }
        return image;
    }
};