struct Trie{
	/*
		Insert Complexity: O(n*maxL)
		Retrieval complexity: O(L)	
	*/
	
	struct Node{
		struct Node* Map[26];
	};
	
	struct Node *root;
	
	void init(){
		root = create();
	}
	
	struct Node* create(){
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		for(int ch=0;ch<26;ch++)
			temp->Map[ch]=NULL;
		
		return temp;
	}
	
	void insert(string &str){
			
		struct Node *curr = root;
		for(int i=0;i<str.length();i++){
			
			if( curr->Map[str[i]-97]==NULL )
				curr->Map[str[i]-97] = create();
				
			curr=curr->Map[str[i]-97];
		}
	}

	string query(string &s){
		
		struct Node *p = root;
		for(int i=0;i<s.length();i++){
			
			p=p->Map[s[i]-97];
			
			if()
				return "-1";
		}
	}
};
