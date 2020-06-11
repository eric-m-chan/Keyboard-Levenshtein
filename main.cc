/*
 * compile with g++ main.cc
 * execute with ./a.out
 *
 * necessary files:
 * @dictionary.txt = complete English dictionary
 * @common.txt     = set of common words
 * @corpus.txt     = input corpus
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>

/* Operation Costs */
// SHORT_SUB = 1;
// MED_SUB   = 2;
// LONG_SUB  = 3;

//insert cost
uint INS_COST = 2;
//delete cost
uint DEL_COST = 2;
//swap cost
uint SWP_COST = 1;


//distance matrix
std::vector<std::vector<uint>> distMatrix;

//populate the distance matrix
std::vector<std::vector<uint>> populate_matrix() {
	std::vector<uint> aMatrix = {0,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,1,3,1,3,3,3,2,2,3,1};
	std::vector<uint> bMatrix = {3,0,2,3,3,2,1,2,3,3,3,3,2,1,3,3,3,3,3,3,3,1,3,3,3,3};
	std::vector<uint> cMatrix = {3,2,0,1,3,2,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,1,3,1,3,2};
	std::vector<uint> dMatrix = {2,3,1,0,1,1,2,3,3,3,3,3,3,3,3,3,3,2,1,3,3,2,2,2,3,3};
	std::vector<uint> eMatrix = {3,3,3,1,0,2,3,3,3,3,3,3,3,3,3,3,2,1,2,2,3,3,1,3,3,3};

	std::vector<uint> fMatrix = {3,2,2,1,2,0,1,2,3,3,3,3,3,3,3,3,3,1,2,2,3,1,3,3,3,3};
	std::vector<uint> gMatrix = {3,2,3,2,3,1,0,1,3,2,3,3,2,1,3,3,3,2,3,1,3,3,3,3,2,3};
	std::vector<uint> hMatrix = {3,3,3,3,3,2,1,0,3,1,2,3,1,2,3,3,3,3,3,2,2,3,3,3,1,3};
	std::vector<uint> iMatrix = {3,3,3,3,3,3,3,3,0,2,1,2,3,3,1,2,3,3,3,3,1,3,3,3,2,3};
	std::vector<uint> jMatrix = {3,3,3,3,3,3,2,1,2,0,1,2,1,2,3,3,3,3,3,3,1,3,3,3,2,3};

	std::vector<uint> kMatrix = {3,3,3,3,3,3,3,2,1,1,0,1,2,3,2,3,3,3,3,3,2,3,3,3,3,3};
	std::vector<uint> lMatrix = {3,3,3,3,3,3,3,3,2,2,1,0,3,3,1,2,3,3,3,3,3,3,3,3,3,3};
	std::vector<uint> mMatrix = {3,2,3,3,3,3,3,3,3,2,1,3,0,1,3,3,3,3,3,3,3,3,3,3,3,3};
	std::vector<uint> nMatrix = {3,1,3,3,3,3,2,1,3,2,3,3,1,3,3,3,3,3,3,3,3,2,3,3,3,3};
	std::vector<uint> oMatrix = {3,3,3,3,3,3,3,3,1,3,2,1,3,3,0,1,3,3,3,3,2,3,3,3,3,3};

	std::vector<uint> pMatrix = {3,3,3,3,3,3,3,3,2,3,3,2,3,3,1,0,3,3,3,3,3,3,3,3,3,3};
	std::vector<uint> qMatrix = {1,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,1,3,3,3};
	std::vector<uint> rMatrix = {3,3,3,2,1,1,2,3,3,3,3,3,3,3,3,3,3,0,3,1,3,3,2,3,2,3};
	std::vector<uint> sMatrix = {1,3,2,1,2,2,3,3,3,3,3,3,3,3,3,3,2,3,0,3,3,3,1,1,3,2};
	std::vector<uint> tMatrix = {3,3,3,3,2,2,1,2,3,3,3,3,3,3,3,3,3,1,3,0,2,3,3,3,1,3};

	std::vector<uint> uMatrix = {3,3,3,3,3,3,3,2,1,1,2,3,3,3,2,3,3,3,3,2,0,3,3,3,1,3};
	std::vector<uint> vMatrix = {3,1,1,2,3,1,2,3,3,3,3,3,3,2,3,3,3,3,3,3,3,0,3,2,3,3};
	std::vector<uint> wMatrix = {2,3,3,2,1,3,3,3,3,3,3,3,3,3,3,3,1,2,1,3,3,3,0,3,3,3};
	std::vector<uint> xMatrix = {2,3,1,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,3,3,2,3,0,3,1};
	std::vector<uint> yMatrix = {3,3,3,3,3,3,2,1,2,2,3,3,3,3,3,3,3,2,3,1,1,3,3,3,0,3};
	std::vector<uint> zMatrix = {1,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,1,3,0};

	std::vector<std::vector<uint>> distMatrix;

	distMatrix.push_back(aMatrix);
	distMatrix.push_back(bMatrix);
	distMatrix.push_back(cMatrix);
	distMatrix.push_back(dMatrix);
	distMatrix.push_back(eMatrix);

	distMatrix.push_back(fMatrix);
	distMatrix.push_back(gMatrix);
	distMatrix.push_back(hMatrix);
	distMatrix.push_back(iMatrix);
	distMatrix.push_back(jMatrix);

	distMatrix.push_back(kMatrix);
	distMatrix.push_back(lMatrix);
	distMatrix.push_back(mMatrix);
	distMatrix.push_back(nMatrix);
	distMatrix.push_back(oMatrix);

	distMatrix.push_back(pMatrix);
	distMatrix.push_back(qMatrix);
	distMatrix.push_back(rMatrix);
	distMatrix.push_back(sMatrix);
	distMatrix.push_back(tMatrix);

	distMatrix.push_back(uMatrix);
	distMatrix.push_back(vMatrix);
	distMatrix.push_back(wMatrix);
	distMatrix.push_back(xMatrix);
	distMatrix.push_back(yMatrix);
	distMatrix.push_back(zMatrix);

	return distMatrix;
}

//utility function to easily query distances from the distance matrix
//can do dist('a', 'a'), instead of distMatrix[0][0]
uint dist(char a, char b) {
	return distMatrix[(int)(a - 97)][(int)(b - 97)];
}

//splice a sentence into a vector of words (space delimiting)
//function taken from https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/
std::vector<std::string> sentence_to_words(std::string sentence) {
	std::vector<std::string> words;
	std::istringstream ss(sentence);

	while (ss) {
		std::string word;
		ss >> word;
		words.push_back(word);
	}
	return words;
}

bool is_valid_word(std::string word, std::vector<std::string>& letterDict) {
	//@word is the word we want to test
	//@letterDic is the dictionary of words that start with the same letter as [word]
	//@@return true if @word is a real word, otherwise return false
	bool flag = false;
	
	for (int i = 0; i < letterDict.size(); i++) {
		if (word.compare(letterDict[i]) == 0) {
			flag = true;
		}
	}
	
	return flag;
}

//a min(3) function cause the other wasn't working for me
int min(int x, int y, int z) {
	if (y < x) {
		if (z < y) {
			return z;
		}
		return y;
	}
	if (z < x) {
		return z;
	}
	return x;
}

//computes one iteration of the Levenshtein comparison between two words
uint Levenshtein(std::string word1, std::string word2) {

	const std::size_t len1 = word1.size();
	const std::size_t len2 = word2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(int i = 1; i <= len1; ++i) {
		d[i][0] = INS_COST * i;
	}
	for(int i = 1; i <= len2; ++i) {
		d[0][i] = DEL_COST * i;
	}
	for(unsigned int i = 1; i <= len1; i++) {
		for(unsigned int j = 1; j <= len2; ++j) {
			if (word1[i-1] == word2[j-1]) {
				d[i][j] = d[i-1][j-1];
			}
			else {
				//cost to insert the value in the computation
				int ins_val = d[i-1][j] + INS_COST;
				//cost to delete the value in the computation
				int del_val = d[i][j-1] + DEL_COST;
				//cost to substitute
				int sub_val = d[i-1][j-1] + dist(word1[i-1], word2[j-1]);
				if (i > 2 && j > 2) {
					if (word1[i-1] == word2[j-2] && word1[i-2] == word2[j-1]) {
						//cost to swap
						int swp_val = d[i-2][j-2] + SWP_COST;
						d[i][j] = min(min(ins_val, del_val, sub_val), swp_val, swp_val);
					}
					else {
						d[i][j] = min(ins_val, del_val, sub_val);
					}
				}
				else {
					d[i][j] = min(ins_val, del_val, sub_val);
				}
			}
			//d[i][j] = std::min({d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1)});
                }
        }
	return d[len1][len2];
}


void find_suggestions(std::string word, std::vector<std::string> dict1, std::vector<std::string> dict2, std::vector<std::string> dict3, uint sentenceNum) {
	//compute the KB-Levenshtein distance between word and words of all three dictionaries
	//extract the 5 closest words

	uint minDist = 100;
	uint tempDist;

	std::vector<std::string> closeWords;

	//compare against first dictionary
	for (int i = 0; i < dict1.size(); i++) {
		tempDist = Levenshtein(word, dict1[i]);
		//if tempDist < minDist, flush the vector of words. Then update min
		if (tempDist < minDist) {
			closeWords.clear();
			closeWords.push_back(dict1[i]);
			minDist = tempDist;
		}
		//if tempDist == minDist, add the current word to set of close words
		else if (tempDist == minDist) {
			closeWords.push_back(dict1[i]);
		}
	}
	//compare against second dictionary
	for (int i = 0; i < dict2.size(); i++) {
		tempDist = Levenshtein(word, dict2[i]);

		if (tempDist < minDist) {
			closeWords.clear();
			closeWords.push_back(dict2[i]);
			minDist = tempDist;
		}
		else if (tempDist == minDist) {
			closeWords.push_back(dict2[i]);
		}
	}
	//compare against third dictionary
	for (int i = 0; i < dict3.size(); i++) {
		tempDist = Levenshtein(word, dict3[i]);

		if (tempDist < minDist) {
			closeWords.clear();
			closeWords.push_back(dict3[i]);
			minDist = tempDist;
		}
		else if (tempDist == minDist) {
			closeWords.push_back(dict3[i]);
		}
	}

	//in case there are too many close words
	tempDist = min(3, 3, closeWords.size());

	//remove duplicates in the recommended words set
	std::cout << "[" << word << "]" << " is misspelled in sentence number [" << sentenceNum + 1  <<"], perhaps you meant one of the following instead: {";
	for (int i = 0; i < tempDist; i++) {
		//pretty printing
		if (i == tempDist - 1) {
			std::cout << closeWords[i] << "}\n";
		}
		else {
			std::cout << closeWords[i] << ", ";
		}
	}

}

int main() {
	//2D vector to mantain keyboard distances
	//std::vector<std::vector<uint>> dMatrix;
	//2D vector to maintain a dictionary of wordss by their first letters
	std::vector<std::vector<std::string>> dictionary(26);
	//vector of 300 most common words
	std::vector<std::string> common;
	//input corpus/text, indexed by each sentence
	std::vector<std::string> corpus;
	//string for parsing
	std::string line;

	//populate distance matrix
	distMatrix = populate_matrix();
	
	//populate common
	std::ifstream commonFile("common.txt");
	while (getline(commonFile, line, '\n')) {
		common.push_back(line);
	}
	commonFile.close();

	//populate dictionary
	std::ifstream dictionaryFile("dictionary.txt");
	while(getline(dictionaryFile, line, '\n')) {
		//if the first letter begins with 'a', put the word into the first vector
		//do this for every other letter
		dictionary[(int)(line[0]-97)].push_back(line);
	}
	dictionaryFile.close();

	//read in sentences, delimiting on periods(.)
	std::ifstream corpusFile("corpus.txt");
	while(getline(corpusFile, line, '.')) {
		//remove space at beginning if its present
		if (isspace(line[0])) {
			corpus.push_back(line.substr(1));
		}
		else {
			corpus.push_back(line);
		}
	}
	corpusFile.close();

	for (int i = 0; i < corpus.size(); i++) {
		//splice the current sentence into a vector of words
		std::vector<std::string> words = sentence_to_words(corpus[i]);
		for (int j = 0; j < words.size() - 1; j++) {
			//check if a word is valid
			//dictionary[(int)...] is the expression for the vector
			//of words beginning with the same letter as words[j]
			if (!is_valid_word(words[j], dictionary[(int)(words[j][0]-97)])) {
				//if the word is invalid, find suggestions between words that 
				//start with the same letter, 
				//words that start with the second letter,
				//and common
				find_suggestions(words[j], dictionary[(int)(words[j][0]-97)], dictionary[(int)(words[j][0]-96)], common, i);	
			}
		}
	}
	std::cout << std::endl;
}

