#include "DVD.h"

void DVD::setDVDInfo(std::string & title, std::string & star1, std::string & star2, std::string & producer, std::string & director, std::string & productionCo, int setInStock)
{
	// clear the vector.
	m_dvdInfos.clear();

	m_dvdTitle = title;
	m_movieStar1 = star1;
	m_movieStar2 = star2;
	m_movieProducer = producer;
	m_productionCompagnie = productionCo;
	m_movieDirector = director;
	m_numberInStock = setInStock;

	m_dvdInfos.push_back(m_dvdTitle);
	m_dvdInfos.push_back(m_movieStar1);
	m_dvdInfos.push_back(m_movieStar2);
	m_dvdInfos.push_back(m_movieProducer);
	m_dvdInfos.push_back(m_productionCompagnie);
	m_dvdInfos.push_back(m_movieDirector);
}

void DVD::checkOut()
{
	if (getNumOfCopiesInStock() > 0)
	{
		m_numberInStock--;
	}
	else
	{
		std::out_of_range("Currently Out of stock!");
	}

}

void DVD::chechIn()
{
	m_numberInStock++;
}

void DVD::updateNumOfCopiesInStock(size_t num)
{
	m_numberInStock = num;
}

DVD::DVD(std::string title, std::string star1, std::string star2, std::string producer, std::string director, std::string productionCom, size_t setInStock)
{
	setDVDInfo(title, star1, star2, producer, director, productionCom, setInStock);
}

bool DVD::operator==(const DVD & otherDVD) const
{
	return m_dvdTitle == otherDVD.getTitle();
}

bool DVD::operator!=(const DVD & otherDVD) const
{
	return m_dvdTitle != otherDVD.getTitle();
}

bool DVD::operator<=(const DVD & otherDVD) const
{
	return m_dvdTitle <= otherDVD.getTitle();
}

bool DVD::operator>=(const DVD & otherDVD) const
{
	return m_dvdTitle >= otherDVD.getTitle();
}

bool DVD::operator<(const DVD & otherDVD) const
{
	return m_dvdTitle < otherDVD.getTitle();
}

bool DVD::operator>(const DVD & otherDVD) const
{
	return m_dvdTitle > otherDVD.getTitle();
}

std::ostream & operator<<(std::ostream & oStream, const DVD & dvd)
{
	oStream << std::endl;
	oStream << "Title:" << std::endl;
	oStream << "Stars: " << dvd.getStar1() << " - " << dvd.getStar2() << std::endl;
	oStream << "Producer: " << dvd.getProducer() << std::endl;
	oStream << "Production Compagny: " << dvd.getProductionCompagnie() << std::endl;
	oStream << "Director: " << dvd.getDirector() << std::endl;
	oStream << "Total in Stock: " << dvd.getNumOfCopiesInStock() << std::endl;
	oStream << "_____________________________________________________" << std::endl;

	return oStream;
}
