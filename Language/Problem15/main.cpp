#include <gsl/gsl>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class CIPAddress
{
public:
    CIPAddress(){}
    ~CIPAddress(){}
    
    void setIPaddress(string ip) {
        
        regex pattern("(((\\d{1,2})|(1\\d{2})|(2[0-4]\\d)|(25[0-5]))\\.){3}((\\d{1,2})|(1\\d{2})|(2[0-4]\\d)|(25[0-25]))");
        smatch match;
        regex_search(ip, match, pattern);
        cout << match.str(0) << endl;

        m_ip_num = match.str(0);
    }

    string getIPaddress() {
        if (m_ip_num.empty()) {
            return "null";
        } else {
            return move(m_ip_num);
        }
    }

private:
    string m_ip_num;
};

int main(int argc, char* argv[])
{
    string addr;
    CIPAddress cip;
    cout << "insert ip address : " << endl;
    cin >> addr;

    cip.setIPaddress(addr);
    cout << cip.getIPaddress() << endl;

    return 0;
}
