#include <string>
using namespace std;

class Med
{
private:
	string name;
	double konzentration;
	int menge;
	double preis;

public:
	Med();
	Med(string name, double konzentration, int menge, double preis);
	
	string get_name() const;
	double konzentration() const;
	int get_menge() const;
	double get_preis() const;
	void set_name (string name);
	void konzentration_s(double k);
	void set_menge(int menge);
	void set_preis (int preis);

	~Med();
};