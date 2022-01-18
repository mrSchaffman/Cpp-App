#pragma once
#include<ostream>
#include<string>
#include<vector>
class DVD
{

	friend std::ostream &operator<<(const std::ostream& oStream, const DVD& dvd);

private:
	//the title of the movie
	std::string m_dvdTitle;
	//first star in the movie
	std::string m_movieStar1;
	//second star in the movie
	std::string m_movieStar2;
	//the producer of the movie
	std::string m_movieProducer;
	//the producer cooperator of the movie
	std::string m_productionCompagnie;
	//the director of the movie
	std::string m_movieDirector;
	// nomber of this dvd in stock
	size_t m_numberInStock;
	//dvd info
	std::vector<std::string> m_dvdInfos;

public:
	void setDVDInfo(std::string& title,
		std::string& star1,
		std::string& star2,
		std::string& producer,
		std::string& director,
		std::string& productionCo,
		int setInStock);

	constexpr size_t getNumOfCopiesInStock()const { return m_numberInStock; }
	void setNumOfCopiesInStock(size_t num) { m_numberInStock = num; }
	void checkOut();
	void chechIn();
	void updateNumOfCopiesInStock(size_t num);
	std::string getTitle()const { return m_dvdTitle; }
	std::string getStar1()const { return m_movieStar1; }
	std::string getStar2()const { return m_movieStar2; }
	std::string getProducer()const { return m_movieProducer; }
	std::string getProductionCompagnie()const { return m_productionCompagnie; }
	std::string getDirector()const { return m_movieDirector; }

	bool chechTitle(std::string& title) { return m_dvdTitle == title; }
	std::vector<std::string> getInfos() const { return m_dvdInfos; }

	DVD(std::string title = "",
		std::string star1 = "",
		std::string star2 = "",
		std::string producer = "",
		std::string director = "",
		std::string productionCom = "",
		size_t setInStock = 0);

	bool operator==(const DVD& otherDVD)const;
	bool operator!=(const DVD& otherDVD)const;
	bool operator<=(const DVD& otherDVD)const;
	bool operator>=(const DVD& otherDVD)const;
	bool operator<(const DVD& otherDVD)const;
	bool operator>(const DVD& otherDVD)const;

};

