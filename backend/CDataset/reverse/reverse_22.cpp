int reverse(int x) {
	string a = to_string(x);
	string res = "";
	if(a.find("-")!=string::npos){
		res += "-";
	}
	for(int i=a.length()-1; i>=0; i--){
		res += a.substr(i, 1);
	}
	if(stoll(res) > 2147483647 || stoll(res) < -2147483648){
		return 0;
	}
	return stoi(res);
}
