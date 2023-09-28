#include <iostream>
#include <string>
#include <vector>
using  namespace std;

#define hkd 0.1275
#define rmb 0.1372
#define usd 1
#define CRQ 0;
#define SSC 1;
#define JMH 2;
#define NUM 3

const vector<string> roommate_list{"CRQ", "SSC", "JMH"};

class payment_item{
public:
    string name;
    double amt;
    float currency;
    int payer;
    vector<int> split;
public:
    payment_item(string n, float c, double a, int pay, vector<int>& sp):name(n), currency(c), amt(a), payer(pay),split(sp) {};
};

class payment_table{
public:
    vector<payment_item> pay_list;
    void cal_payment();
};

// result[i][j] the sum j should give to i
void payment_table::cal_payment() {
    vector<vector<double>> result(NUM, vector<double>(NUM, 0));
    for(auto& i: pay_list){
        for(auto& j: i.split){
            result[i.payer][j] += i.amt*i.currency/(double)i.split.size();
        }
    }
    for(int i=0; i<result.size(); ++i){
        for(int j=0; j<i; ++j){
            if(result[i][j]<result[j][i]){
                cout << roommate_list[j] << " give " << roommate_list[i] << result[j][i]-result[i][j] << "usd." << endl;
            }else if(result[i][j]<result[j][i]){
                cout << roommate_list[i] << "give" << roommate_list[j] << result[i][j]-result[j][i] << "usd." << endl;
            }
        }
    }
}



int main() {

    payment_table paymentTable;
    string n = "air";
    double amt = 10374;
    float c = hkd;
    int payer = SSC;
    vector<int> split(1, 0);
    payment_item p1(n, c, amt, payer, split);
    paymentTable.pay_list.push_back(p1);
    paymentTable.cal_payment();


    return 0;
}
