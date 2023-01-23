// Project UID db1f506d06d84ab787baf250c265e24e

#include <map>
#include <set>
#include "csvstream.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <math.h>
using namespace std;


//check command line args

class Classifer{
private:
//    int uniqueWords;
    string label;
    string content;
    string predictedLabel;
    std::map<string, int> uniqueUnit;
    std::map<string, int> unitLabels;
    std::map<pair<string, string>, int> labelAndContent;
    map<pair<string, string>, int> labelsWords;
    std::set<string> onlyUniqueWords;
    std::set<string> trainingLabels;
    int numPost = 0;
    bool debugStatus;
    string debug;
    int max = 0;
    int numTestPost = 0;
    int numTestCorrect = 0;
    string correctLabel;

    
public:

    
    void startProcessData(const string file){
         csvstream in(file);
        std::map<string, string> row;
        set<string> words;
        if(debugStatus == true){
            cout << "training data:" << endl;
        }
        while(in >> row){
            numPost++;
            
        //label post
        string label = row["tag"];
        unitLabels[label]++;
        string content = row["content"];
            
            if(debugStatus == true){
            cout << "  label = " << label << ", " << "content = ";
            cout << content << "\n";
            }
            
        set<string> trainingWords;
        trainingWords = unique_words(content);
            for(auto word : trainingWords){
                uniqueUnit[word]++;
                pair<string, string> p = {label, word};
                labelAndContent[p]++;
         
            }
    }
        
        if(debugStatus == true){
            
            cout << "trained on " << numPost << " examples" << endl;
            cout << "vocabulary size = " << uniqueUnit.size() << "\n\n";
            
            cout << "classes:" << endl;
            for(auto &a : unitLabels){
                cout << "  " << a.first << ", " << a.second << " examples, ";
                cout << "log-prior = " << logPriorMath(a.first) << endl;

            }
            
            cout << "classifier parameters:" << endl;
            for(auto &b : labelAndContent){
                cout << "  " << b.first.first << ":" << b.first.second;
                cout << ", count = " << b.second << ", log-likelihood = ";
                cout << whichLogFunction(b.first.second, b.first.first);
                cout << endl;
                
//
//            cout << "trained on "
            }
            
        }
    }
    
    
    set<string> unique_words(const string &str) {
      istringstream source(str);
      set<string> words;
      string word;
      while (source >> word) {
        words.insert(word);
        onlyUniqueWords.insert(word);
      }
      return words;
        
    }
    
    void printHeader(){
        cout << "trained on " << numPost << " examples"<< endl;
        cout << "test data: \n" << endl;
        
    }
    
     string predictedLabelMaker(const string label, const string word){
         double currentPredictedLabelStat = whichLogFunction(label, word);
         string currentPredictedLabel = label;
         if(currentPredictedLabelStat > max){
             currentPredictedLabel = label;
             predictedLabel = currentPredictedLabel;
         }else{
             return label;
         }
         return currentPredictedLabel;
     }
    
    
    double logNothing(){
        double output = log(1 / static_cast<double>(numPost));
        return output;
    }

    double logInTraining(const string word){
        double output = log(uniqueUnit[word] / static_cast<double>(numPost));
        return output;
    }
    
    double logPriorMath(const string label){
        double output = log(unitLabels[label] /static_cast<double>(numPost));
        return output;
    }
           
    double logLikelihoodMath(const string label, const string word){
        pair<string, string> p = {label, word};
        double output = log(labelAndContent[p]/
                            static_cast<double> (unitLabels[label]));
        return output;
 
    }
    
    
    double whichLogFunction(string word, string label){
        
            pair<string, string> p = {label, word};
            double labelCount = labelsWords[p];
            double wordCount = uniqueUnit[word];
        double labelAndWordCount = labelAndContent[p];
            if(labelAndWordCount != 0){
                double output = logLikelihoodMath(label, word);
                return output;
//                double output = log(labelsWords[p]/unitLabels[label]);
//                return output;
            }else if(labelCount == 0 && wordCount != 0){
                return logInTraining(word);
            }else{
                return logNothing();
            }
    }
    
    
    pair<string, double> logComparison(string content){
        vector<pair<string, double>> prob;
        for(auto &a : unitLabels){
        
            double p = 0;
            set<string> unique = unique_words(content);
            for(string word : unique){
               p =  p + whichLogFunction(word, a.first);
            }
            p = p + logPriorMath(a.first);
            
            pair<string, double> x = {a.first, p};
            prob.push_back(x);
        
        }
        
        pair<string, double> highestProb = prob[0];
        for(auto &eachPair : prob){
            if(eachPair.second > highestProb.second){
                highestProb = eachPair;
            }
        }
        return highestProb;
    }
        
    
    void startTestingData(const string file){
        if(debugStatus == false){
            cout << "trained on " << numPost << " examples\n" << endl;
        }
        
        if(debugStatus == true){
            cout << endl;
        }
        cout << "test data:" << endl;
            csvstream in(file);
            std::map<string, string> row;
            while(in >> row){
                numTestPost++;
                string correctLabel = row["tag"];
                string content = row["content"];
                pair<string, double> prediction = logComparison(content);
            
                cout << "  correct = " << correctLabel << ", " << "predicted = ";
                cout << prediction.first;
                cout << ", " << "log-probability score = ";
                cout << prediction.second << endl;
                cout << "  content = " << content << "\n" << endl;
                
                
                if(correctLabel == prediction.first){
                    numTestCorrect++;
                }
            }

        cout << "performance: " << numTestCorrect << " / " << numTestPost;
        cout << " posts predicted correctly" << endl;
    }
    
    void debugYesOrNo(string debug){
        if(debug == "--debug"){
            debugStatus = true;
            
        }else{
            debugStatus = false;
        }
    }

};



int main(int argc, char **argv){
    cout.precision(3);
    Classifer meow;

    string execName = argv[0];
    string testFile = argv[1];
    ifstream testFileRead(testFile);
    string trainFile = argv[2];
    ifstream trainFileRead(trainFile);


    if(!(argc == 3 || argc == 4)){
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
    }

    if(argc == 4){
        string debug = argv[3];
        if(!(debug == "--debug")){
            cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
        }
        
        if(debug == "--debug"){
        meow.debugYesOrNo(argv[3]);
    }
    }
    
    if(argc == 3){
        meow.debugYesOrNo("set to false!");
    }
    
    if(!testFileRead.is_open()){
        cout << "Error opening file: " << argv[1]<< endl;
        return 1;
    }


    if(!trainFileRead.is_open()){
        cout << "Error opening file: " << argv[2] << endl;
        return 1;
    }

    
    meow.startProcessData(argv[1]);
    meow.startTestingData(argv[2]);
//    meow.startTestingData("test_small.csv");
//
//    meow.debugYesOrNo("--debug");

    
    return 0;
}
//consturct classifier adt
//1. train classifer

//map of pairs with c and w
///<"Euchre", "bower"> is diff from <"Euchre, "jack">

//my_map[{"euchre", "bower"}] = 1; //key = value
//
//
////or you can make map of maps
//
//my_map["euchre"]["bower"] = 1; //cascading maps?
//2. classify items in testing data





