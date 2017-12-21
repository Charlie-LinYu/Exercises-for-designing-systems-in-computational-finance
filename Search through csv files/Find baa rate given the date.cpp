#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

double average(vector<double> v);

double find_rate(vector<double> rate_vec, vector<string> date_vec, string date);

bool isnum(string s);

int main()
{
    vector<double> rate;
    vector<string> date;
    ifstream infile("./hw1_H.15_Baa_Data.csv");

// code for loading rate and date vectors from the file hw1_H.15_Baa_Data.csv
// the headers should be handled properly. do not delete them manually

    string test4date;                      //store string from csv, waiting to test if it is a date format
    string test4rate;                      //store string from csv, waiting to test if it is double
    double rawrate;                        //used by stringstream to convert test4rate to a double variable
    double average_rate;
    string input_date;
    double output_result;

    while(infile.good()){
        getline(infile,test4date,',');
        getline(infile,test4rate);
        if (isnum(test4date.substr(0,4)) && test4date.substr(4,1)=="-" && isnum(test4date.substr(5,2)) && isnum(test4rate)){
            date.push_back(test4date);
            stringstream strtonum(test4rate);
            strtonum >> rawrate;
            rate.push_back(rawrate);
        }
    }

   infile.close();

   average_rate = average(rate);

// code for prompting user for a date and returning the rate
// and the difference between the rate for that date and the
// average rate
//
// This code should allow the user to continue to input dates
// until the user inputs the EOF (End-of-file), namely control-d (in linux/mac) or control-z (in windows)
// This should not crash if a bad date is entered.

    cout<<"Please enter the date you are interested in (In yyyy-mm format)."<<endl;
    cout<<"Reminder: the date should be between "<<date[0];
    cout<<" and "<<date[date.size()-1]<<", and you can quit by typing Ctrl + z."<<endl;

    while(cin>>input_date){
        if (input_date.size()==7 && isnum(input_date.substr(0,4)) && input_date.substr(4,1)=="-" && isnum(input_date.substr(5,2))){
            output_result=find_rate(rate,date,input_date);
            if (output_result != -100.00){
                cout<<"The rate of "<<input_date<<" is "<<output_result<<"."<<endl;
                cout<<"The difference between the rate of "<<input_date;
                cout<<" and the average rate is "<<(output_result-average_rate)<<"."<<endl;
                cout<<"Please enter the date you are interested in (In yyyy-mm format):"<<endl;
            }
            else{
                cout<<"The date you input exceeds the data range, please input a new date:"<<endl;
            }
        }
        else{
            cout<<"Your date format is wrong, please input a new date in yyyy-mm format:"<<endl;
        }
    }

   return 0.0; // program end
}

double average(vector<double> v)
{
// code for calculating average of members of v
// and returning the average
    double sum = 0.0;
    for (vector<int>::size_type i = 0;i < v.size();i++){
      sum = sum + v[i];
    }
    return sum/v.size();
}

double find_rate(vector<double> rate_vec, vector<string> date_vec, string date)
{
// code for finding the Baa rate for the
// given date (in yyyy-mm format)
// and returning the rate for that month
    vector<string>::iterator iter = std::find(date_vec.begin(),date_vec.end(),date);
    int seq = std::distance(date_vec.begin(),iter);
    if (seq<date_vec.size()){
        return rate_vec[seq];
    }
    else{
      return -100.00;
    }
}

bool isnum(string s)
{
// code for judging whether a string is a number
    stringstream sin(s);
    double testnumber;
    char testchar;
    if (!(sin>>testnumber)){
        return false;
    }
    if (sin>>testchar){
        return false;
    }
    else{
        return true;
    }
}

