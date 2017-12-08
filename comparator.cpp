bool newcomp(const string &a,const string &b){
		
	if(a.length()!=b.length())
		return a.length() < b.length();
	
	if(a==b)
		return true;
	
	int len = a.length();
	for(int i=0;i<len;i++)
		if(a[i]!=b[i])
			return a[i] < b[i];
			
	return true;	
}

/* 
	While making comparator method inside the class for some object,
   	make it 'static' and use sort(all(...), this->comp).
   	
   	Another option is to overload operator '<' inside the struct or
   	class object.
*/
   
