#include <iostream>
using namespace std;

long long getNumber(string s, int start, int n) {
	long long temp = 0, idx = start;
	while(n--) {
		temp *=10;
		temp+= (int)s[idx++] - '0';
		
	}
//	cout<<"Number: "<<temp<<endl;
	return temp;
}


bool isStringMatching(string s, int startPos, int endPos, long long key) {
	long long temp = getNumber(s, startPos, endPos - startPos + 1);
//	cout<<"temp "<<temp <<" key "<<key<<endl;
	if(key == temp ) {
	//	cout<<"Return true"<<endl;
		return true;
	}
	return false;
}

long long digitsInNumber(long long N) {
//	cout<<"Digit "<<N<<endl;
	int idx = 0;
	while(N >0) {
		N/=10;
		idx++;
	}
	return idx;
}

long long isBeautifulString(string s) {
	int numberOfDigits = 0;
	int len = s.length();
	bool isSequenceFound = false;
	long long firstNumber = -1;
	while(!isSequenceFound) {
		numberOfDigits++;
		if(numberOfDigits * 2 > len) {
			return -1;
		}
		firstNumber = getNumber(s,0, numberOfDigits);
	//	cout<<"First number"<<firstNumber<<endl;
		long long nextNumberInSequence = firstNumber + 1;
		int digits = digitsInNumber(nextNumberInSequence);
		int startPos = numberOfDigits, endPos = startPos + digits -1 ;
		while(true) {
			if(isStringMatching(s, startPos, endPos, nextNumberInSequence)) {
				if(endPos == len -1) {
				//	cout<<"Returning first number"<<firstNumber<<endl;
					return firstNumber;
					break;
				}
				nextNumberInSequence++;
				startPos = endPos + 1;
				endPos = startPos + digitsInNumber(nextNumberInSequence) - 1;
			}else {
				break;
			}
		}
	}
//	cout<<"Returning -1"<<endl;
	return -1;
}

int main() {
	// your code goes here
	int Q;
	cin>>Q;
	string S;
	while(Q--) {
		cin>>S;
		long long ans = isBeautifulString(S);
		if(ans > -1) {
			cout<<"YES "<<ans<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	//	cout<<getFirstNumberInSequence(S, 3)<<endl;
	}
	return 0;
}
