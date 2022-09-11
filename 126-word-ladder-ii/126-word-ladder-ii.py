class Solution:        
    
    def backtrack(self, curr_trans, curr_word):
        if curr_word == self.beginWord:
            curr_trans.append(curr_word)
            curr_trans.reverse()
            self.result.append(curr_trans)
            return
        
        for prev_word in self.prev[curr_word]:
            self.backtrack(curr_trans+[curr_word], prev_word)
        
       
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        
        # Edge case:
        if endWord not in wordList:
            return []
        
        
        # 0. some init
        self.beginWord = beginWord
        L = len(beginWord)
        
        
        # 1. build adjacency map
        self.neighbors = collections.defaultdict(list)
        for i in range(L):
            for word in wordList:
                self.neighbors[word[:i] + '*' + word[i+1:]].append(word)
            
                    
        # 2. Start BFS.
        # Define several datastructures:
        self.word_depth = dict.fromkeys(wordList, -1)  # -1 depth means unvisited
        self.prev = collections.defaultdict(list)   # storage all prev words 1 level higher than curernt word
        q = []
        q.append(beginWord)
        self.word_depth[beginWord] = 0
        
        while len(q) != 0:
            curr_word = q.pop(0)
            for i in range(L):
                for neighbor in self.neighbors[curr_word[:i] + '*' + curr_word[i+1:]]:
                    # if not visited before:
                    #   1. update with smallest depth
                    #   2. add curr_word to its prev words
                    #   3. add neighbor to q
                    if self.word_depth[neighbor] == -1:
                        self.word_depth[neighbor] = self.word_depth[curr_word] + 1
                        self.prev[neighbor].append(curr_word)
                        q.append(neighbor)
                    else:
                        # if visited before, if curr_word has same depth as its exisitng prev word, append to it. Ow ignore. 
                        if self.word_depth[neighbor] == self.word_depth[curr_word] + 1:
                            self.prev[neighbor].append(curr_word)
                        
        # 3. get all shortest transformation. Assume endWord can be reached from beginWord
        self.result = []  
        self.backtrack([], endWord)
        return self.result