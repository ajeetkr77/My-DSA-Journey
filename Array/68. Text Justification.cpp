class Solution {
public:
    string makeLine(int i, int j, vector<string>& words, int eachSpaceExtra, int remExtraSpace, int maxWidth){
        string Line = "";
        for(int k = i; k < j; k++){
            Line += words[k];
            if(k != j-1){
                Line += " ";
                for(int p = 0; p < eachSpaceExtra; p++){
                    Line += " ";
                }
                if(remExtraSpace > 0){
                    Line += " ";
                    remExtraSpace--;
                }
            }
        }
        int space = maxWidth - Line.length();
        while(space--) Line += " ";
        return Line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        int i = 0, j = 0;
        
        while(i < n){
            int spaceCount = 0;
            int letterCount  = 0;
            while(j < n && letterCount + spaceCount + words[j].length() <= maxWidth){
                letterCount += words[j].length();
                spaceCount++;
                j++;
            }
            spaceCount --;

            int extraSpaces = maxWidth - letterCount - spaceCount;
            int eachSpaceExtra = 0;
            int remExtraSpace = 0;

            if(spaceCount != 0 && j != n){
                eachSpaceExtra = extraSpaces / spaceCount;
                remExtraSpace = extraSpaces % spaceCount;
            }
           // cout<<spaceCount<<" "<<eachSpaceExtra<<" "<<remExtraSpace<<endl;

            string Line = makeLine(i, j, words, eachSpaceExtra, remExtraSpace, maxWidth);
            // cout<<Line<<endl;
            ans.push_back(Line);
            i = j;
        }
        return ans;
    }
};
