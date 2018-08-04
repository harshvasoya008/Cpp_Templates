vector<string> split(const string& s, const char& c){
	string buff("");
	vector<string> v;

	for(auto ch: s){
		if(ch != c) buff += ch;
		else if(ch == c && buff != "") {
			v.push_back(buff);
			buff = "";
		}
	}

	if(buff != "") v.push_back(buff);

	return v;
}