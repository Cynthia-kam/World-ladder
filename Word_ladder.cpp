#include <iostream>                     //  Marie Cynthia Abijuru Kamikazi
#include <string>                          //date: 25 Feb 2021
#include <fstream>                       //disclaimer:may contain few bugs prior to what world ladder game is supposed to do
#include <vector>
#include <queue>
#include <set>

using namespace std;

void getWords(string &word1, string &word2) {
  while (true) {
    cout << "Enter the starting word: ";
    cin>>word1;
    
    cout << "Enter the target word: ";
    cin>>word2;
    
    if (word1.length() == word2.length()) {
      break;
    }
    cout << "words should be of the same length!" << endl;
  }
}

void displayLadder(string word1, string word2){
	queue<vector<string> > Q;     // of all sub vectors that form small ladders
	vector<string>wordladder;   
	vector<string> v;    //contains sequences of words
    v.push_back(word1);   //initializing the vector with first word
    Q.push(v);          //initializing the queue with vector contains first element
   	ifstream file;
    file.open("EnglishWords.txt");
	set<string> myfile;   //our dictionary
    set<string> testedWords;
      string term;   // each word in dictionary
    if(file) {
   
	      while(file >> term) {
	    	myfile.insert(term);
	      }
	      
	       while(!(Q.empty())) {     // queue is not empty
	       		vector<string> ladder = Q.front();
	       		Q.pop();
	       		
			string currentword =ladder[ladder.size()-1];
		
				if (currentword == word2) {
			
			  cout << "The  shortest ladder from " << word1 << " to " << word2 << " is \n";
		     for (int i = 1; i < ladder.size(); i++){
                    cout << ladder[i] << "-->";
                }
                break;
                cout << endl;}
           
              
		else{
		
		string next;
			 for (int i = 0; i < currentword.size(); i++) {
			    for (char j = 'a'; j <= 'z'; j++) {
			    next = currentword.substr(0, i) + j + currentword.substr(i + 1);
		     
			    if (myfile.find(next)!=myfile.end()) {
			      
			      if (testedWords.find(next)!=testedWords.end() ){
				
						vector<string> copy = ladder;
				                
						copy.push_back(next);
				                
						Q.push(copy);
			      }
			    }
			    
		            
			    testedWords.insert(next);
			}
		}
	      }
	    }
    }
	
	 else {
      cout << "error! in locating the dictionary" << endl;
    }
    
    
}
int main() {
    
  string word1, word2;
  getWords(word1, word2); 
  displayLadder(word1, word2);
    
  return 0;
}
    

