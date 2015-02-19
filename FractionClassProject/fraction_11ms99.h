
using namespace std;

class FractionException {
public:
	FileException(const string&);
	string& what();
private:
	string message;
};

class Fraction {

};