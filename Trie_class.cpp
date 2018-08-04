class Trie{

	struct Node{
		int cnt;
		struct Node* next[256];
	};

	struct Node* root;

	public:
	Trie(){
		root = createNode();
	}

	Node* createNode(){
		struct Node* temp = new Node;
		temp->cnt = 0;
		for(int i=0;i<256;i++)
			temp->next[i] = NULL;

		return temp;
	}

	void insert(string &s){

		struct Node* curr = root;
		for(char c : s){
			if(curr->next[c] == NULL){
				curr->next[c] = createNode();
			}

			curr->next[c]->cnt += 1;  
			curr = curr->next[c];
		}
	}

	string query(string &s){

		string pref = "";
		struct Node* curr = root;

		for(int i=0;i<s.length();i++){
			pref += s[i];
			if(curr->next[s[i]]->cnt == 1)
				return pref;
			curr = curr->next[s[i]];
		}

		return pref;
	}
};
