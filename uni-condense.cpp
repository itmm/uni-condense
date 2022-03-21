#include <iostream>
#include <sstream>
#include <set>

int main() {
	std::string line;
	std::string last_addr_start, last_addr_end, last_cat;
	std::set<std::string> initial_cats { "Lu", "Ll", "Lt", "Lm", "Lo", "Mn", "Nl", "No", "Pd", "Pc", "Po", "Sc", "Sm", "Sk", "So", "Co" };
	std::set<std::string> rest_cats { "Nd", "Mc", "Me" };
	while (std::getline(std::cin, line)) {
		std::istringstream in { line };
		std::string addr, cat;
		if (! std::getline(in, addr, '\t')) {
		       	std::cerr << "no addr in [" << line << "]\n"; break;
	       	}
		if (! std::getline(in, cat, '\t')) {
			std::cerr << "no category in [" << line << "]\n"; break;
		}
		if (initial_cats.find(cat) != initial_cats.end()) {
			cat = "ini";
		} else if (rest_cats.find(cat) != rest_cats.end()) {
			cat = "end";
		} else {
			cat = "unused";
		}
		if (cat == last_cat) {
			last_addr_end = addr;
		} else {
			if (! last_cat.empty()) {
				std::cout << last_addr_start << '\t' << last_addr_end << '\t' << last_cat << '\n';
			}
			last_cat = cat;
			last_addr_start = last_addr_end = addr;
		}
	}
	if (! last_cat.empty()) {
		std::cout << last_addr_start << '\t' << last_addr_end << '\t' << last_cat << '\n';
	}
}
