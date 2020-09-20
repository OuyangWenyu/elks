void operator =(string s){
    	Complex c();
    	int k=0;
    	for(;s[k]!='+';k++);
 		r=atoi(s.substr(0,k+1).c_str());
    	int j=k+1;
    	for(;s[j]!='i';j++);
    	i=atoi(s.substr(k+1,j-k).c_str());
    }