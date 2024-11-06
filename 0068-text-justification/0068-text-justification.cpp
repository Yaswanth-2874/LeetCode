class Solution {
    void placeSpaces(int spaceCount, string& line, int& pos) {
        while(spaceCount-- && pos < line.size())
            line[pos++] = ' ';
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justifiedContent;
        int sentenceWidth = 0;
        vector<string> currentLine;
        
        for(int wordIndex = 0; wordIndex < words.size(); wordIndex++) {
            string& word = words[wordIndex];
            int wordWidth = word.size();
            sentenceWidth += wordWidth;

            if(sentenceWidth > maxWidth) {
                sentenceWidth -= wordWidth;
                int wordsPresent = currentLine.size();
                sentenceWidth -= wordsPresent; // removing extra spaces added
                
                int totalSpace = maxWidth - sentenceWidth;
                int spacesPresent = max(wordsPresent - 1, 1);
                
                int eachSpaceLength = totalSpace / spacesPresent;
                int extraSpace = totalSpace % spacesPresent;
                
                string line(maxWidth, ' ');
                int pos = 0;
                
                for(int i = 0; i < currentLine.size(); i++) {
                    line.replace(pos, currentLine[i].size(), currentLine[i]);
                    pos += currentLine[i].size();
                    
                    if(i < currentLine.size() - 1) {
                        int spaceToAdd = eachSpaceLength + (extraSpace-- > 0);
                        placeSpaces(spaceToAdd, line, pos);
                    }
                }
                
                justifiedContent.push_back(line);
                sentenceWidth = wordWidth;
                currentLine.clear();
            }
            
            sentenceWidth++;  // for space
            currentLine.push_back(word);
        }
        
        string line(maxWidth, ' ');
        int pos = 0;
        for(int i = 0; i < currentLine.size(); i++) {
            line.replace(pos, currentLine[i].size(), currentLine[i]);
            pos += currentLine[i].size() + 1;
        }
        
        justifiedContent.push_back(line);
        
        return justifiedContent;
    }
};
