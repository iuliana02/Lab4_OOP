#include <string>
using namespace std;

class Medikament
{
private:
	string name;
	double konzentration;
	int menge;
	double preis;

public:
	Medikament();
	Medikament(string name, double konzentration, int menge, double preis);
	
	string get_name() const;
	double get_konz() const;
	int get_menge() const;
	double get_preis() const;
	void set_name (string name);
	void set_konz(double k);
	void set_menge(int menge);
	void set_preis (int preis);

	~Medikament();
};