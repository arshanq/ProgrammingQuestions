bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
int areBracketsMatched(string s) {
 	stack<char>  S;
	for(int i =0;i<s.length();i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			S.push(s[i]);
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if(S.empty() || !ArePair(S.top(),s[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? 1:0;
 
}

 
 