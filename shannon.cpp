#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void ComputeLengths(vector<int> &lengths, vector <float> &probs){

    int len;
    for (int i = 0; i<probs.size(); i++)
    {
        len = ceil(log2(1/probs[i]));
        lengths.push_back(len);
    }  
}
vector <string> ShannonCode(vector <float> &cdf, vector <int> &lengths, int D_ary){

    float bin_digit;
    vector<string> codes;
    string code;

    for (int j=0;j<lengths.size(); j++){
        code = "";
        bin_digit = cdf[j];
        
        for (int i = 0; i<lengths[j]; i++){
            bin_digit -= floor(bin_digit);
            bin_digit = bin_digit*D_ary;
            code += to_string(int(bin_digit));
            
        }
    codes.push_back(code);
}
    return codes;
}

void ExpectedLength(vector <string> &codes, vector <float> probs){

    float total_exp_len = 0;
    for (int i = 0; i<codes.size(); i++){
        total_exp_len += codes[i].length() * probs[i];
    }
    cout << "Expected length of symbols: " << total_exp_len << "\n";
}
int main(){

    int D_ary;
    int Num_symbols;
    vector <float> probs;
    vector <float> cdf;
    vector <int> lengths;
    vector <string> codes;

    cout << "Enter D-ary value: ";
    cin >> D_ary;

    cout << "Enter number of symbols: ";
    cin >> Num_symbols;

    for (int i = 0; i < Num_symbols; i++) {
        float value;
        cin >> value;

        probs.push_back(value);
    }

    sort(probs.begin(), probs.end(), greater<int>());

    for (int i = 0; i<probs.size(); i++){
        if (i==0) cdf.push_back(0.0);
        else cdf.push_back(cdf[i-1] + probs[i-1]);
    }


    ComputeLengths(lengths, probs);

    codes = ShannonCode(cdf, lengths, D_ary);

    for (int i = 0; i<codes.size(); i++){
        cout << codes[i]<< " " << probs[i] << "\n";
    }

    ExpectedLength(codes, probs);
    return 0;
}