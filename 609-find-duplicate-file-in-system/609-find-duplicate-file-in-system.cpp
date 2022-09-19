class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
    unordered_map<string,vector<string>>map;
        
    for(int i=0;i<paths.size();i++)
    {
        string directory="";
        string filename="";
        string content="";
        int j=0;
        while(paths[i][j]!=' ')
        {
            directory+=paths[i][j];
            j++;
        }
        directory+='/';
        while(paths[i][j]!='\0')
        {
          if(paths[i][j]==' ')
          {
              j++;
              while(paths[i][j]!='(')
              {
                  filename+=paths[i][j];
                  j++;
              }
              // cout<<filename<<endl;
              // filename="";
          }
          else if(paths[i][j]=='(')
          {
              j++;
              content="";
              while(paths[i][j]!=')')
              {
                  content+=paths[i][j];
                  j++;
              }
              map[content].push_back(directory+filename);
              content="";
              filename="";
              j++;
          }
          // if(paths[i][j]=='\0')
          //     break;
          //   // j++;
        }
    }
    vector<vector<string>>ans;
    unordered_map<string,vector<string>>:: iterator itr=map.begin();
    while(itr!=map.end())
    {
        if(itr->second.size()!=1)
        ans.push_back(itr->second);
        itr++;
    }
    return ans;
    }
};