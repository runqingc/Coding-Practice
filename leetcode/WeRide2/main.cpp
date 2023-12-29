#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> predictAnswer(vector<int>& stockData, vector<int>& queries){

    vector<int> ret;
    if(stockData.empty()){
        ret = vector<int>(queries.size(), -1);
        return ret;
    }
    stack<int> s;
    // next right element index smaller than i-th element
    vector<int> right_small(stockData.size(), -1);
    for(int i=0; i<stockData.size(); ++i){
        if(s.empty() || stockData[s.top()]<=stockData[i]){
            s.push(i);
            continue;
        }
        while(!s.empty() && stockData[s.top()]>stockData[i]){
            right_small[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }
    vector<int> left_samll(stockData.size(), -1);
    for(int i=stockData.size()-1; i>=0; --i){
        if(s.empty() || stockData[s.top()]<=stockData[i]){
            s.push(i);
        }
        while(!s.empty() && stockData[s.top()]>stockData[i]){
            left_samll[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for(auto query: queries){
        --query;
        // no result, or result valid only on oneside
        if(left_samll[query]==-1 && right_small[query]==-1){
            ret.push_back(-1);
        } else if(left_samll[query]==-1){
            ret.push_back(right_small[query]+1);
        }else if(right_small[query]==-1){
            ret.push_back(left_samll[query]+1);
        }
        // left closer, or equally closer
        else if(query-left_samll[query]<=right_small[query]-query){
            ret.push_back(left_samll[query]+1);
        }
        // right closer
        else{
            ret.push_back(right_small[query]+1);
        }

    }


    return ret;

}



int main() {
    vector<int> stockData = {
            89214,
            26671,
            75144,
            32445,
            13656,
            66289,
            21951,
            10265,
            59857,
            59133,
            63227,
            86121,
            37411,
            54628,
            25859,
            43510,
            63756,
            54763,
            30852,
            53243,
            76238,
            96885,
            33074,
            17745,
            81814,
            43436,
            79172,
            92819,
            30001,
            68442,
            54021,
            35566,
            95113,
            29164,
            84362,
            25120,
            11804,
            6313,
            51736,
            71661,
            81797,
            14962,
            57781,
            35560,
            85941,
            99991,
            95421,
            66048,
            54754,
            26272,
            35642,
            47343,
            39508,
            85068,
            65087,
            21321,
            28503,
            60611,
            30491,
            58503,
            29052,
            84512,
            94069,
            40516,
            13675,
            78430,
            65635,
            25479,
            1094,
            17370,
            13491,
            99243,
            48683,
            71271,
            34802,
            34624,
            87613,
            46574,
            671,
            42366,
            89197,
            36313,
            89708,
            28704,
            21380,
            54795,
            66376,
            49882,
            15405,
            96867,
            24737,
            60808,
            81378,
            35157,
            1324,
            11404,
            29938,
            66958,
            53234,
            47384};
    vector<int> queries = {80,
                           24,
                           26,
                           62,
                           46,
                           79,
                           85,
                           59,
                           52,
                           8,
                           76,
                           48,
                           72,
                           84,
                           3,
                           3,
                           30,
                           30,
                           36,
                           86,
                           96,
                           72,
                           93,
                           25,
                           28,
                           68,
                           81,
                           18,
                           78,
                           14,
                           1,
                           57,
                           90,
                           26,
                           18,
                           87,
                           56,
                           55,
                           97,
                           59,
                           62,
                           73,
                           58,
                           85,
                           8,
                           60,
                           87,
                           89,
                           89,
                           22};
    vector<int> ans = predictAnswer(stockData, queries);

    vector<int> correct = {
            79,
            37,
            24,
            61,
            45,
            -1,
            89,
            57,
            51,
            38,
            79,
            49,
            71,
            85,
            2,
            2,
            29,
            29,
            37,
            85,
            95,
            71,
            92,
            24,
            27,
            69,
            80,
            19,
            79,
            13,
            2,
            56,
            89,
            24,
            19,
            86,
            65,
            56,
            96,
            57,
            61,
            71,
            57,
            89,
            38,
            59,
            86,
            95,
            95,
            21};
    for (int i = 0; i < ans.size(); ++i) {
    if (ans[i] != correct[i]) {
        cout << "ERROR ";
    }
    cout << queries[i] << " " << ans[i] << " " << correct[i] << endl;
}
    return 0;
}
