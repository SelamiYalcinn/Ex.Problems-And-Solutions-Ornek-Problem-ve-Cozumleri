//=== Sample Problem ===//
/*
	Coderbyte coding challenge: Arith Geo II
	Using the C++ language, have the function ArithGeoII(arr) take the array of
	numbers stored in arr and return the string "Arithmetic" if the sequence follows
	an arithmetic pattern or return "Geometric" if it follows a geometric pattern.
	If the sequence doesn't follow either pattern return -1.
	An arithmetic sequence is one where the difference between each of the numbers
	is consistent, where as in a geometric sequence, each term after the first is
	multiplied by some constant or common ratio. Arithmetic example: [2, 4, 6, 8]
	and Geometric example: [2, 6, 18, 54]. Negative numbers may be entered as
	parameters, 0 will not be entered, and no array will contain all the same
	elements.
	Sample test cases:
	Input:  5,10,15
	Output: "Arithmetic"
	Input:  2,4,16,24
	Output: "-1"
  
*/
//=== Örnek Problem ===//
/*
	Coderbyte coding challenge: Arith Geo II
  Bu örnekte verilen bir dizi tam sayı türündeki elemanın, aritmetik veya geometrik olarak
  sıralanıp sıralanmadığını test ediniz.
  Aritmetik dizi örneği : [2, 4, 6, 8]
  Geometrik dizi örneği : [2, 6, 18, 54]
  '0' değeri girdilerde bulunmayacak ve elemanların tamamı aynı olmayacak.
	Test Denemeleri:
	Girdi:  5,10,15
	Çıktı: "Arithmetic"
	Girdi:  2,4,16,24
	Çıktı: "-1"
  Girdi:  "1","3,","9"
	Çıktı: "Geometric"
  
*/

//=== KOD ===//
#define sizeAr(a) sizeof(a)/sizeof(*a)
#include<iostream>
#include<string>
#include<vector>

template<typename T>
class ResClas
{
private:
	T m_Contain{};
public:
	ResClas(const T& ivec) :m_Contain(ivec) {}
	//Initialize the Container...
	ResClas(size_t range, const std::string str[]) {
		for (size_t i = 0; i < range; i++)
			m_Contain.push_back(std::stoi(str[i]));
	}
	//Control to container
	void PrintRange() {
		auto iter = m_Contain.begin();
		while (iter != m_Contain.end())
			std::cout << *iter++ << ' ';

	}
	//Control Arithmetic ?
	bool CheckArith() {
		auto dif = std::abs(*std::next(m_Contain.begin()) - *m_Contain.begin());
		auto cls = [dif](const int& i1, const int& i2) {
			auto tmp = std::abs(i2 - i1);
			return dif == tmp;
		};
		int cnt = 0;
		for (size_t i = 0; i < m_Contain.size() - 1; i++)
		{
			auto stat = cls(m_Contain[i], m_Contain[i + 1]);
			if (stat)
				++cnt;
		}
		return cnt == m_Contain.size() - 1 ? true : false;
	}
	//Control Geo ?
	bool CheckGeo() {
		auto dif = std::abs(*std::next(m_Contain.begin()) / *m_Contain.begin());
		auto cls = [dif](const int& i1, const int& i2) {
			auto tmp = std::abs(i2 / i1);
			return dif == tmp;
		};
		int cnt = 0;
		for (size_t i = 0; i < m_Contain.size() - 1; i++)
		{
			auto stat = cls(m_Contain[i], m_Contain[i + 1]);
			if (stat)
				++cnt;
		}
		return cnt == m_Contain.size() - 1 ? true : false;
	}
};

std::string ResOfProblem(size_t range, const std::string str[]) {
	/*
	If you want to take a int vector ar, you can use the below code and you can 
	call member functions with reference to the example.
	(vecto<int> açılımı olarak bir dizi almak isterseniz aşağıdaki bloğu aktif ederek sınıfın 
	fonksiyonlarını, aşağıda verilen örnekteki gibi çağırınız...)
	std::vector<int> ivec{ 1,2,3,4,5 };
	ResClas<std::vector<int>> rc{ ivec};
	*/
	ResClas <std::vector<int>> rc{ range,str };
	auto stat1 = rc.CheckArith();
	auto stat2 = rc.CheckGeo();
	if (stat1 || stat2)
		return stat1 ? "Arithmetic" : "Geometric";
	else
		return "-1";
}
int main() {
	std::string str1[] = { "1","3","5" }, str2[]{ "3","9","27" };
	std::cout << "ResOfProblem1: " << ResOfProblem(sizeAr(str1), str1) << '\n';
	std::cout << "ResOfProblem2: " << ResOfProblem(sizeAr(str2), str2);
}
//=== Program Çıktısı ===//
/*
	ResOfProblem1: Arithmetic
	ResOfProblem2: Geometric
*/
//=======================//
